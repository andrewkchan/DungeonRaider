#ifndef CHARACTER_H
#define CHARACTER_H

#include "Actor.h"
#include "HealthComponent.h"
#include "PhysicsComponent.h"
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
	Controller* controller; //note: controller and Character both contain pointers to each other
	HealthComponent healthComponent;
	PhysicsComponent physicsComponent;
public:
	
	Character() : controller(0)
	{}; //default constructor;
	/*
	Copy-constructor
	Note: This is called often when CharacterManager expands, since it must reallocate Character objects to new memory
	*/
	Character(const Character& character) : 
		Actor(character),
		controller(character.controller), 
		healthComponent(character.healthComponent),
		physicsComponent(character.physicsComponent)
	{
		//repoint the controller at this character, since most likely the old character will be destroyed
		controller->linkCharacter(this); 
	}


	virtual ~Character()
	{
		controller = 0; //leave the game to deal with the controller
	}

	void operator=(const Character& character) //assignment overload
	{
		//check for self-assignment
		if (&character == this)
		{
			return;
		}

		Actor::operator=(character);
		controller = character.controller;
		healthComponent = character.healthComponent;
		physicsComponent = character.physicsComponent;
	}

	//tick function
	virtual void update(float frameTime);
	/*
	Gets the Character's central health component
	*/
	virtual HealthComponent& getHealthComponent() { return healthComponent; }
	/*
	Gets the Character's central physics component
	*/
	virtual PhysicsComponent& getPhysicsComponent() { return physicsComponent; }


	friend class Controller;
};




#endif