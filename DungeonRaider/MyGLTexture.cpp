#include "MyGLTexture.h"
#include <GL/glew.h>
#include <SFML/Graphics.hpp>


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

		texUnit = GL_TEXTURE0 + textureUnit;
		//glActiveTexture(texUnit);
		glActiveTexture(texUnit + 1); //HACK! I have no idea why I have to add 1, but it works
		//printf("Active texture: %u \n", texUnit);
		//printf("GL_TEXTURE0: %u \n", GL_TEXTURE0);
		//printf("Sampler unit should be %u \n", static_cast<unsigned int>(texUnit - GL_TEXTURE0));
		glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(textureID)); //bind the ID to the texture unit

		//load actual image pixel data into VRAM!
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr()); 

		glBindTexture(GL_TEXTURE_2D, 0); //any openGL calls will not affect this texture after this

		return true;
	}

	unsigned int Texture::getSamplerUnit() const
	{
		return static_cast<unsigned int>(texUnit - GL_TEXTURE0);
	}

	Texture::Texture()
	{
		GLuint newTextureID;
		glGenTextures(1, &newTextureID);
		textureID = static_cast<unsigned int>(newTextureID);
		width = 0;
		height = 0;
		texUnit = 0;

		glBindTexture(GL_TEXTURE_2D, static_cast<GLuint>(textureID)); //bind the ID to the texture unit
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //repeat if oversample on x-coordinate
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //repeat if oversample on y-coordinate
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT); //repeat if oversample on z-coordinate
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //linear filtering on image shrinking
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //linear filtering on image magnification
		glGenerateMipmap(GL_TEXTURE_2D); //generate mipmaps for the currently active texture
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
}