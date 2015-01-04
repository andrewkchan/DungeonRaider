#include "Actor.h"


void Actor::update(double frameTime)
{
	//todo: DO THIS!!!!!

	healthComponent_.update(frameTime); //update health and non-display stuff first
	//transformComponent_.update(frameTime); //we don't have an update function here yet
	stateComponent_.update(frameTime, this);
	animStateComponent_.update(frameTime, this);
	
	

}
void Actor::setAnimStateComponent(const AnimStateComponent& animStateComponent)
{
	animStateComponent_ = animStateComponent;
}
void Actor::setStateComponent(const StateComponent& stateComponent)
{
	stateComponent_ = stateComponent;
}
void Actor::setHealthComponent(const HealthComponent& healthComponent)
{
	healthComponent_ = healthComponent;
}
void Actor::setTransformComponent(const TransformComponent& transformComponent)
{
	transformComponent_ = transformComponent;
}


Actor& Actor::operator=(const Actor& srcActor)
{
	//check for self-assignment
	if (this == &srcActor)
	{
		return *this;
	}

	animStateComponent_ = srcActor.animStateComponent_;
	stateComponent_ = srcActor.stateComponent_;
	healthComponent_ = srcActor.healthComponent_;
	return *this;
}
