#ifndef PHYSICALSTATE_H
#define PHYSICALSTATE_H

#include "Vector3.h"

struct PhysicalState
{
	/*
	This struct defines all the temporary, mutable, instance characteristics of an Actor.
	*/
	PhysicalState(int inputHealth = 0, bool inputIsPoisoned = false, Vector3 inputPos = Vector3(), Vector3 inputVelocity = Vector3())
		: 
		health(0), isPoisoned(false), pos(Vector3()), velocity(Vector3()) {} //default constructor

	int health;
	bool isPoisoned;
	Vector3 pos;
	Vector3 velocity;
};


#endif