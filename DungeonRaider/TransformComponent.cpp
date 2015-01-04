#include "TransformComponent.h"

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