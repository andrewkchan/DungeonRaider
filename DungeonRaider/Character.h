#ifndef CHARACTER_H
#define CHARACTER_H

#include "Actor.h"
#include "EVector3.h"
#include "Attributes.h"
#include "PhysicalState.h"

//forward declarations of dependencies
//class Command;
class Controller;


class Character : Actor
{
	/*
	Class Character

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Actor, which inherits from Entity.
	
	
	*/
protected:
	const Attributes* attributes; //intrinsic physical attributes, ex: max movement speed
	PhysicalState physicalState; //mutable physical characteristics for each Character instance

	Controller* controller; //note: controller and Character both contain pointers to each other

public:
	
	Character() : attributes(0), controller(0)
	{}; //default constructor;
	Character(const Attributes* inputAttributes, EVector3 inputPos = EVector3()) :
		attributes(inputAttributes), controller(0)
	{
		//constructor with attributes param
		physicalState.health = attributes->maxHealth;
	}
	Character(const Character& Character) //copy constructor
	{
		attributes = Character.attributes;
		physicalState = Character.physicalState;
		controller = Character.controller;
	}
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
		physicalState = Character.physicalState; //uses implicit copy-constructor
		controller = Character.controller;
	}
	const PhysicalState& getPhysicalState() { return physicalState; }
	const Attributes& getAttributes() { return *(attributes); }

	//functions to change protected stuff
	void addVelocity(EVector3 inputVelocity);
	void addHealth(int inputHealth);
	void changePos(EVector3 inputPos);
	void changeIsPoisoned(bool inputIsPoisoned);

	//tick function
	void update(double frameTime); //todo: make this



	friend class Controller;
};




#endif