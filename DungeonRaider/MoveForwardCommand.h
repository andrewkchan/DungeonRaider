#ifndef MOVEFORWARDCOMMAND_H
#define MOVEFORWARDCOMMAND_H


#include "Command.h"

class MoveForwardCommand : Command
{
	/*
	Class MoveForwardCommand

	This command moves the selected Character forward.
	
	*/
private:
public:
	MoveForwardCommand()
	{
		//default constructor
	}
	~MoveForwardCommand(){} //destructor

	virtual void execute(Character& Character);

};


#endif