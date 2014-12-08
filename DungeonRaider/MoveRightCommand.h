#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H


#include "Command.h"

class MoveRightCommand : Command
{
	/*
	Class MoveRightCommand

	This command moves the selected actor left.

	*/
private:
public:
	MoveRightCommand()
	{
		//default constructor
	}
	~MoveRightCommand(){} //destructor

	virtual void execute(Actor& actor);

};


#endif