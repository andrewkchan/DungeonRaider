#ifndef COMMAND_H
#define COMMAND_H

#include "Actor.h"


class Command
{
	/*
	Class Command

	This class describes a command that is then interpreted by an actor.
	
	
	*/
private:
public:
	virtual ~Command(){};
	virtual void execute(Actor& actor) = 0;
};


#endif