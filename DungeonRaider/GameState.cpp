#include "GameState.h"

void GameState::loadMedia()
{
	actorManager = new ActorManager();

}

void GameState::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		//initialize all SDL subsystems, should return 0 if everything goes great
	{
		std::cout << "SDL_init error:" << SDL_GetError() << std::endl;
	}

	//open the game window
	window = SDL_CreateWindow("Dungeon Raider", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == 0)
	{
		std::cout << "SDL_CreateWindow error:" << SDL_GetError() << std::endl;
		close(); //close the game if anything goes wrong!
	}
	//create a game renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == 0)
	{
		std::cout << "SDL_CreateRenderer error:" << SDL_GetError() << std::endl;
		close();
	}

	//done loading fundamental rendering stuff, now load gameplay logic and media
	loadMedia();
}

void GameState::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = 0;
	window = 0;
	SDL_Quit();
	std::cout << "Closing game" << std::endl;
	exit(0); //exit game!

	
}

void GameState::getInput(Uint32 curr_frame_time)
{
	while (SDL_PollEvent(&latestEvent) != 0) //put the latest input event in latestEvent
	{
		//check if the user wants to quit
		if (latestEvent.type == SDL_QUIT)
		{
			close();
		}
	}
	//pass keystates to Controler


}

void GameState::update(double frameTime)
{

}

void GameState::draw()
{



	SDL_RenderPresent(renderer);
}