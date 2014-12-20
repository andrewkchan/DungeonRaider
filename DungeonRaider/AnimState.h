#ifndef ANIMSTATE_H
#define ANIMSTATE_H

//fwd declarations
class Animation;

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

public:
	AnimState() 
	{
		anim = Animation(sf::Sprite()); //make a single-frame animation using an empty sprite
	} //default constructor with placeholder animation
	AnimState(const AnimState& animState)
	{
		anim = animState.anim;
	}
	AnimState(const Animation& srcAnim) //sets the animation to srcAnim
	{
		anim = srcAnim;
	}
	virtual ~AnimState() {}

	virtual sf::Sprite& OnDraw();

};






#endif