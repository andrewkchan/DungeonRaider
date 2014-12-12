#include "CharacterManager.h"

void CharacterManager::pushCharacter(Character newCharacter)
{
	++numCharacters;
	if (numCharacters >= CharacterArrayLength)
	{
		//if we need to increase the size of the array...

		//create a temporary array to hold the elements of the old array
		Character* tempCharacterArray = new Character[CharacterArrayLength];
		for (int i = 0; i < CharacterArrayLength; i++)
		{
			tempCharacterArray[i] = CharacterArray[i];
		}

		//delete the old array's elements
		delete[] CharacterArray;

		//increase the size of the new array by 5
		CharacterArrayLength += 5;
		CharacterArray = new Character[CharacterArrayLength];
		
		//copy all old elements back into the new array
		for (int i = 0; i < (CharacterArrayLength - 5); i++)
		{
			CharacterArray[i] = tempCharacterArray[i];
		}

		//FINALLY, add in the new Character element
		CharacterArray[numCharacters - 1] = newCharacter;
	}
	else
	{
		CharacterArray[numCharacters - 1] = newCharacter;
	}
}
void CharacterManager::instantiateSkeleton()
{
	pushCharacter(*skeletonPrototype);
}
void CharacterManager::draw()
{

}
void CharacterManager::update(double frameTime)
{
	for (int i = 0; i < numCharacters; i++)
	{
		CharacterArray[i].update(frameTime);
	}
}