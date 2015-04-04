#ifndef HEALTHCOMPONENT_H
#define HEALTHCOMPONENT_H

#include "Component.h"

/*
Class HealthComponent

This class manages character health. It takes care of taking damage for the character, adding health,
setting health, determining if the character should be dead or not, and determing whether the character's
health exceeds max health and all that stuff.
*/
class HealthComponent : public Component
{
	
private:
	int maxHealth_;
	int health_;
	bool isAlive_;
	bool isInvulnerable_;
public:
	HealthComponent(int maxHealth = 1) : maxHealth_(maxHealth), health_(maxHealth), isInvulnerable_(true)
	{}
	HealthComponent(int maxHealth, int health, bool isInvulnerable = false) : maxHealth_(maxHealth), health_(health),
		isInvulnerable_(isInvulnerable)
	{}
	HealthComponent(const HealthComponent& healthComponent)
	{
		maxHealth_ = healthComponent.maxHealth_;
		health_ = healthComponent.health_;
		isInvulnerable_ = healthComponent.isInvulnerable_;
		isAlive_ = healthComponent.isAlive_;
	}

	void takeDamage(int damage)
		//inline for now... if this gets too big, take it out!
	{
		if (!isInvulnerable_)
			health_ -= damage;
	}
	virtual void update(float frameTime, Actor& actor);
	void setIsInvulnerable(bool isInvulnerable)
	{
		isInvulnerable_ = isInvulnerable;
	}
	bool isInvulnerable()
	{
		return isInvulnerable_;
	}
	bool isAlive()
	{
		return isAlive_;
	}

	HealthComponent& operator=(const HealthComponent& healthComponent);
};


#endif