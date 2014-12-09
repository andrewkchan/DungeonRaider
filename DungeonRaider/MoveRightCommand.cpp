#include "MoveRightCommand.h"

void MoveRightCommand::execute(Actor& actor)
{
	actor.addVelocity(EVector3(actor.getAttributes().maxMoveSpeed, 0.0, 0.0));
}