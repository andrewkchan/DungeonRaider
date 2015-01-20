#ifndef GAMESTATEMAINMENU_H
#define GAMESTATEMAINMENU_H


#include "GameState.h"

/*
Brief: The state of the main menu of the game.
*/
class GameStateMainMenu : public GameState
{
private:
	sf::View view_;

	sf::Event latestEvent_;
public:
	GameStateMainMenu(Game* game);
	virtual ~GameStateMainMenu();

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