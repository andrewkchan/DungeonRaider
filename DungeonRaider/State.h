#ifndef STATE_H
#define STATE_H


#include "Transition.h"
#include <map>

//fwd declarations
class Transition;

class State
{
	/*
	Class State

	This class encapsulates the conditions required for, the conditions implied by, 
	and the possible states to transition to of an Actor at any given time.
	
	State is a component class of StateController.
	*/
private:
	//nothing... for now
protected:
	std::string stateName; //the name of the state
	float stateTime; //the maximum amount of time possible in this state (seconds), <=0 if infinite

	std::map<std::string, Transition> possibleTransitions; //a map of transitions (Transition) to possible states (std::string)
	std::map<std::string, Transition>::iterator currTransition; //an iterator for the above map
public:
	//default constructor (for initializing arrays)
	State() : stateTime(0), stateName("") {} 
	//constructor with name and max time param
	State(std::string name, float maxTime = 0.0f) : stateTime(maxTime), stateName(name) {} 
	virtual ~State() {}

	/*tick function, checks whether actor should transition to another state or not
	if actor is to transition to another state, return the name of the next state
	if the actor cannot transition to any other states, return the name of this state
	*/
	virtual std::string OnUpdate(Actor& actor, double frameTime);

	/*
	Adds a state that this state can transition to. 
	A transition object to that state is automatically created.
	*/
	virtual void addTransitionToState(std::string transitionToThis);
	/*
	Sets the transition object mapped to another state to the specified transition
	*/
	virtual void setTransitionToState(std::string transitionToThis, Transition newTransition);

	//return the name of the current state
	std::string getName() const { return stateName; }

	//change the name of the state (unsafe if already in stateController... could lead to duplicate states)
	//void setName(std::string newName) { stateName = newName; }

	//change the maximum amount of time possible for an entity to spend in the state
	void setMaxTime(float newMaxTime) { stateTime = newMaxTime; }
	//return the maximum amount of time possible for an entity to spend in the state
	float getMaxTime() { return stateTime; }
};



#endif