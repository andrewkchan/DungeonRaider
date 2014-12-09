#ifndef EVECTOR3_H
#define EVECTOR3_H


#include "math.h"
#include <iostream>

class EVector3
{
private:
	double _x;
	double _y;
	double _z;
public:
	EVector3(double initX = 0, double initY = 0, double initZ = 0) : _x(initX), _y(initY), _z(initZ)
	{
	}
	//copy constructor
	EVector3(const EVector3& sourceVector) : _x(sourceVector._x), _y(sourceVector._y), _z(sourceVector._z)
	{
	}

	double x() { return _x; }
	double y() { return _y; }
	double z() { return _z; }

	double magnitude() //returns positive length of vector
	{
		return sqrt(_x*_x + _y*_y + _z*_z);
	}

	EVector3 uv(); //returns the unit vector of the current vector

	//vector arithmetic products
	friend EVector3 crossProduct(const EVector3& firstVector, const EVector3& secondVector);
	friend double dotProduct(const EVector3& firstVector, const EVector3& secondVector);

	//approxEquals() function
	friend bool approxEquals(const EVector3& firstVector, const EVector3& secondVector);

	//=======================Overloads===============

	//assignment overloads
	EVector3& operator=(const EVector3& sourceVector);
	//arithmetic assignment
	void operator+=(const EVector3& sourceVector); //addition of vectors assignment
	void operator-=(const EVector3& sourceVector); //subtraction of vectors assignment
	void operator*=(double someDouble); //scalar product assignment



	//arithmetic operator overloads
	friend EVector3 operator+(const EVector3& firstVector, const EVector3& secondVector);
	friend EVector3 operator-(const EVector3& firstVector, const EVector3& secondVector);
	//NOTE: dot product is implemented as a regular function, NOT an operator
	//NOTE: same with cross product
	friend EVector3 operator*(const EVector3& vector, double someDouble); //scalar product
	friend EVector3 operator*(double someDouble, const EVector3& vector);

	//iostream overloads
	friend std::ostream& operator<<(std::ostream& out, const EVector3& vector); //printing a vector

	//bool operator overloads
	friend bool operator==(const EVector3& firstVector, const EVector3& secondVector);
	//beware - since vector components are doubles, this will fail due to roundoff errors, so approxEquals() recommended instead
	friend bool operator!=(const EVector3& firstVector, const EVector3& secondVector); //same as ==, beware roundoff error

	//unary operator overloads
	friend EVector3 operator+(const EVector3& vector);
	friend EVector3 operator-(const EVector3& vector);
	friend bool operator!(const EVector3& vector); //operator !, returns true if vector==EVector2(0,0)

	

	
};


#endif