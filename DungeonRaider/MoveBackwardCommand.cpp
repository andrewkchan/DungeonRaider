#include "MoveBackwardCommand.h"

void MoveBackwardCommand::execute(Actor& actor)
{
	actor.addVelocity(EVector3(0.0, -1.0*actor.getAttributes().maxMoveSpeed, 0.0));
}