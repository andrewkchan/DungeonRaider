#ifndef COMMAND_H
#define COMMAND_H

//#include "Aligned16.h"

//fwd declarations
class Character;

class Command// : public Aligned16
{
	/*
	Class Command

	This class describes a command that is then interpreted by an Character.
	
	
	*/
private:
public:
	Command(){}
	virtual ~Command(){};
	virtual void execute(Character& character) = 0;
};


#endif