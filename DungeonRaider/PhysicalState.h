#ifndef PHYSICALSTATE_H
#define PHYSICALSTATE_H

#include "EVector3.h"

struct PhysicalState
{
	/*
	This struct defines all the temporary, mutable, instance characteristics of an Actor.
	*/
	PhysicalState(int inputHealth = 0, bool inputIsPoisoned = false, EVector3 inputPos = EVector3(), EVector3 inputVelocity = EVector3())
		: 
		health(0), isPoisoned(false), pos(EVector3()), velocity(EVector3()) {} //default constructor

	int health;
	bool isPoisoned;
	EVector3 pos;
	EVector3 velocity;
};


#endif