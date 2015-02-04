#ifndef COMPONENT_H
#define COMPONENT_H


//fwd declarations of dependencies
class Actor;

/*
Class Component

This class is the pure virtual base class for all actor components.
*/
class Component
{
	/*
	Class Component

	This class is the pure virtual base class for all actor components.
	*/

protected:
	Component() {} //default constructor, protected so that people can't directly instantiate Components

public:
	virtual void update(float frameTime, Actor& actor) = 0;
	virtual ~Component() {}
};




#endif