#ifndef ZWORLD_H
#define ZWORLD_H

#include "World.h"


/*
class ZWorld

A World that allows for movement and position defined across the Z (vertical) axis as well as across the X and Y axes.
*/
class ZWorld : public World
{
private:
public:
	ZWorld(float orthoAngleX = 26.5f, float orthoAngleY = 26.5f) :
		World(orthoAngleX, orthoAngleY)
	{
		
	}

};





#endif