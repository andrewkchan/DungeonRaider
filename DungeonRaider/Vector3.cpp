#include "Vector3.h"

Vector3 Vector3::uv()
{
	return Vector3(_x / magnitude(), _y / magnitude(), _z / magnitude());
}
Vector3 crossProduct(const Vector3& firstVector, const Vector3& secondVector) //vector cross product
{
	return Vector3(
		firstVector._y * secondVector._z - firstVector._z * secondVector._y,
		firstVector._z * secondVector._x - firstVector._x * secondVector._z,
		firstVector._x * secondVector._y - firstVector._y * secondVector._x
		);
}
double dotProduct(const Vector3& firstVector, const Vector3& secondVector)
{
	return firstVector._x * secondVector._x + firstVector._y * secondVector._y + firstVector._z * secondVector._z;
}
bool approxEquals(const Vector3& firstVector, const Vector3& secondVector)
{
	//returns whether 2 vectors are approximately equal, or within about
	//0.0001% of each other.
	//This is recommended instead of just using ==
	//because Vector2 uses doubles, which can warp direct comparisons
	//due to roundoff error
	const double dEpsilon = 0.000001; //some small number

	return
		fabs(firstVector._x - secondVector._x) < dEpsilon*fabs(firstVector._x)
		&&
		fabs(firstVector._y - secondVector._y) < dEpsilon*fabs(firstVector._y)
		&&
		fabs(firstVector._z - secondVector._z) < dEpsilon*fabs(firstVector._z);
}

//===============================================================================
//			OPERATOR OVERLOADS
//===============================================================================



Vector3& Vector3::operator=(const Vector3& sourceVector)
{
	if (this == &sourceVector)
	{
		return *this; //if self-assignment, skip the copying
	}
	_x = sourceVector._x;
	_y = sourceVector._y;
	_z = sourceVector._z;

	return *this; //returns this pointer to allow assignment chaining
}
void Vector3::operator+=(const Vector3& sourceVector)
{
	_x += sourceVector._x;
	_y += sourceVector._y;
	_z += sourceVector._z;
}
void Vector3::operator-=(const Vector3& sourceVector)
{
	_x -= sourceVector._x;
	_y -= sourceVector._y;
	_z -= sourceVector._z;
}
void Vector3::operator*=(double someDouble) //scalar product assignment
{
	_x *= someDouble;
	_y *= someDouble;
	_z *= someDouble;
}

Vector3 operator+(const Vector3& firstVector, const Vector3& secondVector)
{
	return Vector3(firstVector._x + secondVector._x, firstVector._y + secondVector._y, firstVector._z + secondVector._z);
}
Vector3 operator-(const Vector3& firstVector, const Vector3& secondVector)
{
	return Vector3(firstVector._x - secondVector._x, firstVector._y - secondVector._y, firstVector._z - secondVector._z);
}
Vector3 operator*(const Vector3& vector, double someDouble) //scalar product
{
	return Vector3(vector._x * someDouble, vector._y * someDouble, vector._z * someDouble);
}
Vector3 operator*(double someDouble, const Vector3& vector) //scalar product, different order
{
	return Vector3(vector._x * someDouble, vector._y * someDouble, vector._z * someDouble);
}

//iostream overloads
std::ostream& operator<<(std::ostream& out, const Vector3& vector) //printing a vector
{
	//prints out a vector in vector notation using std::cout
	//example: cout << Vector2(5.0,7.0,2.0) prints <5.0,7.0,2.0>
	return out << "<" << vector._x << "," << vector._y << "," << vector._z << ">";
}

bool operator==(const Vector3& firstVector, const Vector3& secondVector)
{
	//not recommended due to roundoff error, use approxEquals() instead
	return firstVector._x == secondVector._x&&firstVector._y == secondVector._y&&firstVector._z == secondVector._z;
}
bool operator!=(const Vector3& firstVector, const Vector3& secondVector)
{
	//not recommended due to roundoff error, use !(approxEquals()) instead
	return !(firstVector == secondVector);
}
Vector3 operator+(const Vector3& vector)
{
	return vector;
}
Vector3 operator-(const Vector3& vector)
{
	return -1.0 * vector;
}
bool operator!(const Vector3& vector)
{
	return vector._x == 0.0&&vector._y == 0.0&&vector._z == 0.0;
}