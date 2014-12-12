#ifndef ANIMATION_H
#define ANIMATION_H


#include <SFML/Graphics.hpp>

class Animation
{
	/*
	Class Animation

	This class is a sequence of sprites. Each CharacterStateMachine contains an Animation object for each CharacterState.
	
	When the game wants to draw an Character, it calls window.draw() on the Character in the scene graph.
	The Character looks up its state in its CharacterStateMachine, which returns the CharacterState, and the CharacterState then
	returns an Animation object reference, which finally returns the current frame of the animation to draw
	using getCurrentFrame(). The Character is then drawn according to its own sf::Transform coordinates.
	
	
	*/
private:
	sf::Sprite* _sprites; //an array of sprites
	int _numSprites; //the number of sprites in the array
	double _animTime; //the time interval for the animation to play
public:
	Animation(sf::Sprite* input_sprites = 0, int input_numSprites = 0, double input_animTime = 0.0)
	{
		_numSprites = input_numSprites;
		_animTime = input_animTime;
		if (input_sprites && input_numSprites) //if an initial array of sprites is provided
		{
			//copy the provided array into the member array of sprites
			
			_sprites = new sf::Sprite[_numSprites];
			for (int i = 0; i < _numSprites; i++)
			{
				_sprites[i].setTexture(*(input_sprites[i].getTexture()));
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
	sf::Sprite& getCurrentFrame(double timeSinceStart) const; //get the current frame of the animation based on time passed since animation started playing


};




#endif