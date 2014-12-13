#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H


#include "AnimState.h"
#include <vector>


class StateController
{
	/*
	Class StateController

	This class encapsulates all state changes for an entity and returns the conditions that each state implies.
	The entity should pass in a struct representing its physical state or a trigger representing an external event,
	which the StateController should handle and thus determine the new state that the entity is in.
	
	Each actor contains a pointer to a StateController.
	*/


private:
	std::vector<AnimState> stateStack; //a pushdown automata of states, or a stack of states where we can push and pop states
	std::vector<AnimState> possibleStates; //a dynamic array of all possible states
public:
	StateController() {} //default constructor

	void updateState(double frameTime); //change the state based on the time since last frame
	sf::Sprite& drawState();
};







#endif