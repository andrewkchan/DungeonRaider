#include "MoveLeftCommand.h"

void MoveLeftCommand::execute(Actor& actor)
{
	actor.addVelocity(Vector3(-1.0*actor.getAttributes().maxMoveSpeed, 0.0, 0.0));
}