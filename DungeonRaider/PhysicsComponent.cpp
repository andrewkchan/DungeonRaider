#include "PhysicsComponent.h"
#include "Actor.h"

PhysicsComponent::PhysicsComponent(const PhysicsComponent& src)
{
	velocity_ = src.velocity_;
	acceleration_ = src.acceleration_;
	absMaxSpeed_ = src.absMaxSpeed_;
}

void PhysicsComponent::update(float frameTime, Actor& actor)
{
	velocity_ += frameTime * acceleration_;
	if (glm::length(velocity_) > absMaxSpeed_)
	{
		velocity_ = velocity_ * (absMaxSpeed_ / glm::length(velocity_));
	}
	actor.getTransform().translatePosition(frameTime * velocity_);
}