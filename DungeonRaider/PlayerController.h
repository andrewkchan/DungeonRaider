#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Controller.h"
#include "GameState.h"


class PlayerController : Controller
{
private:
	Uint32 lastCommandTime;
public:
	PlayerController() : Controller(), lastCommandTime(SDL_GetTicks())
	{
		//default constructor
	}
	virtual void handleInput(Uint8* keyStateArray);

};





#endif