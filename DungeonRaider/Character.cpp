#include "Character.h"


void Character::changeIsPoisoned(bool inputIsPoisoned)
{
	physicalState.isPoisoned = inputIsPoisoned;
}
void Character::changePos(EVector3 inputPos)
{
	physicalState.pos = inputPos;
}
void Character::addHealth(int inputHealth)
{
	physicalState.health += inputHealth;
}
void Character::addVelocity(EVector3 inputVelocity)
{
	physicalState.velocity += inputVelocity;
}

void Character::update(double frameTime)
{
	//todo: make this!
}