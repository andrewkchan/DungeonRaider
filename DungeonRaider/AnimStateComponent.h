#ifndef ANIMSTATECOMPONENT_H
#define ANIMSTATECOMPONENT_H


#include "AnimStateController.h"



class AnimStateComponent
{
	/*
	Class AnimStateComponent

	This class encapsulates actor interaction with its current drawable state.
	*/
private:
	bool isVisible;
	int _indexOfCurrentState;
	AnimStateController* _stateController;
public:
	AnimStateComponent(AnimStateController* stateController) :
		_stateController(stateController), isVisible(true)
	{
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
	}
	AnimStateComponent(const AnimStateComponent& animStateComponent)
	{
		isVisible = animStateComponent.isVisible;
		_stateController = animStateComponent._stateController;
		_indexOfCurrentState = animStateComponent._indexOfCurrentState;
	}

	void setStateController(AnimStateController* controller)
	{
		_stateController = controller;
		_indexOfCurrentState = _stateController->getIndexOfDefaultState();
		//leave the game to deal with the old AnimStateController
	}
	void update(double frameTime, Actor* actor) { _stateController->updateState(frameTime, *actor, _indexOfCurrentState); }
	sf::Sprite& onDraw() { _stateController->getStateSprite(_indexOfCurrentState); }
};




#endif