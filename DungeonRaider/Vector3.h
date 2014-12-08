#ifndef VECTOR3_H
#define VECTOR3_H


#include "math.h"
#include <iostream>

class Vector3
{
private:
	double _x;
	double _y;
	double _z;
public:
	Vector3(double initX = 0, double initY = 0, double initZ = 0) : _x(initX), _y(initY), _z(initZ)
	{
	}
	//copy constructor
	Vector3(const Vector3& sourceVector) : _x(sourceVector._x), _y(sourceVector._y), _z(sourceVector._z)
	{
	}

	double x() { return _x; }
	double y() { return _y; }
	double z() { return _z; }

	double magnitude() //returns positive length of vector
	{
		return sqrt(_x*_x + _y*_y + _z*_z);
	}

	Vector3 uv(); //returns the unit vector of the current vector

	//vector arithmetic products
	friend Vector3 crossProduct(const Vector3& firstVector, const Vector3& secondVector);
	friend double dotProduct(const Vector3& firstVector, const Vector3& secondVector);

	//approxEquals() function
	friend bool approxEquals(const Vector3& firstVector, const Vector3& secondVector);

	//=======================Overloads===============

	//assignment overloads
	Vector3& operator=(const Vector3& sourceVector);
	//arithmetic assignment
	void operator+=(const Vector3& sourceVector); //addition of vectors assignment
	void operator-=(const Vector3& sourceVector); //subtraction of vectors assignment
	void operator*=(double someDouble); //scalar product assignment



	//arithmetic operator overloads
	friend Vector3 operator+(const Vector3& firstVector, const Vector3& secondVector);
	friend Vector3 operator-(const Vector3& firstVector, const Vector3& secondVector);
	//NOTE: dot product is implemented as a regular function, NOT an operator
	//NOTE: same with cross product
	friend Vector3 operator*(const Vector3& vector, double someDouble); //scalar product
	friend Vector3 operator*(double someDouble, const Vector3& vector);

	//iostream overloads
	friend std::ostream& operator<<(std::ostream& out, const Vector3& vector); //printing a vector

	//bool operator overloads
	friend bool operator==(const Vector3& firstVector, const Vector3& secondVector);
	//beware - since vector components are doubles, this will fail due to roundoff errors, so approxEquals() recommended instead
	friend bool operator!=(const Vector3& firstVector, const Vector3& secondVector); //same as ==, beware roundoff error

	//unary operator overloads
	friend Vector3 operator+(const Vector3& vector);
	friend Vector3 operator-(const Vector3& vector);
	friend bool operator!(const Vector3& vector); //operator !, returns true if vector==Vector2(0,0)

	

	
};


#endif