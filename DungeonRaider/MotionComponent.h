#ifndef MOTIONCOMPONENT_H
#define MOTIONCOMPONENT_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>

class MotionComponent
{
	/*
	Class MotionComponent

	This component describes all positional and motional properties of an actor at any given time,
	for example: position, velocity, and direction.
	*/
private:
	glm::vec4 _pos;
	glm::vec4 _velocity;
public:
	MotionComponent(glm::vec4 pos = glm::vec4(0.0f,0.0f,0.0f,1.0f), 
		glm::vec4 velocity = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) :
		_pos(pos), _velocity(velocity)
	{} //default constructor
	
	glm::vec4 getPosition() { return _pos; }
	glm::vec4 getVelocity() { return _velocity; }
	float getSpeed() { return glm::length(_velocity); }
	float getSpeedSquared() { return glm::length2(_velocity); }

	void transformPosition(glm::mat4 transform) { _pos = transform * _pos; }
	void transformVelocity(glm::mat4 transform) { _velocity = transform * _velocity; }
	void setPosition(float x, float y, float z) { _pos = glm::vec4(x, y, z, 1.0f); }
	void setVelocity(float x, float y, float z) { _pos = glm::vec4(x, y, z, 0.0f); }
};








#endif