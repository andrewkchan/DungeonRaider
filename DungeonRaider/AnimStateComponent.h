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
	static AnimStateController s_defaultController; //the controller to use when no controller is provided. contains an animation with an empty sprite.

	bool isVisible;
	int _indexOfCurrentState;
	AnimStateController* _stateController;
public:
	AnimStateComponent(AnimStateController* stateController = 0);
	AnimStateComponent(const AnimStateComponent& animStateComponent);

	void setStateController(AnimStateController* controller);
	void update(double frameTime, Actor* actor);
	sf::Sprite& onDraw();

	AnimStateComponent& operator=(const AnimStateComponent& animStateComponent);
};




#endif