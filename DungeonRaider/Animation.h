#ifndef ANIMATION_H
#define ANIMATION_H


#include "Sprite.h"

class Animation
{
	/*
	Class Animation

	This class is a sequence of sprites.
	
	
	
	
	*/
private:
	Sprite* _sprites; //the array of sprites
	int _numSprites; //the number of sprites in the array
	double _animTime; //the time interval for the animation to play
public:
	Animation(Sprite* input_sprites = 0, int input_numSprites = 0, double input_animTime = 0.0)
	{
		_numSprites = input_numSprites;
		_animTime = input_animTime;
		if (input_sprites && input_numSprites) //if an initial array of sprites is provided
		{
			//copy the provided array into the member array of sprites
			
			_sprites = new Sprite[_numSprites];
			for (int i = 0; i < _numSprites; i++)
			{
				_sprites[i] = input_sprites[i];
			}
		}
		else
		{
			_sprites = 0;
		}
	}
	~Animation()
	{
		delete[] _sprites;
		_sprites = 0;
	}
	SDL_Texture* getCurrentFrame(double timeSinceStart); //get the current frame of the animation based on time passed since animation started playing


};




#endif