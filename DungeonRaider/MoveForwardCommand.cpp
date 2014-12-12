#include "MoveForwardCommand.h"

void MoveForwardCommand::execute(Character& Character)
{
	Character.addVelocity(EVector3(0.0, Character.getAttributes().maxMoveSpeed, 0.0));
}