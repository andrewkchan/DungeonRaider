#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

/*
Class TextureLibrary
Brief: This is a instantiable class for storing and retrieving textures.
Textures are accessed by passing in their filename.
*/
class TextureLibrary
{
/*
Class TextureLibrary
Brief: This is a instantiable class for storing and retrieving textures.
Textures are accessed by passing in their filename.
*/
private:
	//the textures currently loaded
	std::map<std::string, sf::Texture>textures_;

public:
	//default constructor
	TextureLibrary()
	{}

	//load a texture from file
	void loadTexture(const std::string& name, const std::string& filename);

	//get a texture reference (for drawing, mainly) from the name of a texture
	sf::Texture& getTexture(const std::string& textureName);
	
};



#endif