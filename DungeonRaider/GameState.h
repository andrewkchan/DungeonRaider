#ifndef GAMESTATE_H
#define GAMESTATE_H


#include <iostream>
#include "ActorManager.h"

class ActorManager; //forward declaration of dependencies

class GameState
{
	/*
	Class GameState

	This class describes the whole game for each iteration of the game loop.

	It contains methods for initializing the game and loading all media/renderers/etc,
	handling user input for the game, updating the game, drawing the game, and closing the game.
	
	
	*/
private:


	const int SCREEN_HEIGHT;
	const int SCREEN_WIDTH;

	ActorManager* actorManager; //don't know actorManager's size b/c it's dynamic, so must be on heap

	void loadMedia(); //load all entities n' such
public:
	GameState() :
		SCREEN_WIDTH(640), SCREEN_HEIGHT(480)
	{
		//default constructor

	}
	~GameState()
	{
		//destructor
	}


	void init();
	void close();

	//todo: pause and resume functions

	void getInput(unsigned int curr_frame_time); //get user input and handle it
	void update(double frameTime); //updates the game using the timestep between frames, frameTime
	void draw(); //draw the current frame
};


#endif