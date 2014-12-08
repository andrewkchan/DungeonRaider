#ifndef SPRITE_H
#define SPRITE_H

#include "TexturePtr.h"

class Sprite
{
private:
	TexturePtr _texture; //a smart pointer to an SDL_Texture*, handles deleting it n' stuff
public:
	Sprite(){} //default constructor
	Sprite(const Sprite& sourceSprite) //copy constructor
	{
		_texture = sourceSprite._texture;
	}
	~Sprite()
	{
		//destructor
	}
	//SDL_Texture* getTexture() { return _texture.get(); }

	void operator=(const Sprite& sourceSprite)
	{
		//check for self-assignment
		if (&sourceSprite == this)
		{
			return;
		}
		_texture = sourceSprite._texture;
	}
};





#endif