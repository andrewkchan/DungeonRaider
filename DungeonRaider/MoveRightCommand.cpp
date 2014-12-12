#include "MoveRightCommand.h"

void MoveRightCommand::execute(Character& Character)
{
	Character.addVelocity(EVector3(Character.getAttributes().maxMoveSpeed, 0.0, 0.0));
}