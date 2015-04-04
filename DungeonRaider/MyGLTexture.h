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

		/*
		Create an empty texture unbound to any specific image that can be used as a rendertarget.

		@initWidth			-The width of the empty texture
		@initHeight			-The height of the empty texture
		@textureUnit		-The texture unit that the texture is to be loaded into, should always be <48
		@format				-(Optional) The internal format that the texture is stored as. If 0, then RGBA
		@return				-TRUE if texture was created successfully, FALSE if texture has already been created
		*/
		bool createUnboundTexture(unsigned int initWidth, unsigned int initHeight, 
			unsigned int textureUnit, unsigned int format = 0);

		//returns the unique identifier of the texture in VRAM
		unsigned int getID() const { return textureID; }
		//returns the width of the texture
		unsigned int getWidth() const { return width; }
		//returns the height of the texture
		unsigned int getHeight() const { return height; }
		//returns the texture unit that the texture is associated with
		unsigned int getSamplerUnit() const;
		//returns the unique ID that the texture is associated with
		unsigned int getTextureID() const;

		void bind() const;
		void regenerateID();

		Texture();
		Texture(const Texture& texture);
		virtual ~Texture();
	private:
		unsigned int textureID; //texture identifier, a unique number holding its address on GPU
		unsigned int width;
		unsigned int height;
		unsigned int texUnit; //the texture unit in VRAM that the texture ID is associated with, matches with GLEnum

		void initializeBoundTexture();
	};
}





#endif