#include "StateController.h"

int StateController::updateState(double frameTime, const PhysicalState& physicalState, int indexOfCurrentState)
{
	//update the topmost state according to frameTime
	//also check if we change states
	nextStateName = possibleStates[indexOfCurrentState].OnUpdate(frameTime);
	if (nextStateName != possibleStates[indexOfCurrentState].getName())
	{
		//if the current state reports that the state we should change to is not the current state's name,
		//then change to the new state
		for (size_t i = 0; i < possibleStates.size(); i++)
		{
			if (possibleStates[i].getName() == nextStateName)
			{
				//change to the next state
				int nextState = i;
				possibleStates[nextState].OnEntry();
				return nextState; //then exit the loop
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