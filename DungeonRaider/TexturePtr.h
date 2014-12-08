#ifndef TEXTUREPTR_H
#define TEXTUREPTR_H

#include <SDL.h>
#include <iostream>


class TexturePtr
{
	/*
	Class TexturePtr


	This class allows safe handling and copying of SDL_Texture structs. 

	We want a Sprite class that only holds a texture, and not a SDL_renderer or SDL_Surface pointer. 
	We also need the Sprite class to support safe copying using the assignment operator, so that we can
	easily copy animations and such. However, since SDL_Textures are actually stored
	in VRAM, SDL_CreateTexture() only returns a pointer to the SDL_Texture it creates. Thus if we want to copy
	a Sprite object, we can only copy the memory addresses of the SDL_Textures, which is highly unsafe, because what
	if we accidentally delete the texture that another sprite is using? 

	TexturePtr will allow us to share a texture pointer amongst Sprite objects that will be deletion-safe.
	TexturePtr does reference-counting; everytime a TexturePtr is copy-constructed or assigned to another,
	the count of Sprites referring to that TexturePtr increases by 1.
	If a Sprite holding a TexturePtr is destroyed, its destructor will 
	call TexturePtr's destructor, which will only delete the actual SDL_Texture if there are no other Sprites
	holding the same TexturePtr. 
	
	
	*/
private:
	SDL_Texture* _texture;
	unsigned int* _count;
public:
	TexturePtr() //default constructor for arrays only
	{
		_texture = 0;
		_count = 0;
	}
	TexturePtr(SDL_Renderer* renderer, SDL_Surface* surface)
	{
		_texture = SDL_CreateTextureFromSurface(renderer, surface);
		_count = new unsigned int(1);
		if (_texture == 0)
		{
			std::cout << "SDL_CreateTextureFromSurface error:" << SDL_GetError() << std::endl;
		}
	}
	TexturePtr(const TexturePtr& sourceTexturePtr) //copy constructor
	{
		_texture = sourceTexturePtr._texture;
		++*(_count);
	}
	~TexturePtr() //destructor
	{
		--*(_count);
		if (*(_count) == 0) //if, after deleting this TexturePtr, there are no more references to the texture
		{
			SDL_DestroyTexture(_texture);
			delete _count;
		}
		_texture = 0;
		_count = 0;
	}

	SDL_Texture* get() { return _texture; }



};






#endif