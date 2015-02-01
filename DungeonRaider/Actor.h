#ifndef ACTOR_H
#define ACTOR_H


#include "Entity.h"
#include "Component.h"
#include "DrawableComponent.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define GLM_FORCE_PURE //this stops "Error C2719" alignment errors with GLM Matrices on 32-bit systems
						//the above error should be fixed by GLM 9.6.1
#include "PhysicalState.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>




class Actor : public Entity
{
	/*
	Class Actor

	This class represents everything that has a real, ingame position in ingame space.
	It inherits from Entity.
	
	*/
protected:
	//----------------------------
	std::vector<Component*>otherComponents; //all components without guaranteed onDraw() function
	std::vector<DrawableComponent*>drawableComponents; //all components WITH guaranteed onDraw() function
	//----------------------------
public:
	/*
	Default constructor, creates default (empty) component list.
	*/
	Actor(glm::vec4 inputPos = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)) 
		: 
		Entity()
	{}

	/*
	Copy constructor
	Note: This is often called when ActorManager pushes a new Actor on, since it must resize its container of actors
	*/
	Actor(const Actor& srcActor);
	virtual ~Actor() 
	{} //destructor

	virtual void update(float frameTime); //tick function
	virtual void addOtherComponent(Component* component);
	virtual void addDrawableComponent(DrawableComponent* component);

	Actor& operator=(const Actor& srcActor);
};





#endif