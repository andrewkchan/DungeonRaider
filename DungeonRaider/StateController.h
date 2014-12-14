#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H


#include "AnimState.h"
#include <vector>
#include "PhysicalState.h"


class StateController
{
	/*
	Class StateController

	This class encapsulates all state changes for an entity and returns the conditions that each state implies.
	The entity should pass in a struct representing its physical state or a trigger representing an external event,
	which the StateController should handle and thus determine the new state that the entity is in.
	
	Each actor contains a pointer to a StateController.
	*/


protected:
	int indexOfCurrentState; //the state that the actor is currently in
	std::string nextStateName; //the name of the next state
private:
	std::vector<State> possibleStates; //a dynamic array of all possible states
public:
	StateController() {} //default constructor
	virtual ~StateController() { possibleStates.clear(); }


	//change the state based on the time since last frame and actor's current physical state
	virtual void updateState(double frameTime, const PhysicalState& physicalState); 

	virtual void addPossibleState(const State& srcState);

};







#endif