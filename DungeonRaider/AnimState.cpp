#include "AnimState.h"


void AnimState::OnUpdate(double frameTime)
{
	timeInState += frameTime;
	checkConditions();
	
	//todo: see what other states the actor can transition to
}
sf::Sprite& AnimState::OnDraw()
{
	return anim.getCurrentFrame(timeInState);
}
void AnimState::checkConditions()
{
	//todo: implement checking of actor physical conditions
}