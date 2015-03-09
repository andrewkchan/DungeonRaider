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
	glm::vec4 permAcceleration_; //the acceleration that is constantly exerted on the actor
	glm::vec4 currAcceleration_; //the sum of all accelerations (not including the permanent acceleration) currently exerted on the actor
	float absMaxSpeed_; //the absolute value of the maximum speed of the actor, <0.0 if infinite

public:
	PhysicsComponent(float absMaxSpeed = -1.0f, float accelerationZ = 0.0f) : 
		absMaxSpeed_(absMaxSpeed),
		velocity_(0.0f, 0.0f, 0.0f, 0.0f),
		permAcceleration_(0.0f, 0.0f, accelerationZ, 0.0f)
	{}
	PhysicsComponent(float absMaxSpeed, const glm::vec4& acceleration = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) :
		absMaxSpeed_(absMaxSpeed),
		velocity_(0.0f, 0.0f, 0.0f, 0.0f),
		permAcceleration_(acceleration)
	{}
	PhysicsComponent(const PhysicsComponent& src);
	virtual ~PhysicsComponent(){}

	//get the magnitude of the velocity
	float getSpeed() { return glm::length(velocity_); }
	//get the magnitude squared of the velocity (should be faster)
	float getSpeedSquared() { return glm::length2(velocity_); }
	//get the magnitude of the acceleration
	float getAccelMagnitude() { return glm::length(permAcceleration_ + currAcceleration_); }
	//get the absolute value of the maximum possible speed of the actor, <0.0 if infinite
	float getAbsMaxSpeed() { return absMaxSpeed_; }

	//get the horizontal velocity in the x-direction of the actor
	float getVelocityX() { return velocity_.x; }
	//get the horizontal velocity in the y-direction of the actor
	float getVelocityY() { return velocity_.y; }
	//get the vertical velocity of the actor
	float getVelocityZ() { return velocity_.z; }
	//get the sum horizontal acceleration in the x-direction of the actor
	float getAccelerationX() { return (permAcceleration_ + currAcceleration_).x; }
	//get the sum horizontal acceleration in the y-direction of the actor
	float getAccelerationY() { return (permAcceleration_ + currAcceleration_).y; }
	//get the sum vertical acceleration of the actor
	float getAccelerationZ() { return (permAcceleration_ + currAcceleration_).z; }

	void transformVelocity(const glm::mat4& transform) { velocity_ = transform * velocity_; }
	void setVelocity(float x, float y, float z) { velocity_ = glm::vec4(x, y, z, 0.0f); }
	//transform the acceleration that is constantly exerted on the actor
	void transformPermanentAcceleration(const glm::mat4& transform) { permAcceleration_ = transform * permAcceleration_; }
	//set the acceleration that is constantly exerted on the actor
	void setPermanentAcceleration(float x, float y, float z) { permAcceleration_ = glm::vec4(x, y, z, 0.0f); }
	void setAbsMaxSpeed(float absMaxSpeed) { absMaxSpeed_ = absMaxSpeed; }

	//exert a temporary acceleration on the actor
	void exertAcceleration(float x, float y, float z) { currAcceleration_ += glm::vec4(x, y, z, 0.0f); }

	virtual void update(float frameTime, Actor& actor);

	PhysicsComponent& operator=(const PhysicsComponent& src);
};







#endif