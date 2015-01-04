#ifndef MOTIONCOMPONENT_H
#define MOTIONCOMPONENT_H

#define GLM_FORCE_PURE //this stops "Error C2719" alignment errors with GLM Matrices on 32-bit systems
						//the above error should be fixed by GLM 9.6.1

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>



class TransformComponent
{
	/*
	Class MotionComponent

	This component describes all positional and motional properties of an actor at any given time,
	for example: position, velocity, and direction.
	*/
private:
	glm::vec4 pos_;
	glm::vec4 velocity_;

	float absMaxSpeed_; //the absolute value of the maximum speed of the actor, -1.0 if infinite
public:
	TransformComponent(glm::vec4 pos = glm::vec4(0.0f,0.0f,0.0f,1.0f), 
		glm::vec4 velocity = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f), float absMaxSpeed = -1.0f) :
		pos_(pos), velocity_(velocity), absMaxSpeed_(absMaxSpeed)
	{} //default constructor
	TransformComponent(const TransformComponent& component)
	{
		pos_ = component.pos_;
		velocity_ = component.velocity_;
		absMaxSpeed_ = component.absMaxSpeed_;
	}
	
	glm::vec4 getPosition() { return pos_; }
	glm::vec4 getVelocity() { return velocity_; }
	float getSpeed() { return glm::length(velocity_); }
	float getSpeedSquared() { return glm::length2(velocity_); }
	float getAbsMaxSpeed() { return absMaxSpeed_; }

	float getVelocityX() { return velocity_.x; }
	float getVelocityY() { return velocity_.y; }
	float getVelocityZ() { return velocity_.z; }

	void transformPosition(glm::mat4 transform) { pos_ = transform * pos_; }
	void transformVelocity(glm::mat4 transform) { velocity_ = transform * velocity_; }

	void setPosition(float x, float y, float z) { pos_ = glm::vec4(x, y, z, 1.0f); }
	void setVelocity(float x, float y, float z) { pos_ = glm::vec4(x, y, z, 0.0f); }
	void setAbsMaxSpeed(float absMaxSpeed) { absMaxSpeed_ = absMaxSpeed; }

	TransformComponent& operator=(const TransformComponent& component);
};








#endif