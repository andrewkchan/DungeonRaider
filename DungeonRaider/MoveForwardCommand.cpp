#include "MoveForwardCommand.h"

void MoveForwardCommand::execute(Actor& actor)
{
	actor.addVelocity(Vector3(0.0, actor.getAttributes().maxMoveSpeed, 0.0));
}