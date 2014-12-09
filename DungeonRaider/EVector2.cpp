#include "EVector2.h"

//==============================================
//            MEMBER FUNCTIONS
//==============================================

EVector2 EVector2::uv()
{
	double unitX = m_x / magnitude();
	double unitY = m_y / magnitude();
	return EVector2(unitX, unitY);
}

EVector2& EVector2::operator=(const EVector2& sourceVector)
{
	if (this == &sourceVector)
	{
		return *this; //if self-assignment, skip the copying
	}
	m_x = sourceVector.m_x;
	m_y = sourceVector.m_y;

	return *this; //returns this pointer to allow assignment chaining

}


//=============================================
//               FRIEND FUNCTIONS
//=============================================

EVector2 operator+(const EVector2& firstVector, const EVector2& secondVector) //...NOT a member function of EVector2!
{
	//returns a new vector with x component of the sum of the 2 x components, y component of the sum of the 2 y components
	return EVector2(firstVector.m_x + secondVector.m_x, firstVector.m_y + secondVector.m_y);
}
EVector2 operator-(const EVector2& firstVector, const EVector2& secondVector)
{
	//returns a new vector with x component of the difference of the 2 x components,
	//and y component of the difference of the 2 y components
	return EVector2(firstVector.m_x - secondVector.m_x, firstVector.m_x - secondVector.m_y);
}
double operator*(const EVector2& firstVector, const EVector2& secondVector)
{
	//----------DOT PRODUCT OF 2 VECTORS-------------------------------//
	//returns a SCALAR QUANTITY, the sum of the product of input vectors' x components and
	//the product of input vectors' y components

	return firstVector.m_x*secondVector.m_x + firstVector.m_y*secondVector.m_y;
}
EVector2 operator*(const EVector2& vector, double someDouble)
{
	//---SCALAR PRODUCT----//
	//returns vector with both components multiplied by a scalar

	return EVector2(vector.m_x*someDouble, vector.m_y*someDouble);
}
EVector2 operator*(double someDouble, const EVector2& vector)
{
	return operator*(vector, someDouble); //just return the above b/c it's the same thing
}

std::ostream& operator<<(std::ostream& out, const EVector2& vector)
{
	//prints out a vector in vector notation using std::cout
	//example: cout << EVector2(5.0,7.0) prints <5.0,7.0>
	return out << "<" << vector.m_x << "," << vector.m_y << ">"; 
}

bool operator==(const EVector2& firstVector, const EVector2& secondVector)
{
	//returns whether 2 vectors are equal
	//BEWARE - since vector components are doubles, this will fail due to ROUNDOFF error
	//therefore, approxEquals() is recommended instead
	return firstVector.m_x == secondVector.m_x&&firstVector.m_y == secondVector.m_y;
}
bool operator!=(const EVector2& firstVector, const EVector2& secondVector)
{
	return !(operator==(firstVector, secondVector));
}


EVector2 operator+(const EVector2& vector)
{
	return vector;
}
EVector2 operator-(const EVector2& vector)
{
	return EVector2(-vector.m_x, -vector.m_y);
}
bool operator!(const EVector2& vector)
{
	return (!(vector.m_x)) && (!(vector.m_y));
}

bool approxEquals(const EVector2& firstVector, const EVector2& secondVector)
{
	//returns whether 2 vectors are approximately equal, or within about
	//0.0001% of each other.
	//This is recommended instead of just using ==
	//because EVector2 uses doubles, which can warp direct comparisons
	//due to roundoff error
	const double dEpsilon = 0.000001; //some small number

	return
		fabs(firstVector.m_x - secondVector.m_x) < dEpsilon*fabs(firstVector.m_x)
		&&
		fabs(firstVector.m_y - secondVector.m_y) < dEpsilon*fabs(firstVector.m_y);
}
