#include "States\AnimStateController.h"

sf::IntRect AnimStateController::OnDraw(int indexOfCurrentState, float timeInCurrentState)
{
	if (possibleStates.size() > 0)
		return possibleStates[indexOfCurrentState].OnDraw(timeInCurrentState);
	return sf::IntRect();
}
void AnimStateController::addPossibleState(const AnimState& srcState)
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

float AnimStateController::getMaxTimeOfState(int indexOfState)
{
	return possibleStates[indexOfState].getMaxTime();
}