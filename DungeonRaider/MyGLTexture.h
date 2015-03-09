#ifndef MYGLTEXTURE_H
#define MYGLTEXTURE_H

#include <string>

namespace MyGL
{
	class Texture
	{
	public:
		/*
		Loads the texture from the specified image file.

		@filePath		-The path of the image file relative to the working directory
		@textureUnit	-The texture unit that the texture is to be loaded into, should always be <48
		@return			-TRUE if texture loaded successfully, FALSE if failed to load
		*/
		bool loadFromFile(const std::string& filePath, unsigned int textureUnit);

		//returns the unique identifier of the texture in VRAM
		unsigned int getID() const { return textureID; }
		//returns the width of the texture
		unsigned int getWidth() const { return width; }
		//returns the height of the texture
		unsigned int getHeight() const { return height; }
		//returns the texture unit that the texture is associated with
		unsigned int getSamplerUnit() const;

		Texture();
		Texture(const Texture& texture);
		virtual ~Texture();
	private:
		unsigned int textureID; //texture identifier, a unique number holding its address on GPU
		unsigned int width;
		unsigned int height;
		unsigned int texUnit; //the texture unit in VRAM that the texture ID is associated with, matches with GLEnum
	};
}





#endif