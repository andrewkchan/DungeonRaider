#ifndef ENTITY_H
#define ENTITY_H

#include "EVector2.h"


class Entity
{
	/*
	Class Entity

	This class describes all objects in the game, including everything from GUI buttons to enemies
	to invisible triggers.

	All entities have:
	1. The ability to announce entity-specific events
	2. A unique ID, and an accessor for it

	All ingame objects should inherit from Entity.

	*/
protected:
	int _ID; //unique ID
public:
	static int s_nextID; //static ID generator
	Entity() : _ID(++s_nextID)
	{
		//default constructor
	}
	Entity(const Entity& entity) : _ID(entity._ID) {}
	virtual ~Entity() {}; //destructor
	int getID() { return _ID; }; //accessor for unique ID

	virtual void update(float frameTime) = 0;

	Entity& operator=(const Entity& entity)
	{
		if (&entity == this)
		{
			return *this;
		}

		_ID = entity._ID;
		return *this;
	}
};




#endif