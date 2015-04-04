#ifndef GWRAP_SPRITE_H
#define GWRAP_SPRITE_H

#include "Window.h"
#include "DrawableDT.h"
#include <SFML\Graphics.hpp>

namespace gWrap
{
	class Texture;

	/*
	A drawable handle for a texture that can be transformed, cropped, etc.
	Every Sprite has both a diffuse (color) texture and a depth (heightmap) texture.
	*/
	class Sprite : public DrawableDT, public sf::Transformable
	{
	public:
		/*
		\brief	Default constructor, create an empty sprite without source textures
		*/
		Sprite();
		/*
		\brief	Create a sprite from a source diffuse and optional depth texture
		*/
		Sprite(const sf::Texture& newDiffuseTex, const sf::Texture& newDepthTex);

		/*
		\brief		Change the source diffuse texture of a sprite

		Note that Sprites do not store their own copies of textures, but rather just const
		pointers to textures. Thus source textures should not be deleted for the lifetime of 
		the Sprite.

		@texture	The new diffuse texture to use
		@resetRect	Whether the texture rect should be reset to the size of the new texture or not
		*/
		void setDiffuseTex(const sf::Texture& texture, bool resetRec = false);

		/*
		\brief		Change the source depth texture of a sprite

		Note that Sprites do not store their own copies of textures, but rather just const
		pointers to textures. Thus source textures should not be deleted for the lifetime of
		the Sprite.

		@texture	The new depth texture to use
		@resetRect	Whether the texture rect should be reset to the size of the new texture or not
		*/
		void setDepthTex(const sf::Texture& texture, bool resetRec = false);

		/*
		\brief Set the sub-rectangle of the texture that the sprite will display

		@rectangle	A rectangle representing the portion of the texture to display
		*/
		void setTextureRect(const sf::IntRect& rectangle);

		/*
		\brief	Get the source diffuse texture of the sprite

		@return	A const pointer to the source diffuse texture of the sprite
		*/
		const sf::Texture* getDiffuseTex() const;

		/*
		\brief	Get the source depth texture of the sprite

		@return	A const pointer to the source depth texture of the sprite
		*/
		const sf::Texture* getDepthTex() const;

		/*
		\brief	Get the portion of the texture displayed

		@return	The rectangular portion of the texture displayed
		*/
		const sf::IntRect& getTextureRect() const;

		sf::FloatRect getLocalBounds() const;
		sf::FloatRect getGlobalBounds() const;
	protected:
		virtual void draw(Window& target, float positionalDepth = 0.0f, sf::RenderStates states = sf::RenderStates::Default) const;
		virtual void drawDiffuse(Window& target, sf::RenderStates states) const;
		virtual void drawDepth(Window& target, sf::RenderStates states) const;
	private:
		//update vertice positions
		void updatePositions();
		//update vertice texture coordinates
		void updateTexCoords();

		sf::Vertex vertices[4];
		const sf::Texture* diffuseTex;
		const sf::Texture* depthTex;
		sf::IntRect textureRect;
	};
}



#endif