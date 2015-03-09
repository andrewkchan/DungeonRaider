#include "FlyCommand.h"
#include "Character.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>
#include <iostream>

class PhysicsComponent;

void FlyCommand::execute(Character& character)
{
	PhysicsComponent& pc = character.getPhysicsComponent();
	pc.exertAcceleration(dir.x, dir.y, dir.z);
	//pc.setVelocity(dir.x, dir.y, dir.z);
	//std::cout << "execution dir.x:" << dir.x << " dir.y:" << dir.y << " dir.z:" << dir.z << std::endl;
	//pc.setVelocity(0.0f, -1.0f, -1.0f);
}