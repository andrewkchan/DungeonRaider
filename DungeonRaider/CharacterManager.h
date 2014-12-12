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
	Character* CharacterArray; //an array of the Characters managed by this class
	int numCharacters; //the number of Characters managed by this class
	int CharacterArrayLength; //length of CharacterArray (NOTE: should be greater than numCharacters, so empty elements in the array)

	Attributes skeletonAttributes;
	Character* skeletonPrototype;

public:
	CharacterManager()
	{
		//default constructor
		CharacterArray = new Character[4]; //by default, get enough size for 4 Characters in the array
		CharacterArrayLength = 4; 
		numCharacters = 0;


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
		delete[] CharacterArray;
		CharacterArray = 0;
		delete skeletonPrototype;
		skeletonPrototype = 0;
	}

	void instantiateSkeleton();
	void pushCharacter(Character newCharacter);
	void update(double frameTime); //update all Characters in the current frame
	void draw(); //draw all Characters in the current frame
	int getNumCharacters() { return numCharacters; }
};





#endif