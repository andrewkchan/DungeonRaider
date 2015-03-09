#include "Controller.h"
#include "Character.h"

void Controller::linkCharacter(Character* inputCharacter)
{
	character_ = inputCharacter;
	character_->controller = this;
}
void Controller::unlinkCharacter()
{
	character_->controller = 0; //set Character's reference to this to null
	character_ = 0; //don't delete the Character object, leave game to deal with it
}
