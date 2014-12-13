#include "StateController.h"

void StateController::updateState(double frameTime)
{
	stateStack.back().OnUpdate(frameTime); //update the topmost state according to frameTime
}
sf::Sprite& StateController::drawState()
{
	return stateStack.back().OnDraw();
}