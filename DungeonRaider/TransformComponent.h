#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>
#include "Component.h"
#include <SFML/Graphics.hpp> //for conversion to 2D coordinates


class TransformComponent : public Component
{
	/*
	Class TransformComponent

	This component describes all positional and motional properties of an actor at any given time,
	for example: position, velocity, and direction.
	*/
private:
	glm::vec4 pos_; //the world coordinates and rotation of the actor represented as a 4x1 vector, with 4th element = 1
	glm::vec4 direction_; //the current velocity of the actor, with 4th element = 0

	sf::Transformable pos2D_; //the world coordinates of the actor converted to 2D
public:
	TransformComponent(const glm::vec4& pos = glm::vec4(0.0f,0.0f,0.0f,1.0f), 
		const glm::vec4& direction = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) :
		pos_(pos), 
		direction_(direction)
	{} //default constructor
	TransformComponent(const TransformComponent& component)
	{
		pos_ = component.pos_;
		direction_ = component.direction_;
		pos2D_ = component.pos2D_;
	}
	
	glm::vec4 getPosition() { return pos_; }
	float getPositionX() { return pos_.x; }
	float getPositionY() { return pos_.y; }
	float getPositionZ() { return pos_.z; }
	glm::vec4 getVelocity() { return direction_; }
	float getSpeed() { return glm::length(direction_); }
	float getSpeedSquared() { return glm::length2(direction_); }

	//get the horizontal velocity in the x-direction of the actor
	float getDirectionX() { return direction_.x; }
	//get the horizontal velocity in the y-direction of the actor
	float getDirectionY() { return direction_.y; }
	//get the vertical velocity of the actor
	float getDirectionZ() { return direction_.z; }

	void transformPosition(const glm::mat4& transform) { pos_ = transform * pos_; }
	void transformDirection(const glm::mat4& transform) { direction_ = transform * direction_; }

	void setPosition(float x, float y, float z) { pos_ = glm::vec4(x, y, z, 1.0f); }
	void setDirection(float x, float y, float z) { pos_ = glm::vec4(x, y, z, 0.0f); }

	void translatePosition(const glm::vec4& translation) { pos_ += translation; }
	void translatePosition(float x, float y, float z) { pos_ += glm::vec4(x, y, z, 0.0f); }


	virtual void update(float frameTime, Actor& actor);
	virtual sf::Transform get2DTransform() const;

	TransformComponent& operator=(const TransformComponent& component);
};








#endif