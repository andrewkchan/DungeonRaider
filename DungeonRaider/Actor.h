#ifndef ACTOR_H
#define ACTOR_H

//fwd declarations
class StateComponent;
class AnimStateComponent;

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define GLM_FORCE_PURE //this stops "Error C2719" alignment errors with GLM Matrices on 32-bit systems
						//the above error should be fixed by GLM 9.6.1
#include "PhysicalState.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "StateComponent.h"
#include "AnimStateComponent.h"
#include "HealthComponent.h"
#include "TransformComponent.h"



class Actor : public Entity
{
	/*
	Class Actor

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Entity.
	
	*/
protected:
	
	
public:
	//public composition of components...
	//these components individually still have private members, so encapsulation is not broken
	//----------------------------
	StateComponent stateComponent_;
	AnimStateComponent animStateComponent_;
	HealthComponent healthComponent_;
	TransformComponent transformComponent_;
	//----------------------------

	/*
	Default constructor, creates default (empty) animStateComponent, stateComponent,
	and a healthComponent with starting health of 1 and invulnerability on.
	*/
	Actor(glm::vec4 inputPos = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) 
		: 
		Entity(), animStateComponent_(), stateComponent_(), healthComponent_(), transformComponent_(inputPos)
	{}
	/*
	Actor constructor with params to set the components by value.
	*/
	Actor(AnimStateComponent animStateComponent, HealthComponent healthComponent = HealthComponent(), 
		StateComponent stateComponent = StateComponent(), TransformComponent transformComponent = TransformComponent())
		:
		Entity(), animStateComponent_(animStateComponent), healthComponent_(healthComponent),
		stateComponent_(stateComponent), transformComponent_(transformComponent)
	{}

	/*
	Copy constructor
	Note: This is often called when ActorManager pushes a new Actor on, since it must resize its container of actors
	*/
	Actor(const Actor& srcActor);
	virtual ~Actor() 
	{} //destructor

	virtual void setAnimStateComponent(const AnimStateComponent& animStateComponent);
	virtual void setStateComponent(const StateComponent& stateComponent);
	virtual void setHealthComponent(const HealthComponent& healthComponent);
	virtual void setTransformComponent(const TransformComponent& transformComponent);

	virtual void update(double frameTime); //tick function
	//todo: DO TICK FUNCTION!!!

	Actor& operator=(const Actor& srcActor);
};





#endif