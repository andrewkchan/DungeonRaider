#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
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

	sf::RenderWindow window;
	const int SCREEN_HEIGHT;
	const int SCREEN_WIDTH;
	bool verticalSyncEnabled;

	ActorManager* actorManager; //don't know actorManager's size b/c it's dynamic, so must be on heap

	void loadMedia(); //load all entities n' such
public:
	GameState() :
		SCREEN_WIDTH(640), SCREEN_HEIGHT(480), verticalSyncEnabled(false)
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

	// *brief: get user input and handle it
	// *note: param frameTime is the timestep between frames
	// *note: the time param allows handling of double-clicks n' such
	void getInput(double frameTime); 

	// *brief: updates the game using the timestep between frames, frameTime
	void update(double frameTime); 

	void draw(); //draw the current frame
};


#endif