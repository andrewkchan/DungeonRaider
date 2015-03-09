#ifndef MYGLFUNCTIONS_H
#define MYGLFUNCTIONS_H

#include <GL/glew.h>
#include <string>


namespace MyGLFunctions
{

	/**
	Creates and compiles a GLSL shader of the given type and from the given GLSL source,
	returning the GLuint handle for the shader.

	@type		The enumerated type of shader, ex: GL_FRAGMENT_SHADER
	@shaderSrc	The address of the (const string) shader source code
	@return		The GLuint handle for the shader
	*/
	GLuint createShader(GLenum type, const GLchar* shaderSrc);

	/**
	Creates and compiles a GLSL shader of the given type and from the given GLSL source code
	file path, returning the GLuint handle for the shader.

	@type		The enumerated type of shader, ex: GL_FRAGMENT_SHADER
	@srcPath	The path of the GLSL source code file, relative the the path of main.cpp
	@return		The GLuint handle for the shader
	*/
	GLuint createShaderFromFile(GLenum type, const std::string& srcPath);
}






#endif