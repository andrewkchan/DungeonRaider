#include "MyGLFunctions.h"
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

GLuint MyGLFunctions::createShader(GLenum type, const GLchar* shaderSrc)
{
	static std::vector<GLenum>compiledTypes;
	bool isDuplicate = false;
	for (unsigned int i = 0; i < compiledTypes.size(); i++)
	{
		if (compiledTypes[i] == type)
		{
			isDuplicate = true;
			break;
		}
	}
	if (isDuplicate)
	{
		printf("WARNING: The given shader type %u has already been compiled.\n", type);
	}
	else
	{
		compiledTypes.push_back(type);
	}
	GLuint outputShader = glCreateShader(type);
	glShaderSource(outputShader, 1, &shaderSrc, 0);
	glCompileShader(outputShader);
	return outputShader;
}

GLuint MyGLFunctions::createShaderFromFile(GLenum type, const std::string& srcPath)
{
	//read shader code from file into string
	std::string shaderSrcCode;
	std::ifstream shaderStream(srcPath, std::ios::in);
	if (shaderStream.is_open())
	{
		std::string line = "";
		while (std::getline(shaderStream, line))
		{
			shaderSrcCode += line + "\n";
		}
		shaderStream.close();
	}

	//printf(shaderSrcCode.c_str());

	return createShader(type, shaderSrcCode.c_str());
}