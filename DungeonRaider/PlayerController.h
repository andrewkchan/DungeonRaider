#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Controller.h"
#include "GameState.h"


class PlayerController : Controller
{
private:
	unsigned int lastCommandTime;
public:
	PlayerController() : Controller(), lastCommandTime(0)
	{
		//default constructor
	}
	virtual void handleInput();

};





#endif