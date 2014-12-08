#include "MoveRightCommand.h"

void MoveRightCommand::execute(Actor& actor)
{
	actor.addVelocity(Vector3(actor.getAttributes().maxMoveSpeed, 0.0, 0.0));
}