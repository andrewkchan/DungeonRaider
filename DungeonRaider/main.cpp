#include "Game.h"
#include "GameStateMainMenu.h"


/*
Dungeon Raider, an isometric 2D procedurally generated action-RPG.

*/


int main(int argc, char* args[])
{
	Game game;
	game.pushState(new GameStateMainMenu(&game));
	game.runGameLoop();

	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cin.get();
	
	return 0;
}



/*int main()
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
}*/
