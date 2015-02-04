#include "TransformComponent.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

void TransformComponent::update(float frameTime, Actor& actor)
{
	//these constants should be made inline by the compiler
	const float sineTheta = sinf(0.5236f); //the sine of the angle between horizontal and the world's x or y axes
	const float cosineTheta = cosf(0.5236f); //the cosine of the angle between horizontal and the world's x or y axes
	pos2D_.setPosition(
		(pos_.y * cosineTheta - pos_.x * cosineTheta), //2D x coordinates
		-1.0f * (pos_.y * sineTheta + pos_.x * sineTheta + pos_.z) //2D y coordinates, multiplied by -1 b/c origin is on top left
		);

	//std::cout << pos_.z << std::endl;
}
sf::Transform TransformComponent::get2DTransform() const
{
	return pos2D_.getTransform();
}

TransformComponent& TransformComponent::operator=(const TransformComponent& component)
{
	//check for self-assignment
	if (this == &component)
	{
		return *this;
	}

	pos_ = component.pos_;
	direction_ = component.direction_;
	pos2D_ = component.pos2D_;

	return *this;
}