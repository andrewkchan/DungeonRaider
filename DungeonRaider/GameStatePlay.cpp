#include "GameStatePlay.h"
#include "GameStateMainMenu.h"

GameStatePlay::GameStatePlay(Game* game) : GameState(game)
{
	sf::Vector2f windowSize = sf::Vector2f(game_->window.getSize());
	gameView_.setSize(windowSize);
	guiView_.setSize(windowSize);

	gameView_.setCenter(0.5f * windowSize);
	guiView_.setSize(0.5f * windowSize);

	
}
GameStatePlay::~GameStatePlay()
{}

void GameStatePlay::draw()
{
	game_->window.setView(gameView_);
}
void GameStatePlay::update(double deltaTime)
{

}
void GameStatePlay::getInput(double deltaTime)
{
	while (game_->window.pollEvent(latestEvent_))
		//pull the latest keyboard events and put them in latestEvent_
		//as long as there are still keyboard events in the event queue
	{
		switch (latestEvent_.type)
		{
		case sf::Event::Closed:
		{
			//close the window and end the game
			game_->closeGame();
			break;
		}
		case sf::Event::Resized:
		{
			//resize the window


			gameView_.setSize(latestEvent_.size.width, latestEvent_.size.height);
			guiView_.setSize(latestEvent_.size.width, latestEvent_.size.height);
			//resize the background along with the resized window
			//pin background to window center
			background_.setPosition(game_->window.mapPixelToCoords(sf::Vector2i(0, 0)));
			//now set background scale
			background_.setScale(
				static_cast<float>(latestEvent_.size.width) / static_cast<float>(background_.getTexture()->getSize().x),
				static_cast<float>(latestEvent_.size.height) / static_cast<float>(background_.getTexture()->getSize().y)
				);
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (latestEvent_.key.code == sf::Keyboard::Escape)
			{
				openMainMenu();
			}
			break;
		}
		default:
		{
			//do nothing
			break;
		}
		}
	} //<---end event poll loop
}

/*
------Private functions------------
*/
void GameStatePlay::loadPlayTextures()
{
	//TODO!
}
void GameStatePlay::openMainMenu()
{
	game_->pushState(new GameStateMainMenu(game_));
}