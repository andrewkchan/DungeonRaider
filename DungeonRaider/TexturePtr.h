#ifndef TEXTUREPTR_H
#define TEXTUREPTR_H

#include <iostream>
#include <SFML/Graphics.hpp>

class TexturePtr
{
	/*
	Class TexturePtr


	This class allows safe handling and copying of textures. 

	TexturePtr will allow us to share a texture pointer amongst Sprite objects that will be deletion-safe.
	TexturePtr does reference-counting; everytime a TexturePtr is copy-constructed or assigned to another,
	the count of Sprites referring to that TexturePtr increases by 1.
	If a Sprite holding a TexturePtr is destroyed, its destructor will 
	call TexturePtr's destructor, which will only delete the actual texture in VRAM if there are no other Sprites
	holding the same TexturePtr. 
	
	
	*/
private:
	sf::Texture* _texture; //a pointer to the texture in VRAM being managed
	int* _numReferences; //the number of references to this TexturePtr
public:
	TexturePtr(std::string fileName, sf::IntRect& area = sf::IntRect())
	{
		_texture = new sf::Texture;
		if(!_texture->loadFromFile(fileName, area))
		{
			//todo: error catching
			std::cout << "Error loading sf::Texture from file path:" << fileName.c_str() << std::endl;
			_texture->create(100, 100); //create an empty placeholder texture
		}
		_numReferences = new int(1);
	}
	TexturePtr(const TexturePtr& sourceTexturePtr) //copy constructor
	{
		_texture = sourceTexturePtr._texture; //point this texture pointer at the source's texture
		_numReferences = sourceTexturePtr._numReferences; //point this reference counter to the source's reference counter
		++(*_numReferences); //increment the shared reference counter (which is located on heap)
	}
	~TexturePtr() //destructor
	{
		if ((*_numReferences) <= 0) //if there are no more references to the shared texture
		{
			delete _texture; //delete the texture from VRAM
			delete _numReferences; //delete _numReferences from the heap
		}
		//set both pointers to zero, just in case!
		_texture = 0;
		_numReferences = 0;
	}

	void operator=(const TexturePtr& sourceTexturePtr)
	{
		_texture = sourceTexturePtr._texture; //point this texture pointer at the source's texture
		_numReferences = sourceTexturePtr._numReferences; //point this reference counter to the source's reference counter
		++(*_numReferences); //increment the shared reference counter (which is located on heap)
	}
	sf::Texture& get() const
	{
		return *(_texture);
	}


};






#endif