#ifndef ANIMSTATECONTROLLER_H
#define ANIMSTATECONTROLLER_H


#include "StateController.h"

class AnimStateController : public StateController
{
	/*
	Class AnimStateController


	This class controls all states that have animations associated with them.
	
	*/
private:
	std::vector<AnimState> stateStack; //a pushdown automata of states, or a stack of states where we can push and pop states
	std::vector<AnimState> possibleStates; //a dynamic array of all possible states
public:
	AnimStateController() {} //default constructor
	virtual ~AnimStateController() { stateStack.clear(); possibleStates.clear(); }

	virtual sf::Sprite& getCurrStateSprite();
};





#endif