#include "AnimState.h"


sf::Sprite& AnimState::OnDraw()
{
	return anim.getCurrentFrame(timeInState);
}