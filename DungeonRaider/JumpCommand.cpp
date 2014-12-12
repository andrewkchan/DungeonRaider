#include "JumpCommand.h"

void JumpCommand::execute(Character& Character)
{
	Character.addVelocity(EVector3(0.0, 0.0, Character.getAttributes().maxJumpSpeed));
}