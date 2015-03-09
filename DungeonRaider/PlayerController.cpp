#include "PlayerController.h"
#include <SFML/Window.hpp>
#include <iostream>
#include "FloatValueDisplayText.h"
#include "Character.h"

void PlayerController::handleInput()
{
	//std::cout << "pc handling input" << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		inputLeft->execute(*character_);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		inputRight->execute(*character_);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		inputUp->execute(*character_);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		inputDown->execute(*character_);
	}
	
}
void PlayerController::linkCharacter(Character* inputCharacter)
{
	Controller::linkCharacter(inputCharacter);

	for (unsigned int i = 0; i < coordinateDisplay->getNumComponents(); i++)
	{
		(coordinateDisplay->getComponentAt(i))->setNewSubject(&inputCharacter->getTransform());
	}
}
void PlayerController::update(float frameTime)
{
	coordinateDisplay->update(frameTime);
}
void PlayerController::drawGUIToWindow(sf::RenderWindow& window)
{
	coordinateDisplay->drawToWindow(window);
}