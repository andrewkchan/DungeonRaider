#include "PlayerController.h"
#include "GraphicsWrappers\Window.h"
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

	
}
void PlayerController::update(float frameTime)
{
	
}
void PlayerController::drawGUIToWindow(gWrap::Window& window)
{
	
}