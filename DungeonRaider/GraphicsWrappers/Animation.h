#ifndef ANIMATION_H
#define ANIMATION_H

#include "Sequence.h"
#include <vector>
#include <SFML/Graphics.hpp>

/*
class Animation
Brief: A sequence of sf::IntRect "frames" against which a given spritesheet should be rendered.
*/
class Animation : public Sequence
{
	/*
	Class Animation

	This class is a sequence containing a vector of sf::IntRect objects. When an entity is to be drawn,
	it refers to Animation.getCurrentFrame(), which returns the portion of its spritesheet which should be drawn.
	
	Animation objects are each intended to be used with a single spritesheet only.
	*/
private:
	std::vector<sf::IntRect> frameList_;
public:
	Animation(){}
	//single-frame animation constructor
	Animation(sf::IntRect rect) { frameList_.push_back(rect); }
	virtual ~Animation(){}

	//get the current frame of the animation based on time passed since animation started playing
	sf::IntRect getCurrentFrame(float timeSinceLastFrame); 
	//add a frame of animation
	void addFrame(sf::IntRect newFrame);
	void setDuration(float newDuration);
};




#endif