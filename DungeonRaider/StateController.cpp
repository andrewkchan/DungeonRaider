#include "StateController.h"

void StateController::updateState(double frameTime, const PhysicalState& physicalState)
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
				indexOfCurrentState = i; //change to the next state
				possibleStates[indexOfCurrentState].OnEntry();
				return; //then exit the loop
			}
		}
	}
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