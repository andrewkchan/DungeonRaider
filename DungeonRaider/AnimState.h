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
	//default constructor with placeholder (empty) animation
	AnimState() : State(), 
		anim(sf::Sprite()) //make a single-frame animation using an empty sprite
	{} 
	AnimState(const AnimState& animState)
	{
		anim = animState.anim;
	}
	AnimState(std::string name, Animation& srcAnim) :
		State(name)
		//sets the animation to srcAnim
	{
		anim = srcAnim;
	}
	virtual ~AnimState() {}

	virtual sf::Sprite& OnDraw();

};






#endif