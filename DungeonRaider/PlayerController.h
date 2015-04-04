#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Controller.h"
#include "GameState.h"
#include "Command.h"
#include "FlyCommand.h"
#include "Entities\GUIEntity.h"
#include "FloatValueDisplayText.h"
#include <SFML\Graphics.hpp>

namespace gWrap
{
	class Window;
}

class PlayerController : public Controller
{
private:
	Command* inputLeft;
	Command* inputRight;
	Command* inputUp;
	Command* inputDown;

public:
	PlayerController() : Controller()
	{
		//default constructor
		inputLeft = new FlyCommand(-5.0f, 0.0f, 0.0f);
		inputRight = new FlyCommand(5.0f, 0.0f, 0.0f);
		inputUp = new FlyCommand(0.0f, 0.0f, 5.0f);
		inputDown = new FlyCommand(0.0f, 0.0f, -5.0f);
	}
	virtual ~PlayerController()
	{
		delete inputLeft;
		delete inputRight;
		delete inputUp;
		delete inputDown;
	}
	virtual void linkCharacter(Character* inputCharacter);
	virtual void handleInput();

	virtual void update(float frameTime);
	virtual void drawGUIToWindow(gWrap::Window& window);
};





#endif