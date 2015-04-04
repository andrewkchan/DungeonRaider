#ifndef TEXTCOMPONENT_H
#define TEXTCOMPONENT_H

#include "Components\GUIComponent.h"
#include <SFML/Graphics.hpp>
#include "Tracker.h"
#include "Components\TransformComponent.h"

class TextComponent : public GUIComponent
{
private:
	sf::Text text;
public:
	TextComponent(const sf::Font& font, const std::string& textToDisplay = "")
	{
		text.setFont(font);
		text.setString(textToDisplay);
		text.setCharacterSize(24);
	}

	void setSize(int pixels) { text.setCharacterSize(pixels); }
	void setString(const std::string& textToDisplay)
	{
		text.setString(textToDisplay);
	}
	void setFont(const sf::Font& font)
	{
		text.setFont(font);
	}
	virtual void update(float frameTime, GUIEntity& entity)
	{}

	virtual sf::Drawable& onDraw() { return text; }
};





#endif