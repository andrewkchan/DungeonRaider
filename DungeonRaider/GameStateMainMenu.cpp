#include "GameStateMainMenu.h"
#include "GameStatePlay.h"
#include <SFML\Graphics.hpp>



GameStateMainMenu::GameStateMainMenu(Game* game) : GameState(game)
{
	sf::Vector2f windowSize = sf::Vector2f(
		static_cast<float>(game_->window.getWidth()),
		static_cast<float>(game_->window.getHeight()));
	view_.setSize(windowSize);
	view_.setCenter(0.5f * windowSize);
}
GameStateMainMenu::~GameStateMainMenu()
{}

void GameStateMainMenu::draw()
{
	game_->window.setView(view_);
}
void GameStateMainMenu::update(double deltaTime)
{
	//skeleton->update(static_cast<float>(deltaTime));
}
void GameStateMainMenu::getInput(double deltaTime)
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

				//resize the view
				view_.setSize(static_cast<float>(latestEvent_.size.width), static_cast<float>(latestEvent_.size.height));
				//resize the background along with the resized window
				//pin background to window center
				
				//background_.setPosition(sf::Vector2f(0.0, 0.0));

				//now set background scale
				
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (latestEvent_.key.code == sf::Keyboard::Escape)
				{
					enterPlayState();
					//we destroy this instance after the above, so we must exit this loop to avoid referencing ourselves
					return; 
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


//
//-------Private Functions--------------
//

void GameStateMainMenu::enterPlayState()
{
	game_->swapState(new GameStatePlay(game_));
}