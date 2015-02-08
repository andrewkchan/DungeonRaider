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
public:
	CharacterManager()
	{
		//default constructor		
	}
	~CharacterManager()
	{
		//destructor
		characters.clear();
	}

	void instantiateSkeleton();
	void pushCharacter(Character newCharacter);
	void update(float frameTime); //update all Characters in the current frame
	void draw(sf::RenderWindow& window); //draw all Characters in the current frame
	int getNumCharacters() { return characters.size(); }
};





#endif