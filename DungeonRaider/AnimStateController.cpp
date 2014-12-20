#include "AnimStateController.h"

sf::Sprite& AnimStateController::getStateSprite(int indexOfCurrentState)
{
	return possibleStates[indexOfCurrentState].OnDraw();
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