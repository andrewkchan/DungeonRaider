#ifndef ANIMSTATECOMPONENT_H
#define ANIMSTATECOMPONENT_H

//fwd declarations
class AnimStateController;
class Actor;

#include "DrawableComponent.h"
#include "AnimStateController.h"



class AnimStateComponent : public DrawableComponent
{
	/*
	Class AnimStateComponent

	This class encapsulates actor interaction with its current drawable state.
	*/
private:
	bool isVisible_;
	int indexOfCurrentState_;
	float timeInCurrentState_;
	AnimStateController* stateController_;

	//the thing we want to draw!
	sf::Sprite currentFrame_; 
public:
	AnimStateComponent();
	AnimStateComponent(sf::Texture& spriteSheet, AnimStateController* stateController = 0);
	AnimStateComponent(const AnimStateComponent& animStateComponent);

	void setStateController(AnimStateController* controller);
	virtual void update(float frameTime, Actor& actor);
	virtual sf::Sprite& onDraw();

	AnimStateComponent& operator=(const AnimStateComponent& animStateComponent);
};




#endif