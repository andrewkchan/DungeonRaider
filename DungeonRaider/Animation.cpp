#include "Animation.h"

// sf::Sprite& Animation::getCurrentFrame(double timeSinceStart) const
// *brief: returns a reference to the sprite representing the current frame of the animation
// *note: double timeSinceStart is the time, in seconds, passed since the start of the animation
sf::Sprite& Animation::getCurrentFrame(double timeSinceStart) const
{
	int frameIndex = (static_cast<int>(timeSinceStart / _animTime) * _numSprites) % _numSprites;
	return _sprites[frameIndex];
}