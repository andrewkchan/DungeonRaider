#ifndef GWRAP_GLUTILS_H
#define GWRAP_GLUTILS_H

namespace gWrap
{
	class GLUtils
	{
	public:
		static void ensureGLInit();
	private:
		GLUtils(){}
		static void initGL();
		static bool glInitialized; //whether all the appropriate housekeeping functions for OpenGL have been done yet
	};

	
}


#endif