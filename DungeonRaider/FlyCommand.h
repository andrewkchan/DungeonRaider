#ifndef FLYCOMMAND_H
#define FLYCOMMAND_H

//#include "Aligned16.h"
#include "Command.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>
#include <iostream>


/*
class FlyCommand

A command to move an actor in any given direction in 3-space.
*/
class FlyCommand : public Command//, public Aligned16
{
private:
	glm::vec4 dir; //the direction of movement
public:
	//params float x, float y, float z for the direction of movement
	FlyCommand(float x, float y, float z) : dir(x, y, z, 0.0f)
	{
//		std::cout << "dir.x:" << dir.x << " dir.y:" << dir.y << " dir.z:" << dir.z << std::endl;
//		std::cout << "sizeof(Command):" << sizeof(Command) 
//			<< ", sizeof(FlyCommand):" << sizeof(FlyCommand) 
//			<< ", currentAddress:" << this 
//			<< ", non-aligned bits:" << ( reinterpret_cast<const uintptr_t>(this) ^ (~(uintptr_t)(16)) ) 
//			<< std::endl;
	}
	//params glm::vec3(float x, float y, float z) for the direction of movement
	FlyCommand(glm::vec3 direction)
	{
		dir = glm::vec4(direction.x, direction.y, direction.z, 0.0f);
	}
	virtual ~FlyCommand(){}
	virtual void execute(Character& character);

};






#endif