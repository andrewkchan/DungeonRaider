#ifndef MOVELEFTCOMMAND_H
#define MOVELEFTCOMMAND_H


#include "Command.h"

class MoveLeftCommand : Command
{
	/*
	Class MoveLeftCommand

	This command moves the selected actor left.

	*/
private:
public:
	MoveLeftCommand()
	{
		//default constructor
	}
	~MoveLeftCommand(){} //destructor

	virtual void execute(Actor& actor);

};


#endif