#ifndef ANIMSTATE_H
#define ANIMSTATE_H

#include "State.h"
#include "Animation.h"

class AnimState : public State
{
	/*
	Class AnimState

	This describes a state that can return the animation that an Actor should be playing while in the state.
	
	*/
protected:
	Animation anim; //the animation that should be played while in this state, allocated on stack so don't worry about deletion

	virtual void checkConditions();
public:
	AnimState() {} //default constructor
	AnimState(const Animation& srcAnim) //copy constructor
	{
		anim = srcAnim;
	}
	virtual ~AnimState() {}

	virtual void OnUpdate(double frameTime);
	virtual sf::Sprite& OnDraw();

};






#endif