#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include "Game.h"

//Base class for the discrete states of the game.
class GameState
{
	/*
	Class GameState

	This class describes a discrete state of the game, such as a pause state, play state, menu state, etc.

	It contains methods for initializing the game and loading all media/renderers/etc,
	handling user input for the game, updating the game, drawing the game, and closing the game.
	
	
	*/
protected:
	Game* game_;
	sf::Sprite background_;
public:
	GameState(Game* game = 0) : game_(game)
	{
		background_.setTexture(game_->sharedTextures_.getTexture("background"));
	}
	virtual ~GameState() {} //obviously we don't want to delete the game

	// *brief: get user input and handle it
	// *note: param frameTime is the timestep between frames
	// *note: the time param allows handling of double-clicks n' such
	virtual void getInput(double frameTime) = 0; 

	// *brief: updates the game using the timestep between frames, frameTime
	virtual void update(double frameTime) = 0; 

	// *brief: draw the current frame
	virtual void draw() = 0; 
};


#endif