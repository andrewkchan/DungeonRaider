#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>

/*
Abstract base class describing world loaded and drawn for each game scene.
*/
class World
{
	/*
	Class World



	This class describes the world that is loaded and drawn for each game level.
	
	Worlds consists of a tile system (each tile is decoupled from the world and
	has predetermined graphics) and a world background.
	
	NOTE: World tiles follow a separate coordinate system than the world space itself. For example,
	something can be at coordinates(0,0,0) in world space but at coordinate (150,150) in the tiles.
	A single tile covers non-negligible space in the world.
	*/
private:
	sf::Sprite background_;

	//the angle in degrees from the horizontal that the X axis of an orthographic coordinate system would extend
	//a common isometric coordinate system has about a 26.5 degree angle.
	//a top-down coordinate system has a 0.0 degree angle
	float orthographicAngleX; 
	//the angle in degrees from the horizontal that the Y axis of an orthographic coordinate system would extend
	float orthographicAngleY;
protected:
	//set the angle in degrees between the horizontal and the X axis of the orthographic coordinate system
	void setOrthoAngleX(float orthoAngleX) { orthographicAngleX = orthoAngleX; }
	//set the angle in degrees between the horizontal and the Y axis of the orthographic coordinate system
	void setOrthoAngleY(float orthoAngleY) { orthographicAngleY = orthoAngleY; }

	World(float orthoAngleX = 26.5f, float orthoAngleY = 26.5f) :
		orthographicAngleX(orthoAngleX),
		orthographicAngleY(orthoAngleY)
	{
		background_ = sf::Sprite();
	}
	World(sf::Texture& backgroundTex, float orthoAngleX = 26.5f, float orthoAngleY = 26.5f) :
		orthographicAngleX(orthoAngleX),
		orthographicAngleY(orthoAngleY)
	{
		background_.setTexture(backgroundTex);
	}
public:
	virtual ~World(){}

	
	void drawToWindow(sf::RenderWindow& window)
	{
		window.draw(background_);
	}
};





#endif