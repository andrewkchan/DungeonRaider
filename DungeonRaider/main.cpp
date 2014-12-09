
#include "GameState.h"


/*
Dungeon Raider, a 2D procedurally generated action-RPG.

*/

/*
int main(int argc, char* args[])
{
	bool bRunGame = true;
	//const double DT = 0.01; //constant time-step with which to update physics (seconds)
	double frameTime = 0.0; //time between frames (seconds)
	unsigned int prev_frame_tick; //MILLISECONDS passed between last frame and game start
	unsigned int curr_frame_tick = 0; //MILLISECONDS passed since game start

	

	GameState game;
	game.init();
	while (bRunGame)
	{
		prev_frame_tick = curr_frame_tick;
		curr_frame_tick = 0;
		frameTime = (curr_frame_tick - prev_frame_tick) / 1000.0;

		game.getInput(curr_frame_tick);
		game.update(frameTime);
		game.draw();
	}
	game.close();

	return 0;
}
*/




#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}