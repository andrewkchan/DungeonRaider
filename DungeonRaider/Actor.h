#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define GLM_FORCE_PURE //this stops "Error C2719" alignment errors with GLM Matrices on 32-bit systems
						//the above error should be fixed by GLM 9.6.1
#include "PhysicalState.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>



class Actor : Entity
{
	/*
	Class Actor

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Entity.
	
	*/
protected:
	PhysicalState physicalState; //mutable physical characteristics for each Actor instance
	
public:
	Actor(glm::vec4 inputPos = glm::vec4(0.0f,0.0f,0.0f,0.0f)) : Entity(), physicalState(0, inputPos)
	{} //default constructor

	/*
	Copy constructor
	Note: This is often called when ActorManager pushes a new Actor on, since it must resize its container of actors
	*/
	Actor(const Actor& srcActor) : Entity(), physicalState(srcActor.physicalState) {}
	virtual ~Actor() 
	{} //destructor

	virtual void transformPos(glm::mat4 transform);
	virtual void transformVelocity(glm::mat4 transform);

	virtual void update(double frameTime); //tick function
	//todo: DO TICK FUNCTION!!!

	Actor& operator=(const Actor& srcActor);
};





#endif