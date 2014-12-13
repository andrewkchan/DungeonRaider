#ifndef ACTOR_H
#define ACTOR_H

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define GLM_FORCE_PURE //this stops "Error C2719" alignment errors with GLM Matrices on 32-bit systems
						//the above error should be fixed by GLM 9.6.1
#include <glm.hpp>
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
	glm::vec4 position; //4x1 position matrix (or 4-vector)
public:
	Actor() : Entity(), position(0.0f,0.0f,0.0f,0.0f)
	{} //default constructor
	virtual ~Actor() 
	{} //destructor

	virtual void update(double frameTime); //tick function
	//todo: DO TICK FUNCTION!!!
};





#endif