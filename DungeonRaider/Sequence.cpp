#include "Sequence.h"

int Sequence::getCurrentFrameIndex(float timeSinceLastFrame)
{
	if (numFrames_ == 0)
		return -1;
	if (duration_ == 0.0f) //avoid divide-by-zero!
		return 0;
	currentFrame_ += static_cast<unsigned int>((timeSinceLastFrame / duration_) * numFrames_) % numFrames_;
	currentFrame_ %= numFrames_;
	return currentFrame_;
}

Sequence::~Sequence(){}