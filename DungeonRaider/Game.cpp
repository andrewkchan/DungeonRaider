#include "Game.h"
#include "GameState.h"

Game::Game() :
SCREEN_HEIGHT(480), SCREEN_WIDTH(640), verticalSyncEnabled(false), bRunGame(true)
{
	//default constructor
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dungeon Raider");
	if (verticalSyncEnabled)
	{
		window.setVerticalSyncEnabled(true);
	}
	window.setFramerateLimit(120);

	loadSharedTextures();
}
Game::~Game()
{
	while (!states.empty())
	{
		states.pop();
	}
}

void Game::popState()
{
	delete states.top(); //delete the pointer for the top GameState
	states.pop(); //now remove the deleted pointer from the stack
}
void Game::pushState(GameState* state)
{
	states.push(state);
}
void Game::swapState(GameState* state)
{
	if (!states.empty())
	{
		popState();
	}
	pushState(state);
}
GameState* Game::peekState()
{
	if (!states.empty())
	{
		return states.top();
	}
	return 0;
}

void Game::runGameLoop()
{
	sf::Clock clock;
	double deltaTime = clock.getElapsedTime().asSeconds(); //amount of time elapsed since last clock measurement

	while (bRunGame)
	{
		deltaTime = clock.restart().asSeconds(); //gets time for previous frame to render and sets clock to zero again
		if (peekState() != 0)
		{
			peekState()->getInput(deltaTime);
			peekState()->update(deltaTime);
			//clears buffer of previous frame
			window.clear(sf::Color::Black);
			//draw current frame
			peekState()->draw();
			//bring image from back to front buffer
			window.display();
		}
	}
}
void Game::closeGame()
{
	bRunGame = false;
	window.close();
	exit(0);
}

//
//Private functions-------------------------------------------------------
//

void Game::loadSharedTextures()
{
	sharedTextures_.loadTexture("background", "Textures/background.png");
}
