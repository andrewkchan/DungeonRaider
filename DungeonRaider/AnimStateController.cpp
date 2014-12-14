#include "AnimStateController.h"

sf::Sprite& AnimStateController::getCurrStateSprite()
{
	return stateStack.back().OnDraw();
}