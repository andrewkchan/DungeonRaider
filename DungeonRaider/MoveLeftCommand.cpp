#include "MoveLeftCommand.h"

void MoveLeftCommand::execute(Actor& actor)
{
	actor.addVelocity(EVector3(-1.0*actor.getAttributes().maxMoveSpeed, 0.0, 0.0));
}