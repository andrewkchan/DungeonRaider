#include "Actor.h"

void Actor::transformPos(glm::mat4 transform)
{
	physicalState.pos = transform * physicalState.pos; //note: order matters! transform first always
}
void Actor::transformVelocity(glm::mat4 transform)
{
	physicalState.velocity = transform * physicalState.velocity; //transform first always in matrix multiplication
}

void Actor::update(double frameTime)
{
	//todo: DO THIS!!!!!
}
Actor& Actor::operator=(const Actor& srcActor)
{
	//check for self-assignment
	if (this == &srcActor)
	{
		return *this;
	}

	physicalState = srcActor.physicalState;
	return *this;
}