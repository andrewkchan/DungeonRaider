#include "CharacterManager.h"

void CharacterManager::pushCharacter(Character newCharacter)
{
	characters.push_back(newCharacter);
}
void CharacterManager::instantiateSkeleton()
{
	pushCharacter(*skeletonPrototype); //push a copy of the prototype onto the vector
}
void CharacterManager::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		window.draw(characters[i].animStateComponent_.onDraw());
	}
}
void CharacterManager::update(double frameTime)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i].update(frameTime);
	}
}