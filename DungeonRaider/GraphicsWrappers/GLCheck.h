#ifndef GWRAP_GLCHECK_H
#define GWRAP_GLCHECK_H


namespace gWrap
{
	/*
	\brief	Checks the last OpenGL error and prints it out.

	@file	Source file where this is called.
	@line	Source line number where this is called.
	*/
	void glCheckError(const char* file, unsigned int line);
}

#ifdef ENGINE_DEBUG
	//perform error checking on every OpenGL call
	#define glCheck(x) x; gWrap::glCheckError(__FILE__, __LINE__);
#else
	//no overhead in release mode
	#define glCheck(x) x;
#endif




#endif