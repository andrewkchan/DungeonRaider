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
	AnimState() : State(), anim() //single-frame animation
	{} 
	//implicit copy-constructor!

	AnimState(std::string name, Animation& srcAnim) :
		State(name)
		//sets the animation to srcAnim
	{
		anim = srcAnim;
	}
	virtual ~AnimState() {}

	//draw the animation's current frame according to total continuous time spent in the state so far
	sf::IntRect OnDraw(float timeInState);

};






#endif