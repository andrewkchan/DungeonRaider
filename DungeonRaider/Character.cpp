#include "Character.h"


void Character::update(float frameTime)
{
	//note: order matters!!
	physicsComponent.update(frameTime, *this); //will probably modify the transform component, which is part of Actor.
	Actor::update(frameTime); //will potentially modify other components.
	healthComponent.update(frameTime, *this);
}