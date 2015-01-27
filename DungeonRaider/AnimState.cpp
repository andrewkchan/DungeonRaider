#include "AnimState.h"


sf::IntRect AnimState::OnDraw(float timeInState)
{
	return anim.getCurrentFrame(timeInState);
}