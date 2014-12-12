#include "Controller.h"

void Controller::linkCharacter(Character* inputCharacter)
{
	_Character = inputCharacter;
}
void Controller::unlinkCharacter()
{
	_Character->controller = 0; //set Character's reference to this to null
	_Character = 0; //don't delete the Character object, leave game to deal with it
}