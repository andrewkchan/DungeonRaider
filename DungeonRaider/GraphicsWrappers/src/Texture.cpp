#include "..\Texture.h"
#include <SFML\Graphics.hpp>
#include "..\GLCheck.h"
#include "..\GLUtils.h"
#include <GL/glew.h>

namespace gWrap
{
	bool Texture::create(unsigned int width, unsigned int height)
	{
		return texture.create(width, height);
	}
	bool Texture::loadFromFile(const std::string& filename, const sf::IntRect& area)
	{
		return texture.loadFromFile(filename, area);
	}
	bool Texture::loadFromMemory(const void* data, std::size_t size, const sf::IntRect& area)
	{
		return texture.loadFromMemory(data, size, area);
	}
	unsigned int Texture::getWidth() const
	{
		return texture.getSize().x;
	}
	unsigned int Texture::getHeight() const
	{
		return texture.getSize().y;
	}
	void Texture::update(const sf::Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y)
	{
		texture.update(pixels, width, height, x, y);
	}

	void Texture::bind(const Texture* texToBind)
	{
		sf::Texture::bind(&texToBind->texture);
	}
	void Texture::bind(const Texture* texToBind, unsigned int textureUnit)
	{
		GLUtils::ensureGLInit();
		glCheck(glActiveTexture(static_cast<GLenum>(GL_TEXTURE0 + textureUnit)));
		sf::Texture::bind(&texToBind->texture);
		glCheck(glActiveTexture(GL_TEXTURE0));
	}
}