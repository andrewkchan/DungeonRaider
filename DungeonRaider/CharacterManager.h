#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H


#include "Character.h"
#include "GameState.h"

class CharacterManager
{
	/*
	Class CharacterManager
	
	This class handles rendering and updating of a huge array of Characters. 
	This class is also a huge hack for now.
	
	Only 1 instance of this class should exist at a time.
	*/
private:
	std::vector<Character> characters;

	Attributes skeletonAttributes;
	Character* skeletonPrototype;

public:
	CharacterManager()
	{
		//default constructor

		//initialize/define prototypes
		
		skeletonAttributes.canBreatheUnderwater = true;
		skeletonAttributes.isPoisonImmune = true;
		skeletonAttributes.maxHealth = 100;
		skeletonAttributes.maxJumpSpeed = 0.0;
		skeletonAttributes.maxMoveSpeed = 2.0;
		skeletonAttributes.maxQuickMoveSpeed = 3.0;
		skeletonPrototype = new Character(&skeletonAttributes);
	}
	~CharacterManager()
	{
		//destructor
		characters.clear();
		delete skeletonPrototype;
		skeletonPrototype = 0;
	}

	void instantiateSkeleton();
	void pushCharacter(Character newCharacter);
	void update(double frameTime); //update all Characters in the current frame
	void draw(sf::RenderWindow& window); //draw all Characters in the current frame
	int getNumCharacters() { return characters.size(); }
};





#endif