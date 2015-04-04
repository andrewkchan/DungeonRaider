#include "../GLCheck.h"
#include <GL/glew.h>
#include <string>
#include <iostream>

void gWrap::glCheckError(const char* file, unsigned int line)
{
	GLenum error = glGetError();

	if (error != GL_NO_ERROR)
	{
		std::string fileString(file);
		std::string errorString = "unknown error";
		std::string description = "";

		//get the text for the error code
		switch (error)
		{
			case GL_INVALID_ENUM:
			{
				errorString = "GL_INVALID_ENUM";
				description = "an unacceptable value has been specified for an enumerated argument";
				break;
			}

			case GL_INVALID_VALUE:
			{
				errorString = "GL_INVALID_VALUE";
				description = "a numeric argument is out of range";
				break;
			}

			case GL_INVALID_OPERATION:
			{
				errorString = "GL_INVALID_OPERATION";
				description = "the specified operation is not allowed in the current state";
				break;
			}

			case GL_STACK_OVERFLOW:
			{
				errorString = "GL_STACK_OVERFLOW";
				description = "this command would cause a stack overflow";
				break;
			}

			case GL_STACK_UNDERFLOW:
			{
				errorString = "GL_STACK_UNDERFLOW";
				description = "this command would cause a stack underflow";
				break;
			}

			case GL_OUT_OF_MEMORY:
			{
				errorString = "GL_OUT_OF_MEMORY";
				description = "there is not enough memory left to execute the command";
				break;
			}

			case GL_INVALID_FRAMEBUFFER_OPERATION:
			{
				errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";
				description = "the object bound to FRAMEBUFFER_BINDING is not framebuffer complete";
				break;
			}
		}

		// if error, Log the error
		std::cout << "ERROR: An engine OpenGL call failed in "
			<< fileString.substr(fileString.find_last_of("\\/") + 1) << " (" << line << ") : "
			<< errorString << ", " << description
			<< std::endl;
	}
	//if no error, do nothing
}
