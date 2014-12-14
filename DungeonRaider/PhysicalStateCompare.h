#ifndef PHYSICALSTATECOMPARE_H
#define PHYSICALSTATECOMPARE_H

#include "PhysicalState.h"

enum BoolFunc
{
	EQUAL_TO,
	NOT_EQUAL_TO,
	LESS_THAN,
	GREATER_THAN,
	LESS_THAN_OR_EQUAL_TO,
	GREATER_THAN_OR_EQUAL_TO,
	NOT_REQUIRED
};

class PhysicalStateComparer
{
private:
	BoolFunc eHealth;
	int health;
	BoolFunc ePos;
	glm::vec4 pos;
	BoolFunc eVelocity;
	glm::vec4 velocity;
public:
	PhysicalStateComparer(BoolFunc input_eHealth, int input_health,
		BoolFunc input_ePos, glm::vec4 input_pos, BoolFunc input_eVelocity, glm::vec4 input_velocity)
		:
		eHealth(input_eHealth),
		ePos(input_ePos)
		eVelocity(input_eVelocity)
	{
		health = input_health;
		pos = input_pos;
		velocity = input_velocity;
	}

	bool compareTo(const PhysicalState& physicalState)
	{
		switch eHealth
		{
		case EQUAL_TO:
			if (health != physicalState.health)
				return false;
			break;
		case NOT_EQUAL_TO:
			if (health == physicalState.health)
				return false;
			break;
		case LESS_THAN:
			if (!(health < physicalState.health))
				return false;
			break;
		case GREATER_THAN:
			if (!(health > physicalState.health))
				return false;
			break;
		case LESS_THAN_OR_EQUAL_TO:
			if (!(health <= physicalState.health))
				return false;
			break;
		case GREATER_THAN_OR_EQUAL_TO:
			if (!(health >= physicalState.health))
				return false;
			break;
		case NOT_REQUIRED:
			break;
		}
		switch ePos
		{
		case EQUAL_TO:
			if (glm::length(pos) != glm::length(physicalState.pos))
				return false;
			break;
		case NOT_EQUAL_TO:
			if (glm::length(pos) == glm::length(physicalState.pos))
				return false;
			break;
		case LESS_THAN:
			if (glm::length(pos) >= glm::length(physicalState.pos))
				return false;
			break;
		case GREATER_THAN:
			if (glm::length(pos) <= glm::length(physicalState.pos))
				return false;
			break;
		case LESS_THAN_OR_EQUAL_TO:
			if (glm::length(pos) > glm::length(physicalState.pos))
				return false;
			break;
		case GREATER_THAN_OR_EQUAL_TO:
			if (glm::length(pos) < glm::length(physicalState.pos))
				return false;
			break;
		case NOT_REQUIRED:
			break;
		}
		switch ePos
		{
		case EQUAL_TO:
			if (glm::length(velocity) != glm::length(physicalState.velocity))
				return false;
			break;
		case NOT_EQUAL_TO:
			if (glm::length(velocity) == glm::length(physicalState.velocity))
				return false;
			break;
		case LESS_THAN:
			if (glm::length(velocity) >= glm::length(physicalState.velocity))
				return false;
			break;
		case GREATER_THAN:
			if (glm::length(velocity) <= glm::length(physicalState.velocity))
				return false;
			break;
		case LESS_THAN_OR_EQUAL_TO:
			if (glm::length(velocity) > glm::length(physicalState.velocity))
				return false;
			break;
		case GREATER_THAN_OR_EQUAL_TO:
			if (glm::length(velocity) < glm::length(physicalState.velocity))
				return false;
			break;
		case NOT_REQUIRED:
			break;
		}
		return true;
	}
};




#endif