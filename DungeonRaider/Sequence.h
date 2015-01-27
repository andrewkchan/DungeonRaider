#ifndef SEQUENCE_H
#define SEQUENCE_H


/*
class Sequence
* Brief: An abstract base class for animations.
*/
class Sequence
{
	/*
	class Sequence

	A sequence is a collection of "frames," or states of something that cycle one-at-a-time at a constant
	rate on a given time period. For example: a sequence of images that represent an object's motion (an Animation),
	or a sequence of speeds that an object travels at (a MotionSequence).

	The Sequence class is an abstract base class. Its only members describe its time period, number of frames, and current frame.
	*/
protected:
	Sequence() : duration_(0.0f), numFrames_(0), currentFrame_(0) {}

	float duration_;
	unsigned int numFrames_; 
	unsigned int currentFrame_;
public:
	virtual ~Sequence() = 0; //implemented out of class

	//returns the index of the currentframe based on time since last frame, -1 if the sequence does not contain any frames
	int getCurrentFrameIndex(float timeSinceLastFrame);
};







#endif