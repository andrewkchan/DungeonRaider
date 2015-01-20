#include "TextureLibrary.h"

void TextureLibrary::loadTexture(const std::string& name, const std::string& filename)
{
	//load the texture
	sf::Texture texture;
	texture.loadFromFile(filename);

	//add to the list of textures
	textures_[name] = texture;
}

sf::Texture& TextureLibrary::getTexture(const std::string& textureName)
{
	return textures_.at(textureName); //std::map::at() provides bounds-checking, unlike operator[]
}