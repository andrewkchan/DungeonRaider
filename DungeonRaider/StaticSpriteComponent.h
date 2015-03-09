#ifndef STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H


#include "DrawableComponent.h"
#include <SFML/Graphics.hpp>

/*
class StaticSpriteComponent

A DrawableComponent that draws one and only one sprite every time onDraw() is called.
*/
class StaticSpriteComponent : public DrawableComponent
{
private:
	sf::Sprite sprite_;
	StaticSpriteComponent(){}
public:
	StaticSpriteComponent(sf::Texture& texture)
	{
		sprite_.setTexture(texture);
	}
	StaticSpriteComponent(sf::Sprite sprite)
	{
		sprite_ = sprite;
	}

	virtual void update(float frameTime, Actor& actor){}
	virtual sf::Drawable& onDraw()
	{
		return sprite_;
	}
};







#endif