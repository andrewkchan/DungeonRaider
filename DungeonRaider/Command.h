#ifndef COMMAND_H
#define COMMAND_H

//fwd declarations
class Actor;

class Command
{
	/*
	Class Command

	This class describes a command that is then interpreted by an Character.
	
	
	*/
private:
public:
	virtual ~Command(){};
	virtual void execute(Actor& actor) = 0;
};


#endif