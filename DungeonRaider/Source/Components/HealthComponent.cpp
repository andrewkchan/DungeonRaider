#include "Components\HealthComponent.h"

void HealthComponent::update(float frameTime, Actor& actor)
{
	if (health_ <= 0) //note: invulnerable things can still die
	{
		isAlive_ = false;
	}
}
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