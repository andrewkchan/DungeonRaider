#ifndef EVECTOR2_H
#define EVECTOR2_H

#include "math.h"
#include <iostream>

class EVector2
{
	//EVector2, a euclidean vector with 2 coordinates
private:
	double m_x;
	double m_y;
public:
	EVector2(double initX = 0, double initY = 0) : m_x(initX), m_y(initY)
	{
	}
	//copy constructor
	EVector2(const EVector2& sourceVector) : m_x(sourceVector.m_x), m_y(sourceVector.m_y)
	{
	}

	double x() //returns x component of vector
	{
		return m_x;
	}
	double y() //returns y component of vector
	{
		return m_y;
	}
	double magnitude() //returns positive length of vector
	{
		return static_cast<double>(sqrt(m_x*m_x + m_y*m_y));
	}

	EVector2 uv(); //returns the unit vector (by value) of the current EVector2, function defined in EVector2.cpp



	//========Overloads==================

	//assignment overloads
	EVector2& operator=(const EVector2& sourceVector); //returns *this to allow chaining of assignments



	//arithmetic operator overloads
	friend EVector2 operator+(const EVector2& firstVector, const EVector2& secondVector);
	friend EVector2 operator-(const EVector2& firstVector, const EVector2& secondVector);
	friend double operator*(const EVector2& firstVector, const EVector2& secondVector); //DOT PRODUCT
	friend EVector2 operator*(const EVector2& vector, double someDouble); //scalar product
	friend EVector2 operator*(double someDouble, const EVector2& vector);

	//iostream overloads
	friend std::ostream& operator<<(std::ostream& out, const EVector2& vector); //printing a vector

	//bool operator overloads
	friend bool operator==(const EVector2& firstVector, const EVector2& secondVector); 
	//beware - since vector components are doubles, this will fail due to roundoff errors, so approxEquals() recommended instead
	friend bool operator!=(const EVector2& firstVector, const EVector2& secondVector); //same as ==, beware roundoff error

	//unary operator overloads
	friend EVector2 operator+(const EVector2& vector);
	friend EVector2 operator-(const EVector2& vector);
	friend bool operator!(const EVector2& vector); //operator !, returns true if vector==EVector2(0,0)

	//approxEquals() function
	friend bool approxEquals(const EVector2& firstVector, const EVector2& secondVector);

};

#endif