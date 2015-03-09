#include "TransformComponent.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

void TransformComponent::update(float frameTime, Actor& actor)
{
	pos2D_.setPosition(
		pos_.x, //2D x coordinates
		-1.0f*(pos_.y + pos_.z) //2D y coordinates, multiplied by -1 b/c origin is on top left
		);

	//std::cout << "x:" << pos_.x << " y:" << pos_.y << " z:" << pos_.z << std::endl;
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