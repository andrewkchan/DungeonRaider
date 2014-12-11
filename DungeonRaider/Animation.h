#ifndef ANIMATION_H
#define ANIMATION_H


#include <SFML/Graphics.hpp>

class Animation
{
	/*
	Class Animation

	This class is a sequence of sprites. Each ActorStateMachine contains an Animation object for each ActorState.
	
	When the game wants to draw an Actor, it calls window.draw() on the actor in the scene graph.
	The actor looks up its state in its ActorStateMachine, which returns the ActorState, and the ActorState then
	returns an Animation object reference, which finally returns the current frame of the animation to draw
	using getCurrentFrame(). The actor is then drawn according to its own sf::Transform coordinates.
	
	
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