#ifndef GAMESTATEPLAY_H
#define GAMESTATEPLAY_H


#include "TextureLibrary.h"
#include "GameState.h"
#include "Scene.h"

/*
Class GameStatePlay
Brief: The main state of the game that contains all gameplay.
*/
class GameStatePlay : public GameState
{
private:
	sf::View gameView_; //the 2D game "camera"
	sf::View guiView_;

	sf::Event latestEvent_;
	
	Scene* currentScene;
	TextureLibrary sharedPlayTextures;

	void loadPlayTextures();

	//state-changer functions
	void openMainMenu();
public:
	GameStatePlay(Game* game);
	virtual ~GameStatePlay();

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