#ifndef STATE_H
#define STATE_H

#include "Actor.h"
#include "Transition.h"
#include <map>

//fwd declarations
class Actor;

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
	const double stateTime; //the maximum amount of time possible in this state, <0 if infinite
	double timeInState; //the total time spent in the state so far

	std::map<std::string, Transition> possibleTransitions; //a map of transitions (Transition) to possible states (std::string)
	std::map<std::string, Transition>::iterator currTransition; //an iterator for the above map
public:
	State() : stateTime(0) {} //default constructor (for making arrays)
	State(std::string name) : stateTime(0), stateName(name) {} //constructor with name param
	virtual ~State() {}

	/*tick function, checks whether actor should transition to another state or not
	if actor is to transition to another state, return the name of the next state
	if the actor cannot transition to any other states, return the name of this state
	*/
	virtual std::string OnUpdate(double frameTime);

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
	virtual std::string getName() const { return stateName; }
	//to be called when entering the state
	virtual void OnEntry() { timeInState = 0; }
};



#endif