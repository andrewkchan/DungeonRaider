#include "StateController.h"

void StateController::updateState(double frameTime, const PhysicalState& physicalState)
{
	stateStack.back().OnUpdate(frameTime); //update the topmost state according to frameTime
}
void StateController::addPossibleState(const State& srcState)
{
	possibleStates.push_back(srcState);
}