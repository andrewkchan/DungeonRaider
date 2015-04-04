#ifndef STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H


#include "DrawableComponent.h"
#include "..\..\GraphicsWrappers\Sprite.h"

namespace sf
{
	class Texture;
}

/*
class StaticSpriteComponent

A DrawableComponent that draws one and only one sprite every time onDraw() is called.
*/
class StaticSpriteComponent : public DrawableComponent
{
private:
	gWrap::Sprite sprite_;
	StaticSpriteComponent(){}
public:
	StaticSpriteComponent(sf::Texture& texture)
	{
		sprite_.setDiffuseTex(texture);
	}
	StaticSpriteComponent(const gWrap::Sprite& sprite)
	{
		sprite_ = sprite;
	}

	virtual void update(float frameTime, Actor& actor){}
	virtual gWrap::DrawableDT& onDraw()
	{
		return sprite_;
	}
};







#endif