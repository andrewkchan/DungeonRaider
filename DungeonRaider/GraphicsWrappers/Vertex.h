#ifndef GWRAP_VERTEX_H
#define GWRAP_VERTEX_H

namespace gWrap
{
	/*
	\brief	A point in 2D space with (float) position and texture coordinates.
	*/
	struct Vertex
	{
		Vertex(float x = 0.0f, float y = 0.0f, float s = 0.0f, float t = 0.0f)
		{
			this->x = x;
			this->y = y;
			this->s = s;
			this->t = t;
		}
		float x;	//The x-coordinate of the vertex's position
		float y;	//The y-coordinate of the vertex's position
		float s;	//The texture x-coordinate
		float t;	//The texture y-coordinate
	};
}


#endif