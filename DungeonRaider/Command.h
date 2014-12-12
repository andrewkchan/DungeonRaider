#ifndef COMMAND_H
#define COMMAND_H

#include "Character.h"


class Command
{
	/*
	Class Command

	This class describes a command that is then interpreted by an Character.
	
	
	*/
private:
public:
	virtual ~Command(){};
	virtual void execute(Character& Character) = 0;
};


#endif