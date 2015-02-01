#include "TransformComponent.h"

void TransformComponent::update(float frameTime, Actor& actor)
{
	//TODO: do this!
}

TransformComponent& TransformComponent::operator=(const TransformComponent& component)
{
	//check for self-assignment
	if (this == &component)
	{
		return *this;
	}

	pos_ = component.pos_;
	velocity_ = component.velocity_;
	absMaxSpeed_ = component.absMaxSpeed_;

	return *this;
}