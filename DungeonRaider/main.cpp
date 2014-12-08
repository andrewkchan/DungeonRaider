
#include "GameState.h"


/*
Dungeon Raider, a 2D procedurally generated action-RPG.

*/

int main(int argc, char* args[])
{
	bool bRunGame = true;
	//const double DT = 0.01; //constant time-step with which to update physics (seconds)
	double frameTime = 0.0; //time between frames (seconds)
	Uint32 prev_frame_tick; //MILLISECONDS passed between last frame and game start
	Uint32 curr_frame_tick = SDL_GetTicks(); //MILLISECONDS passed since game start

	

	GameState game;
	game.init();
	while (bRunGame)
	{
		prev_frame_tick = curr_frame_tick;
		curr_frame_tick = SDL_GetTicks();
		frameTime = (curr_frame_tick - prev_frame_tick) / 1000.0;

		game.getInput(curr_frame_tick);
		game.update(frameTime);
		game.draw();
	}
	game.close();

	return 0;
}