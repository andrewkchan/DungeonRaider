#include "StateComponent.h"

StateComponent::StateComponent(StateController* controller) : _stateController(controller)
{
	_indexOfCurrentState = _stateController->getIndexOfDefaultState();
}
StateComponent::StateComponent(const StateComponent& stateComponent)
{
	_indexOfCurrentState = stateComponent._indexOfCurrentState;
	_stateController = stateComponent._stateController;
}

void StateComponent::setStateController(StateController* controller)
{
	_stateController = controller;
	_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	//leave the game to deal with the old state controller
}
void StateComponent::update(double frameTime, Actor* actor) 
{ 
	_stateController->updateState(frameTime, *actor, _indexOfCurrentState); 
}