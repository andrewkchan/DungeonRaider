#include "CharacterManager.h"

void CharacterManager::pushCharacter(Character newCharacter)
{
	characters.push_back(newCharacter);
}
void CharacterManager::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		//todo
	}
}
void CharacterManager::update(float frameTime)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i].update(frameTime);
	}
}