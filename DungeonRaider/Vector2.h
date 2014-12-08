#ifndef VECTOR2_H
#define VECTOR2_H

#include "math.h"
#include <iostream>

class Vector2
{
private:
	double m_x;
	double m_y;
public:
	Vector2(double initX = 0, double initY = 0) : m_x(initX), m_y(initY)
	{
	}
	//copy constructor
	Vector2(const Vector2& sourceVector) : m_x(sourceVector.m_x), m_y(sourceVector.m_y)
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

	Vector2 uv(); //returns the unit vector (by value) of the current vector2, function defined in Vector2.cpp



	//========Overloads==================

	//assignment overloads
	Vector2& operator=(const Vector2& sourceVector); //returns *this to allow chaining of assignments



	//arithmetic operator overloads
	friend Vector2 operator+(const Vector2& firstVector, const Vector2& secondVector);
	friend Vector2 operator-(const Vector2& firstVector, const Vector2& secondVector);
	friend double operator*(const Vector2& firstVector, const Vector2& secondVector); //DOT PRODUCT
	friend Vector2 operator*(const Vector2& vector, double someDouble); //scalar product
	friend Vector2 operator*(double someDouble, const Vector2& vector);

	//iostream overloads
	friend std::ostream& operator<<(std::ostream& out, const Vector2& vector); //printing a vector

	//bool operator overloads
	friend bool operator==(const Vector2& firstVector, const Vector2& secondVector); 
	//beware - since vector components are doubles, this will fail due to roundoff errors, so approxEquals() recommended instead
	friend bool operator!=(const Vector2& firstVector, const Vector2& secondVector); //same as ==, beware roundoff error

	//unary operator overloads
	friend Vector2 operator+(const Vector2& vector);
	friend Vector2 operator-(const Vector2& vector);
	friend bool operator!(const Vector2& vector); //operator !, returns true if vector==Vector2(0,0)

	//approxEquals() function
	friend bool approxEquals(const Vector2& firstVector, const Vector2& secondVector);

};

#endif