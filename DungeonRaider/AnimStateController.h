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
	{}
	virtual ~AnimStateController() { possibleStates.clear(); }

	//return the portion of the texture that should be currently drawn
	//the entity calling this supplies its current state
	sf::IntRect OnDraw(int indexOfCurrentState, float timeInCurrentState);
	virtual void addPossibleState(const AnimState& srcState);
	float getMaxTimeOfState(int indexOfState);
};





#endif