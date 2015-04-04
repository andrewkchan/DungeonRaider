#include "GraphicsWrappers\Animation.h"

// sf::IntRect Animation::getCurrentFrame(double timeSinceStart) const
//get the current frame of the animation based on time passed since animation started playing
// *note: float timeSinceLastFrame is the time, in seconds, passed since this function was last called
sf::IntRect Animation::getCurrentFrame(float timeSinceLastFrame)
{
	getCurrentFrameIndex(timeSinceLastFrame);
	if (currentFrame_ < 0)
		return sf::IntRect(); //return empty rectangle if no frames
	return frameList_[currentFrame_];
}
//add a frame of animation
void Animation::addFrame(sf::IntRect newFrame)
{
	frameList_.push_back(newFrame);
	numFrames_++;
}
//set the new duration of the animation
void Animation::setDuration(float newDuration)
{
	if (newDuration < 0)
		duration_ = -newDuration; //just in case!
	else
		duration_ = newDuration;
}