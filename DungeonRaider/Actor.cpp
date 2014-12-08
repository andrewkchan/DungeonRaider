#include "Actor.h"


void Actor::changeIsPoisoned(bool inputIsPoisoned)
{
	physicalState.isPoisoned = inputIsPoisoned;
}
void Actor::changePos(Vector3 inputPos)
{
	physicalState.pos = inputPos;
}
void Actor::addHealth(int inputHealth)
{
	physicalState.health += inputHealth;
}
void Actor::addVelocity(Vector3 inputVelocity)
{
	physicalState.velocity += inputVelocity;
}

void Actor::update(double frameTime)
{
	//todo: make this!
}