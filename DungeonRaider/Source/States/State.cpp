#include "States\State.h"

std::string State::OnUpdate(Actor& actor, double frameTime)
{
	//check transitions to see if the actor should change state
	currTransition = possibleTransitions.begin();
	while (currTransition != possibleTransitions.end())
	{
		if (currTransition->second.canTransition(actor))
		{
			//if we can transition to any state in the possibleTransitions map, return the name of that state
			return currTransition->first;
		}
		currTransition++;
	}
	//if we can't transition to any other states, simply return the name of our state (this state)
	return stateName;
}
void State::addTransitionToState(std::string transitionToThis)
{
	//adds a key/value pair in the map possibleTransitions
	//key = transitionToThis
	//value = (an empty Transition object)
	possibleTransitions.insert(std::pair<std::string, Transition>(transitionToThis, Transition()));
}
void State::setTransitionToState(std::string transitionToThis, Transition newTransition)
{
	//loop through transition map, looking for the specified state
	currTransition = possibleTransitions.begin();
	while (currTransition != possibleTransitions.end())
	{
		if (currTransition->first == transitionToThis)
		{
			//found the state, now add the transition
			currTransition->second = newTransition;
			return;
		}
		currTransition++;
	}
}