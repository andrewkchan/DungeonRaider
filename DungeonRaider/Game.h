#ifndef GAME_H
#define GAME_H

//forward declarations
class GameState;

#include <stack>
#include "GraphicsWrappers\Window.h"
#include <iostream>
#include "TextureLibrary.h"




//The master class!
class Game
{
	/*
	Class Game

	This class contains the game loop and manages a stack of GameStates.
	In short, Game is a state manager for the entire game.
	*/
private:
	std::stack<GameState*> states;

	const int SCREEN_HEIGHT; //constants initialized in Game.cpp
	const int SCREEN_WIDTH;
	bool bRunGame;

	void loadSharedTextures();
public:
	TextureLibrary sharedTextures_;
	gWrap::Window window;

	Game();
	~Game();

	void pushState(GameState* state);
	void popState();

	/*Replaces the top of the state stack with param state*/
	void swapState(GameState* state); 
	/*Returns a pointer to the current top of the state stack, NULL if stack is empty*/
	GameState* peekState();

	void runGameLoop();
	void closeGame();
};







#endif