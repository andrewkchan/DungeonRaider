#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H

//fwd declarations
class Actor;
class State;

#include "AnimState.h"
#include <vector>


class StateController
{
	/*
	Class StateController

	This class encapsulates all state changes for an entity and returns the conditions that each state implies.
	The entity should pass in a struct representing its physical state or a trigger representing an external event,
	which the StateController should handle and thus determine the new state that the entity is in.
	
	Each actor's StateComponent contains a pointer to a StateController, which will be shared among actors of
	the same type of ingame object.
	*/


protected:
	int indexOfDefaultState; //the index of the default state
	std::string nextStateName; //the name of the next state
private:
	std::vector<State> possibleStates; //a dynamic array of all possible states
public:
	StateController() {} //default constructor
	virtual ~StateController() { possibleStates.clear(); }

	int getIndexOfDefaultState() { return indexOfDefaultState; }

	//change the state based on the time since last frame and actor's current state (and physical state)
	//returns the index of the state we change to
	virtual int updateState(double frameTime, Actor& actor, int indexOfCurrentState); 

	virtual void addPossibleState(const State& srcState);
	virtual void setDefaultState(std::string defaultState);
};







#endif