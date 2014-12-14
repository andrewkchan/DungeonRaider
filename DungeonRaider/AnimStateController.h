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
	std::vector<AnimState> possibleStates; //a dynamic array of all possible states
public:
	AnimStateController() {} //default constructor
	virtual ~AnimStateController() { possibleStates.clear(); }

	virtual sf::Sprite& getCurrStateSprite();
};





#endif