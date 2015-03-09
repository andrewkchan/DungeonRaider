#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include "Tracked.h"
#include "Tracker.h"
#include <SFML/Graphics.hpp>

//fwd declarations
class GUIEntity;

/*
class GUIComponent

The virtual base class for all GUIEntity Components.
*/
class GUIComponent : public Tracked, public Tracker
{
protected:
	GUIComponent(){}
public:
	virtual void update(float frameTime, GUIEntity& entity) = 0;
	virtual ~GUIComponent(){}

	virtual sf::Drawable& onDraw() = 0;
};





#endif