#ifndef ALIGNED16_H
#define ALIGNED16_H

#include <cstdint>
#include <stdlib.h> //for malloc,free
#include <exception> //for bad_alloc

/*
aligned_malloc, a portable version of MSVC's _aligned_malloc that can allocate chunks of memory to boundaries
other than the 8-byte boundaries that malloc guarantees.
NOTE: size_t alignment must be power of 2 (1,2,4,8,16...)
*/
inline void* aligned_malloc(size_t size, size_t alignment) {
	uintptr_t unusedChunk = (uintptr_t)malloc( size + (--alignment) + sizeof(uintptr_t) );
	if (!unusedChunk)
		return 0;
	uintptr_t chunkToUse = unusedChunk + sizeof(uintptr_t);
	uintptr_t offsetChunk = (chunkToUse + alignment) & ~(uintptr_t)alignment; //offset so that it's aligned

	((uintptr_t*)offsetChunk)[-1] = unusedChunk; //preceding byte becomes the start address of total unused space
	return (void*)offsetChunk;
}

/*
aligned_free, a version of free() that should -ONLY- be used with memory allocated with aligned_malloc.
Using this with normally allocated memory will cause an (uncaught) access violation.
*/
inline void aligned_free(void* p) {
	if (!p) 
		return;
	free((void*)(((uintptr_t*)p)[-1]));
}

/*
A base class for all classes with members that need to be aligned on 16-byte blocks.
*/
class Aligned16
{
public:
	void* operator new(size_t size)
	{
		void* output = aligned_malloc(size, 16);
		if (!output)
			throw(std::bad_alloc());
		return output;
	}
	void operator delete(void* p)
	{
		aligned_free(p);
	}
	/*
	void* operator new[](size_t size)
	{
		void* output;
		if (!output)
			throw(std::bad_alloc());
		return output;
	}
	void operator delete[](void* p)
	{

	}*/
};

#endif