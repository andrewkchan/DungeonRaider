#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H

#include <SFML\Graphics.hpp>
#include "Components\Component.h"

namespace gWrap
{
	class DrawableDT;
}

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

	virtual gWrap::DrawableDT& onDraw() = 0;
	virtual ~DrawableComponent(){}
};







#endif