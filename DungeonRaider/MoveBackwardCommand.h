#ifndef MOVEBACKWARDCOMMAND_H
#define MOVEBACKWARDCOMMAND_H


#include "Command.h"

class MoveBackwardCommand : Command
{
	/*
	Class MoveBackwardCommand

	This command moves the selected actor backward.

	*/
private:
public:
	MoveBackwardCommand()
	{
		//default constructor
	}
	~MoveBackwardCommand(){} //destructor

	virtual void execute(Actor& actor);

};





#endif