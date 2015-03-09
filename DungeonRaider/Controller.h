#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Entity.h"

//forward declaration of dependencies
class Character;

class Controller : public Entity
{
	/*
	Class Controller

	This class defines the framework for handling input and passing that input to an Character.
	Controllers can be thought of as the "brain" of an Character. Whereas the Character defines
	all the physical properties of something, the controller defines how commands change or use
	those physical properties.

	A controller can "possess" one Character at a time in order to control it, and can also "unpossess"
	that Character.

	Controllers do not have to handle human input; they can also serve as the framework for AI commands
	to an Character.
	
	*/
protected:
	Character* character_;
public:
	Controller() : character_(0)
	{
		//default constructor
	}
	Controller(const Controller& src) : Entity(src)
	{

	}
	virtual ~Controller()
	{
		//destructor
		character_ = 0; //do NOT delete the Character, leave the game to deal with it
	}
	virtual void linkCharacter(Character* inputCharacter); //possess an Character
	void unlinkCharacter(); //un-possess an Character
	
	virtual void handleInput(){}
	virtual void update(float frameTime){}
};




#endif