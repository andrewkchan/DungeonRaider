#include "JumpCommand.h"

void JumpCommand::execute(Actor& actor)
{
	actor.addVelocity(Vector3(0.0, 0.0, actor.getAttributes().maxJumpSpeed));
}