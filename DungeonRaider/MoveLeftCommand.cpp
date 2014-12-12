#include "MoveLeftCommand.h"

void MoveLeftCommand::execute(Character& Character)
{
	Character.addVelocity(EVector3(-1.0*Character.getAttributes().maxMoveSpeed, 0.0, 0.0));
}