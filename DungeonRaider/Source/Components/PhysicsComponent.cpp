#include "Components\PhysicsComponent.h"
#include "Entities\Actor.h"

PhysicsComponent::PhysicsComponent(const PhysicsComponent& src)
{
	velocity_ = src.velocity_;
	permAcceleration_ = src.permAcceleration_;
	absMaxSpeed_ = src.absMaxSpeed_;
}

void PhysicsComponent::update(float frameTime, Actor& actor)
{
	currAcceleration_ += permAcceleration_;
	velocity_ += frameTime * currAcceleration_;
	if (absMaxSpeed_ > 0.0f && glm::length(velocity_) > absMaxSpeed_)
	{
		velocity_ = velocity_ * (absMaxSpeed_ / glm::length(velocity_));
	}
	actor.getTransform().translatePosition(frameTime * velocity_);

	currAcceleration_ = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
}