#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H

#include <SFML/Graphics.hpp>
#include "Component.h"


/*
class DrawableComponent

A pure virtual base class for all components that are meant to be drawn every frame.
*/
class DrawableComponent : public Component
{
protected:
	DrawableComponent() {}
public:
	//we don't have to redefine void update(Actor& actor), because we're also an abstract class

	virtual sf::Drawable& onDraw() = 0;
	virtual ~DrawableComponent(){}
};







#endif