#ifndef WORLD_H
#define WORLD_H

#include "Material.h"


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
	Material* _tiles[400][400]; //this is NOT dynamically allocated - this is an array of Material pointers
	//todo: add world background
	Material GRASS;
	Material DIRT;
	Material STONE;
	Material WATER;
public:
	World(Sprite& grassSprite, Sprite& dirtSprite, Sprite& stoneSprite, Sprite& waterSprite)
		: GRASS(grassSprite, false, false), DIRT(dirtSprite, false, false), STONE(stoneSprite, false, false),
		WATER(waterSprite, false, false)
	{
		//default constructor
		for (int i = 0; i < 400; i++)
		{
			//cheap systematic assignment of tile materials, for now
			for (int j = 0; j < 400; j++)
			{
				if (i % 3 == 0 && j % 5 == 0)
				{
					_tiles[i][j] = &WATER;
				}
				else
				{
					if (i % 2 == 0 && j % 3 == 0)
					{
						_tiles[i][j] = &DIRT;
					}
					else
					{
						if (j % 2 == 0)
						{
							_tiles[i][j] = &STONE;
						}
						else
						{
							_tiles[i][j] = &GRASS;
						}
					}
				}
			}
		}

	}
	
};





#endif