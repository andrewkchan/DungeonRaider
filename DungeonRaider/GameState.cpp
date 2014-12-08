#include "GameState.h"

void GameState::loadMedia()
{
	actorManager = new ActorManager();

}

void GameState::init()
{

	//done loading fundamental rendering stuff, now load gameplay logic and media
	loadMedia();
}

void GameState::close()
{

	std::cout << "Closing game" << std::endl;
	exit(0); //exit game!

	
}

void GameState::getInput(unsigned int curr_frame_time)
{
	//get the latest keystates
	//pass keystates to Controler


}

void GameState::update(double frameTime)
{

}

void GameState::draw()
{



	//bring image from back to front buffer
}