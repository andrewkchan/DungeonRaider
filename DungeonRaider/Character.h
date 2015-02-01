#ifndef CHARACTER_H
#define CHARACTER_H

#include "Actor.h"
#include "EVector3.h"
#include "Attributes.h"
#include "PhysicalState.h"
#include "Controller.h"

//forward declarations of dependencies
//class Command;
class Controller;


class Character : public Actor
{
	/*
	Class Character

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Actor, which inherits from Entity.
	
	
	*/
protected:
	const Attributes* attributes; //intrinsic physical attributes, ex: max movement speed (shared object)
	//TODO: add a smart pointer/deleter for Attributes?

	Controller* controller; //note: controller and Character both contain pointers to each other

public:
	
	Character() : attributes(0), controller(0)
	{}; //default constructor;
	/*
	Copy-constructor
	Note: This is called often when CharacterManager expands, since it must reallocate Character objects to new memory
	*/
	Character(const Character& Character)
	{
		attributes = Character.attributes;
		controller = Character.controller;
		
		//repoint the controller at this character, since most likely the old character will be destroyed
		controller->linkCharacter(this); 
	}
	/*
	Character constructor with params to set the components by value.
	*/
	Character(const Attributes* inputAttributes)
		:
		attributes(inputAttributes)
	{}
	virtual ~Character()
	{
		//destructor
		attributes = 0; //do NOT delete attributes, it's meant to be 1 static struct shared between Characters
		controller = 0; //leave the game to deal with the controller
	}

	void operator=(const Character& Character) //assignment overload
	{
		//check for self-assignment
		if (&Character == this)
		{
			return;
		}

		attributes = Character.attributes;
		controller = Character.controller;
	}
	const Attributes& getAttributes() { return *(attributes); }

	//tick function
	virtual void update(float frameTime); //todo: make this



	friend class Controller;
};




#endif