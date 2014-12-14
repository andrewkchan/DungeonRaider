#include "AnimStateController.h"

sf::Sprite& AnimStateController::getCurrStateSprite()
{
	return possibleStates[indexOfCurrentState].OnDraw();
}