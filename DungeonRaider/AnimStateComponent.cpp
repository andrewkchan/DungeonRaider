#include "AnimStateComponent.h"

AnimStateComponent::AnimStateComponent(AnimStateController* stateController) :
_stateController(stateController), isVisible(true)
{
	if (_stateController)
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
}

AnimStateComponent::AnimStateComponent(const AnimStateComponent& animStateComponent)
{
	isVisible = animStateComponent.isVisible;
	_stateController = animStateComponent._stateController;
	_indexOfCurrentState = animStateComponent._indexOfCurrentState;
}

void AnimStateComponent::setStateController(AnimStateController* controller)
{
	_stateController = controller;
	if (_stateController)
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	//leave the game to deal with the old AnimStateController
}

void AnimStateComponent::update(double frameTime, Actor* actor)
{
	if (_stateController)
		_stateController->updateState(frameTime, *actor, _indexOfCurrentState);
}

sf::Sprite& AnimStateComponent::onDraw()
{
	if (_stateController)
		return _stateController->getStateSprite(_indexOfCurrentState);
	else
		return s_defaultController.getStateSprite(0);
	
}

AnimStateComponent& AnimStateComponent::operator=(const AnimStateComponent& animStateComponent)
{
	//check for self-assignment
	if (&animStateComponent == this)
	{
		return *this;
	}

	isVisible = animStateComponent.isVisible;
	_stateController = animStateComponent._stateController;
	_indexOfCurrentState = animStateComponent._indexOfCurrentState;

	return *this;
}


//the controller to use when no controller is provided. contains an animation with an empty sprite.
//WARNING: This static object initializes before main() executes
AnimStateController AnimStateComponent::s_defaultController;
//initialize the default (empty) animation controller to an empty controller