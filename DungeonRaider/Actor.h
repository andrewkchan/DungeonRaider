#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"
#include "EVector3.h"
#include "Attributes.h"
#include "PhysicalState.h"

//forward declarations of dependencies
//class Command;
class Controller;


class Actor : Entity
{
	/*
	Class Actor

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Entity.
	
	
	*/
protected:
	const Attributes* attributes; //intrinsic physical attributes, ex: max movement speed
	PhysicalState physicalState; //mutable physical characteristics for each actor instance

	Controller* controller; //note: controller and actor both contain pointers to each other

public:
	
	Actor() : attributes(0), controller(0)
	{}; //default constructor;
	Actor(const Attributes* inputAttributes, EVector3 inputPos = EVector3()) :
		attributes(inputAttributes), controller(0)
	{
		//constructor with attributes param
		physicalState.health = attributes->maxHealth;
	}
	Actor(const Actor& actor) //copy constructor
	{
		attributes = actor.attributes;
		physicalState = actor.physicalState;
		controller = actor.controller;
	}
	virtual ~Actor()
	{
		//destructor
		attributes = 0; //do NOT delete attributes, it's meant to be 1 static struct shared between actors
		controller = 0; //leave the game to deal with the controller
	}

	void operator=(const Actor& actor) //assignment overload
	{
		//check for self-assignment
		if (&actor == this)
		{
			return;
		}

		attributes = actor.attributes;
		physicalState = actor.physicalState; //uses implicit copy-constructor
		controller = actor.controller;
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