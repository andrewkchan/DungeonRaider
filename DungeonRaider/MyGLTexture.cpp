#include "MyGLTexture.h"
#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include "GraphicsWrappers\GLCheck.h"


namespace MyGL
{
	bool Texture::loadFromFile(const std::string& filePath, unsigned int textureUnit)
	{
		sf::Image image;
		if (! image.loadFromFile(filePath))
		{
			return false;
		}
		width = image.getSize().x;
		height = image.getSize().y;
		texUnit = textureUnit;

		bind();
		initializeBoundTexture();
		//load actual image pixel data into VRAM!
		glCheck(
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr())
			);
		glCheck(glBindTexture(GL_TEXTURE_2D, 0)); //any openGL calls will not affect this texture after this

		return true;
	}
	bool Texture::createUnboundTexture(unsigned int initWidth, unsigned int initHeight, unsigned int textureUnit, unsigned int format)
	{
		texUnit = textureUnit;
		width = initWidth;
		height = initHeight;
		GLint texInternalFormat;
		GLenum texFormat;
		GLenum type;
		switch (format)
		{
		case GL_RGBA:
			texFormat = format;
			texInternalFormat = format;
			type = GL_UNSIGNED_INT;
			break;
		case GL_DEPTH_STENCIL:
			texFormat = format;
			texInternalFormat = GL_DEPTH24_STENCIL8;
			type = GL_UNSIGNED_INT_24_8;
			break;
		default:
			texFormat = GL_RGBA;
			texInternalFormat = GL_RGBA;
			type = GL_UNSIGNED_INT;
			break;
		}

		bind();
		initializeBoundTexture();

		glCheck(glTexImage2D(GL_TEXTURE_2D, 0, texInternalFormat, width, height, 0, texFormat, type, NULL));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		glCheck(glBindTexture(GL_TEXTURE_2D, 0));
		return true;
	}

	unsigned int Texture::getSamplerUnit() const
	{
		return static_cast<unsigned int>(texUnit - GL_TEXTURE0);
	}

	unsigned int Texture::getTextureID() const
	{
		return textureID;
	}

	void Texture::bind() const
	{
		glCheck(glActiveTexture(GL_TEXTURE0 + getSamplerUnit()));
		glCheck(glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(getTextureID())));
	}
	void Texture::regenerateID()
	{
		if (textureID)
		{
			GLuint toDelete = static_cast<GLuint>(textureID);
			glCheck(glDeleteTextures(1, &toDelete));
		}
		GLuint newTextureID;
		glCheck(glGenTextures(1, &newTextureID));
		textureID = static_cast<unsigned int>(newTextureID);
	}

	Texture::Texture()
	{
		regenerateID();
		width = 0;
		height = 0;
		texUnit = 0;

	}
	Texture::Texture(const Texture& texture)
	{
		//WARNING: MAJOR PROBLEMS IF THE SOURCE TEXTURE IS DELETED!!! FIX ASAP
		textureID = texture.textureID;
		width = texture.width;
		height = texture.height;
		texUnit = texture.texUnit;
	}
	Texture::~Texture()
	{
		if (textureID)
		{
			GLuint toDelete = static_cast<GLuint>(textureID);
			glDeleteTextures(1, &toDelete);
		}

	}

	void Texture::initializeBoundTexture()
	{
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)); //repeat if oversample on x-coordinate
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)); //repeat if oversample on y-coordinate
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT)); //repeat if oversample on z-coordinate
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)); //linear filtering on image shrinking
		glCheck(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)); //linear filtering on image magnification
		glCheck(glGenerateMipmap(GL_TEXTURE_2D)); //generate mipmaps for the currently active texture
	}
}