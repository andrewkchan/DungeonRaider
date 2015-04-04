#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "Component.h"
#include "Controller.h"
#include <SFML/System.hpp>

/*
class InputComponent

Abstract base class for classes that pass in player or AI input to their update() functions.
*/
class InputComponent : public Component
{
protected:
	
public:
	virtual void update(float frameTime, Actor& actor) {}
	virtual void update(float frameTime, Actor& actor, Controller& controller) = 0;
};





#endif