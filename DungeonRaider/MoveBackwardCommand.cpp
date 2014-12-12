#include "MoveBackwardCommand.h"

void MoveBackwardCommand::execute(Character& Character)
{
	Character.addVelocity(EVector3(0.0, -1.0*Character.getAttributes().maxMoveSpeed, 0.0));
}