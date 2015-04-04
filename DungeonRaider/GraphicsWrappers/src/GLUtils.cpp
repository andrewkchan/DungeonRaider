#include "..\GLUtils.h"
#include <GL/glew.h>
#include <assert.h>

namespace gWrap
{
	bool GLUtils::glInitialized = false;
	void GLUtils::initGL()
	{
		//cannot use any GL functions before doing this!
		::glewExperimental = GL_TRUE;
		assert(glewInit() == GLEW_OK);
		glInitialized = true;
	}
	void GLUtils::ensureGLInit()
	{
		if (!glInitialized)
		{
			initGL();
		}
	}
}