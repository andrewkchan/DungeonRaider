#ifndef MOVEBACKWARDCOMMAND_H
#define MOVEBACKWARDCOMMAND_H


#include "Command.h"

class MoveBackwardCommand : Command
{
	/*
	Class MoveBackwardCommand

	This command moves the selected Character backward.

	*/
private:
public:
	MoveBackwardCommand()
	{
		//default constructor
	}
	~MoveBackwardCommand(){} //destructor

	virtual void execute(Character& Character);

};





#endif