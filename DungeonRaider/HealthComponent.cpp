#include "HealthComponent.h"

HealthComponent& HealthComponent::operator=(const HealthComponent& healthComponent)
{
	//check self-assignment
	if (this == &healthComponent)
	{
		return *this;
	}

	maxHealth_ = healthComponent.maxHealth_;
	health_ = healthComponent.health_;
	isInvulnerable_ = healthComponent.isInvulnerable_;
	isAlive_ = healthComponent.isAlive_;

	return *this;
}