#ifndef ALIGNTEST_H
#define ALIGNTEST_H


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/norm.hpp>
#include <iostream>

class AlignBase
{
private:
public:
	AlignBase(){}
	virtual void printVals() = 0;
};

class AlignTest : public AlignBase
{
private:
	//float* myFloat;
	glm::vec4 myVec;
public:
	AlignTest(float x = 1.0f, float y = 0.0f, float z = -1.0f) : myVec(x, y, z, 0.0f)
	{
		std::cout << "x:" << myVec.x << " y:" << myVec.y << " z:" << myVec.z << std::endl;
	}
	~AlignTest()
	{
		//delete myFloat;
	}
	virtual void printVals()
	{
		std::cout << "exec x:" << myVec.x << " exec y:" << myVec.y << " exec z:" << myVec.z << std::endl;
	}
};






#endif