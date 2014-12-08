#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H


#include "Command.h"

class JumpCommand : Command
{
	/*
	Class JumpCommand

	This command moves up momentarily.

	*/
private:
public:
	JumpCommand()
	{
		//default constructor
	}
	~JumpCommand(){} //destructor

	virtual void execute(Actor& actor);

};


#endif