#ifndef MATERIAL_H
#define MATERIAL_H

#include "Sprite.h"

class Material
{
	/*
	Class Material

	This class describes all physical attributes of a tile's terrain,
	such as movement cost, tile sprite, etc.
	
	The world's tile system consists of a 2D array of pointers to Material objects.
	
	*/

private:
	Sprite _texture;
	bool _isWater;
	bool _isDamaging; //is the material damaging to characters (ex: lava)
public:
	Material(Sprite texture, bool isWater, bool isDamaging) :
		_texture(texture), _isWater(isWater), _isDamaging(isDamaging)
	{
		//default constructor
	}
	//don't have to define deconstructor, since Material's Sprite is not a pointer

	bool isWater() { return _isWater; }
	bool isDamaging() { return _isDamaging; }


};



#endif