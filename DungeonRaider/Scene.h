#ifndef SCENE_H
#define SCENE_H

#include "World.h"
#include "TextureLibrary.h"
#include <SFML/Graphics.hpp>


//fwd declarations
class Character;
class PlayerController;

#include "Character.h"
#include "PlayerController.h"

/*
Class Scene

A scene stores all textures, actors, and other entities needed for a world instance and also the instance
of the world itself. Scenes can be thought of as "levels."
*/
class Scene
{
private:
	World* world;
	TextureLibrary levelTextures;
	Character skelly;
	PlayerController pc;
public:
	Scene();
	Scene(sf::Texture& backgroundTex);
	~Scene();

	void getInput();
	void update(float frameTime);
	void drawToWindow(sf::RenderWindow& window);
};





#endif