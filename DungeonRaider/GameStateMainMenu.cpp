#include "GameStateMainMenu.h"
#include <SFML/Graphics.hpp>

GameStateMainMenu::GameStateMainMenu(Game* game) : GameState(game)
{
	sf::Vector2f windowSize = sf::Vector2f(game_->window.getSize());
	view_.setSize(windowSize);
	view_.setCenter(0.5f * windowSize);
}
GameStateMainMenu::~GameStateMainMenu()
{}

void GameStateMainMenu::draw()
{
	game_->window.setView(view_);

	game_->window.draw(background_);
}
void GameStateMainMenu::update(double deltaTime)
{

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
				background_.setPosition(game_->window.mapPixelToCoords(sf::Vector2i(0, 0)));
				//background_.setPosition(sf::Vector2f(0.0, 0.0));

				//now set background scale
				/*background_.setScale(
					static_cast<float>(latestEvent_.size.width) / static_cast<float>(background_.getTexture()->getSize().x),
					static_cast<float>(latestEvent_.size.height) / static_cast<float>(background_.getTexture()->getSize().y)
					);*/
				break;
			}
			case sf::Event::KeyPressed:
			{
				//todo: something to do with the window if the user presses ESCAPE
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