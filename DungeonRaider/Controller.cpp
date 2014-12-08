#include "Controller.h"

void Controller::linkActor(Actor* inputActor)
{
	_actor = inputActor;
}
void Controller::unlinkActor()
{
	_actor->controller = 0; //set actor's reference to this to null
	_actor = 0; //don't delete the actor object, leave game to deal with it
}