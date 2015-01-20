#include "StateComponent.h"

StateComponent::StateComponent(StateController* controller) : _stateController(controller)
//note: has default arg of null
{
	if (_stateController)
	{
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	}
	else
	{
		_indexOfCurrentState = -1;
	}
}
StateComponent::StateComponent(const StateComponent& stateComponent)
{
	_indexOfCurrentState = stateComponent._indexOfCurrentState;
	_stateController = stateComponent._stateController;
}

void StateComponent::setStateController(StateController* controller)
{
	_stateController = controller;
	if (_stateController)
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	else
		_indexOfCurrentState = -1;
	//leave the game to deal with the old state controller
}
void StateComponent::update(double frameTime, Actor* actor) 
{ 
	if (_stateController)
		_stateController->updateState(frameTime, *actor, _indexOfCurrentState); 
	//else do nothing
}

StateComponent& StateComponent::operator=(const StateComponent& stateComponent)
{
	//check self-assignment
	if (this == &stateComponent)
	{
		return *this;
	}

	_indexOfCurrentState = stateComponent._indexOfCurrentState;
	_stateController = stateComponent._stateController;
	return *this;
}