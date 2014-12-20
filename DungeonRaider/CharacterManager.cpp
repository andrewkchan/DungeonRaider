#include "CharacterManager.h"

void CharacterManager::pushCharacter(Character newCharacter)
{
	characters.push_back(newCharacter);
}
void CharacterManager::instantiateSkeleton()
{
	pushCharacter(*skeletonPrototype);
}
void CharacterManager::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i].animStateComponent.onDraw();
	}
}
void CharacterManager::update(double frameTime)
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		characters[i].update(frameTime);
	}
}