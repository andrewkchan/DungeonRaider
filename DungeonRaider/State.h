#ifndef STATE_H
#define STATE_H

#include "Actor.h"

//fwd declarations
class Actor;

class State
{
	/*
	Class State

	This class encapsulates the conditions required for, the conditions implied by, the states linked to,
	and the states linked by an Actor at any given time.
	
	State is a component class of StateController.
	*/
private:
protected:
	const double stateTime; //the maximum amount of time possible in this state, <0 if infinite
	double timeInState; //the total time spent in the state so far
	virtual void checkConditions() = 0;
public:
	State() : stateTime(0) {} //default constructor
	virtual ~State() {}
	virtual void OnUpdate(double frameTime) = 0;
};



#endif