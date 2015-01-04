#ifndef STATECOMPONENT_H
#define STATECOMPONENT_H

//fwd declarations
class Actor;
class StateController;

#include "StateController.h"

class StateComponent
{
	/*
	Class StateComponent

	This component encapsulates the current state of the Actor and interfacing with the Actor's StateController
	in order to update states.
	
	*/
protected:
	int _indexOfCurrentState; //the index in StateController's vector of states that the actor is currently in
private:
	StateController* _stateController; //the class containing all possible states for this actor
public:
	StateComponent(StateController* controller = 0);
	StateComponent(const StateComponent& stateComponent);

	
	void setStateController(StateController* controller);
	void update(double frameTime, Actor* actor);

	StateComponent& operator=(const StateComponent& stateComponent);
};






#endif