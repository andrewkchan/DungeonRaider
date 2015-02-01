#include "Actor.h"


void Actor::update(float frameTime)
{
	for (unsigned int i = 0; i < otherComponents.size(); i++)
	{
		otherComponents[i]->update(frameTime, *this);
	}
	//note: must update ALL other components before drawables, so separate for loops
	for (unsigned int i = 0; i < drawableComponents.size(); i++)
	{
		drawableComponents[i]->update(frameTime, *this);
	}
	

}
void Actor::addOtherComponent(Component* component)
{
	otherComponents.push_back(component);
}
void Actor::addDrawableComponent(DrawableComponent* component)
{
	drawableComponents.push_back(component);
}

Actor::Actor(const Actor& srcActor)
{
	drawableComponents = srcActor.drawableComponents;
	otherComponents = srcActor.otherComponents;
}
Actor& Actor::operator=(const Actor& srcActor)
{
	//check for self-assignment
	if (this == &srcActor)
	{
		return *this;
	}
	drawableComponents = srcActor.drawableComponents;
	otherComponents = srcActor.otherComponents;
	
	return *this;
}
