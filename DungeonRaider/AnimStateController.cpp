#include "AnimStateController.h"

sf::Sprite& AnimStateController::getStateSprite(int indexOfCurrentState)
{
	return possibleStates[indexOfCurrentState].OnDraw();
}