#ifndef ANIMSTATECONTROLLER_H
#define ANIMSTATECONTROLLER_H

//fwd declarations
class AnimState;
class StateController;

#include "StateController.h"
#include "AnimState.h"



class AnimStateController : public StateController
{
	/*
	Class AnimStateController


	This class controls all states that have animations associated with them.
	
	*/
private:
	std::vector<AnimState> possibleStates; //a dynamic array of all possible states
public:
	AnimStateController() 
	{
		possibleStates.push_back(AnimState());
	} //default constructor
	virtual ~AnimStateController() { possibleStates.clear(); }

	virtual sf::Sprite& getStateSprite(int indexOfCurrentState);
	virtual void addPossibleState(const AnimState& srcState);
};





#endif