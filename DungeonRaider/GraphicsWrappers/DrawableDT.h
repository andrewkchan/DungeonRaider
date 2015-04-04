#ifndef GWRAP_DRAWABLEDT_H
#define GWRAP_DRAWABLEDT_H

#include <SFML\Graphics\RenderStates.hpp>

namespace gWrap
{
	class Window;

	/*
	An abstract base class for objects with both diffuse and depth textures that can be drawn
	to a window.
	*/
	class DrawableDT
	{
	public:
		virtual ~DrawableDT(){}
	protected:
		////////////////////
		friend class Window;
		////////////////////
		virtual void draw(Window& target, float positionalDepth = 0.0f, sf::RenderStates states = sf::RenderStates::Default) const = 0;
		virtual void drawDiffuse(Window& target, sf::RenderStates states) const = 0;
		virtual void drawDepth(Window& target, sf::RenderStates states) const = 0;
	};
}



#endif