#include "States\StateController.h"

int StateController::updateState(double frameTime, Actor& actor, int indexOfCurrentState)
{
	//update the topmost state according to frameTime
	//also check if we change states
	nextStateName = possibleStates[indexOfCurrentState].OnUpdate(actor, frameTime);
	if (nextStateName != possibleStates[indexOfCurrentState].getName())
	{
		//if the current state reports that the state we should change to is not the current state's name,
		//then change to the new state
		for (unsigned int i = 0; i < possibleStates.size(); ++i) //use indices, not iterators, 'cause we know we're using a vector
		{
			if (possibleStates[i].getName() == nextStateName)
			{
				//change to the next state

				//int nextState = i;
				//possibleStates[nextState].OnEntry();
				//return nextState; //then exit the loop
				return i;
			}
		}
	}
	return indexOfCurrentState;
}
void StateController::addPossibleState(const State& srcState)
{
	//check for duplicate state names
	for (size_t i = 0; i < possibleStates.size(); i++)
	{
		if (possibleStates[i].getName() == srcState.getName())
		{
			return; //if the state we want to add has a duplicate name, do nothing and exit the function
			//todo: debug log that we tried to add a duplicate name
		}
	}
	possibleStates.push_back(srcState);
}
void StateController::setDefaultState(std::string defaultState)
{
	for (size_t i = 0; i < possibleStates.size(); i++)
	{
		if (possibleStates[i].getName() == defaultState)
		{
			indexOfDefaultState = static_cast<int>(i);
			return;
		}
	}
}