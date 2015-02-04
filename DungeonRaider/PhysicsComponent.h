#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "Component.h"
#include "TransformComponent.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>

//fwd declarations
class Actor;

/*
class PhysicsComponent

This component allows an actor to be acted on by physical forces, and is required to make the actor 
move in the "right" way. In brief, any actor with a PhysicsComponent will have its TransformComponent
acted on by the game's physics engine, if enabled.

Note that a ColliderComponent is still required for collisions.
*/
class PhysicsComponent : public Component
{
private:
	glm::vec4 velocity_; //the current velocity the actor is moving at
	glm::vec4 acceleration_; //the current acceleration
	float absMaxSpeed_; //the absolute value of the maximum speed of the actor, <0.0 if infinite

public:
	PhysicsComponent(float absMaxSpeed = -1.0f, float accelerationZ = 0.0f) : 
		absMaxSpeed_(absMaxSpeed),
		velocity_(0.0f, 0.0f, 0.0f, 0.0f),
		acceleration_(0.0f, 0.0f, accelerationZ, 0.0f)
	{}
	PhysicsComponent(float absMaxSpeed, glm::vec4 acceleration = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) :
		absMaxSpeed_(absMaxSpeed),
		velocity_(0.0f, 0.0f, 0.0f, 0.0f),
		acceleration_(acceleration)
	{}
	PhysicsComponent(const PhysicsComponent& src);
	virtual ~PhysicsComponent(){}

	//get the magnitude of the velocity
	float getSpeed() { return glm::length(velocity_); }
	//get the magnitude squared of the velocity (should be faster)
	float getSpeedSquared() { return glm::length2(velocity_); }
	//get the magnitude of the acceleration
	float getAccelMagnitude() { return glm::length(acceleration_); }
	//get the absolute value of the maximum possible speed of the actor, <0.0 if infinite
	float getAbsMaxSpeed() { return absMaxSpeed_; }

	//get the horizontal velocity in the x-direction of the actor
	float getVelocityX() { return velocity_.x; }
	//get the horizontal velocity in the y-direction of the actor
	float getVelocityY() { return velocity_.y; }
	//get the vertical velocity of the actor
	float getVelocityZ() { return velocity_.z; }
	//get the horizontal acceleration in the x-direction of the actor
	float getAccelerationX() { return acceleration_.x; }
	//get the horizontal acceleration in the y-direction of the actor
	float getAccelerationY() { return acceleration_.y; }
	//get the vertical acceleration of the actor
	float getAccelerationZ() { return acceleration_.z; }

	void transformVelocity(glm::mat4 transform) { velocity_ = transform * velocity_; }
	void setVelocity(float x, float y, float z) { velocity_ = glm::vec4(x, y, z, 0.0f); }
	void transformAcceleration(glm::mat4 transform) { acceleration_ = transform * acceleration_; }
	void setAcceleration(float x, float y, float z) { acceleration_ = glm::vec4(x, y, z, 0.0f); }
	void setAbsMaxSpeed(float absMaxSpeed) { absMaxSpeed_ = absMaxSpeed; }

	virtual void update(float frameTime, Actor& actor);

	PhysicsComponent& operator=(const PhysicsComponent& src);
};







#endif