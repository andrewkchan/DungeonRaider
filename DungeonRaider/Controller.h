#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Actor.h"

class Controller
{
	/*
	Class Controller

	This class defines the framework for handling input and passing that input to an actor.
	Controllers can be thought of as the "brain" of an actor. Whereas the actor defines
	all the physical properties of something, the controller defines how commands change or use
	those physical properties.

	A controller can "possess" one actor at a time in order to control it, and can also "unpossess"
	that actor.

	Controllers do not have to handle human input; they can also serve as the framework for AI commands
	to an actor.
	
	*/
protected:
	Actor* _actor;
public:
	Controller() : _actor(0)
	{
		//default constructor
	}
	virtual ~Controller()
	{
		//destructor
		_actor = 0; //do NOT delete the actor, leave the game to deal with it
	}
	void linkActor(Actor* inputActor); //possess an actor
	void unlinkActor(); //un-possess an actor
	
	virtual void handleInput();
};




#endif