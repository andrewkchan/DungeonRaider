#ifndef GWRAP_TEXTURE_H
#define GWRAP_TEXTURE_H

#include <SFML\Graphics\Texture.hpp>
#include <SFML\Graphics\Rect.hpp>
#include "Window.h"

namespace gWrap
{
	/*
	\brief	Wrapper for an image stored on GPU used for drawing.
	*/
	class Texture
	{
	public:
		bool create(unsigned int width, unsigned int height);
		bool loadFromFile(const std::string& filename, const sf::IntRect& area = sf::IntRect());
		bool loadFromMemory(const void* data, std::size_t size, const sf::IntRect& area = sf::IntRect());
		unsigned int getWidth() const;
		unsigned int getHeight() const;

		/*
		\brief Update a part of the texture from an array of pixels

		If the width and height params do not match the dimensions of the pixel array, nothing is done.

		@pixels		The array of pixels from which the texture will be updated, must be in 32-bit RGBA format
		@width		The width of the pixel region contained in the pixel array
		@height		The height of the pixel region contained in the pixel array
		@x			The x-coordinate of the top-left corner of the region in the texture to update the pixels
		@y			The y-coordinate of the top-left corner of the region in the texture to update the pixels
		*/
		void update(const sf::Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);

		/*
		\brief	Update a part of the texture from the contents of a window

		@x			X-offset in the texture to copy the window contents
		@y			Y-offset in the texture to copy the window contents
		*/
		void update(const Window& window, unsigned int x, unsigned int y);

		//assignment-operator overload
		//Texture& operator =(const Texture& right);

		/*
		\brief	Bind a texture for rendering, to be used with OpenGL code.

		Note: Textures are bound to GL_TEXTURE0 by default.

		@texToBind	The address of the texture to bind.
		*/
		static void bind(const Texture* texToBind);
		/*
		\brief	Bind a texture for rendering to a specific texture unit on the GPU.

		@texToBind		The address of the texture to bind.
		@textureUnit	Which texture unit to bind the texture to (0 is GL_TEXTURE0)
		*/
		static void bind(const Texture* texToBind, unsigned int textureUnit);
	private:

		sf::Texture texture;
		friend class Window;
		friend class RenderStates;

		bool loadFromImage(const sf::Image& image, const sf::IntRect& area = sf::IntRect());
	};
}



#endif