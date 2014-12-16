#ifndef STATECOMPONENT_H
#define STATECOMPONENT_H

#include "StateController.h"


class StateComponent
{
	/*
	Class StateComponent

	This component encapsulates the current state of the Actor and interfacing with the Actor's StateController
	in order to update states.
	
	*/
private:
	int _indexOfCurrentState; //the index in StateController's vector of states that the actor is currently in
	StateController* _stateController; //the class containing all possible states for this actor
public:
	StateComponent(StateController* controller = 0) : _stateController(controller)
	{
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	}
	
	void setStateController(StateController* controller)
	{
		_stateController = controller;
		//leave the game to deal with the old state controller
	}
	void update() {}
};






#endif