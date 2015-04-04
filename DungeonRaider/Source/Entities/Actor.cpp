#include "Entities\Actor.h"
#include "GraphicsWrappers\Window.h"


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
	transformComponent.update(frameTime, *this);

}
void Actor::addOtherComponent(Component* component)
{
	otherComponents.push_back(component);
}
void Actor::addDrawableComponent(DrawableComponent* component)
{
	drawableComponents.push_back(component);
}

void Actor::drawToWindow(gWrap::Window& window)
{
	for (unsigned int i = 0; i < drawableComponents.size(); i++)
	{
//		window.drawDT(drawableComponents[i]->onDraw(), transformComponent.get2DTransform());
	}
}
Component* Actor::getOtherComponentAt(unsigned int index)
{
	if (index >= otherComponents.size())
	{
		return 0;
	}
	else
	{
		return otherComponents[index];
	}
}
DrawableComponent* Actor::getDrawableComponentAt(unsigned int index)
{
	if (index >= drawableComponents.size())
	{
		return 0;
	}
	else
	{
		return drawableComponents[index];
	}
}

//====================================================================================
//					Constructors and Operators
//====================================================================================

Actor::Actor(const Actor& srcActor) : Entity(srcActor)
{
	drawableComponents = srcActor.drawableComponents;
	otherComponents = srcActor.otherComponents;
	transformComponent = srcActor.transformComponent;
}
Actor::~Actor()
{
	for (unsigned int i = 0; i < drawableComponents.size(); i++)
	{
		delete drawableComponents[i];
	}
	for (unsigned int i = 0; i < otherComponents.size(); i++)
	{
		delete otherComponents[i];
	}
}
Actor& Actor::operator=(const Actor& srcActor)
{
	//check for self-assignment
	if (this == &srcActor)
	{
		return *this;
	}
	Entity::operator=(srcActor);
	drawableComponents = srcActor.drawableComponents;
	otherComponents = srcActor.otherComponents;
	transformComponent = srcActor.transformComponent;
	
	return *this;
}
