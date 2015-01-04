
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.h"


/*
Dungeon Raider, an isometric 2D procedurally generated action-RPG.

*/

/*
int main(int argc, char* args[])
{
	
	bool bRunGame = true;
	sf::Clock clock;
	sf::Time deltaTime = clock.getElapsedTime(); //the total amount of time elapsed since last clock measurement
	//const double DT = 0.01; //constant time-step with which to update physics (seconds)
	

	GameState game;
	game.init();
	while (bRunGame)
	{
		deltaTime = clock.restart(); //gets the time for the previous frame to render. Also restarts the clock to zero.

		game.getInput(clock.getElapsedTime().asSeconds());
		game.update(deltaTime.asSeconds());
		game.draw();
	}
	game.close();

	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cin.get();
	
	return 0;
}*/



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
