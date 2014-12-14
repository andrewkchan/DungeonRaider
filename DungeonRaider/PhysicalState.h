#ifndef PHYSICALSTATE_H
#define PHYSICALSTATE_H

#include <glm.hpp>

struct PhysicalState
{
	/*
	This struct defines all the temporary, mutable, instance characteristics of an Actor.
	*/
	PhysicalState(
		int inputHealth = 0,
		glm::vec4 inputPos = glm::vec4(0.0f,0.0f,0.0f,1.0f), glm::vec4 inputVelocity = glm::vec4(0.0f,0.0f,0.0f,0.0f)
		)
		: 
		health(0), pos(inputPos), velocity(inputVelocity) {} //default constructor

	int health;
	glm::vec4 pos;
	glm::vec4 velocity;
};


#endif