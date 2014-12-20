#ifndef ANIMSTATECOMPONENT_H
#define ANIMSTATECOMPONENT_H

//fwd declarations
class AnimStateController;
class Actor;


#include "AnimStateController.h"



class AnimStateComponent
{
	/*
	Class AnimStateComponent

	This class encapsulates actor interaction with its current drawable state.
	*/
private:
	static AnimStateController s_defaultController;

	bool isVisible;
	int _indexOfCurrentState;
	AnimStateController* _stateController;
public:
	AnimStateComponent(AnimStateController* stateController = 0);
	AnimStateComponent(const AnimStateComponent& animStateComponent);

	void setStateController(AnimStateController* controller);
	void update(double frameTime, Actor* actor);
	sf::Sprite& onDraw();
};




#endif