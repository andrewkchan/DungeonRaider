#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H


#include "GameState.h"

/*
Class GameStatePlay
Brief: The state of the engine where the user can create the game.
*/
class GameStateEditor : public GameState
{
private:
	sf::View gameView_; //camera
	sf::View guiView_;

	sf::Event latestEvent_; //the latest keyboard event
public:
	GameStateEditor(Game* game);
	virtual ~GameStateEditor();

	// *brief: get user input and handle it
	// *note: param frameTime is the timestep between frames
	// *note: the time param allows handling of double-clicks n' such
	virtual void getInput(double deltaTime);
	// *brief: updates the game using the timestep between frames, frameTime
	virtual void update(double deltaTime);
	// *brief: draw the current frame
	virtual void draw();
};

#endif