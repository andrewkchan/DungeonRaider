#ifndef GWRAP_WINDOW_H
#define GWRAP_WINDOW_H

#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include "../../MyGLTexture.h"

namespace gWrap
{
	class DrawableDT;

	/*

	\brief A window with resize, draw, display, clear, and event systems/functions.

	*/
	class Window : public sf::RenderWindow
	{
	public:
		Window();
		/*
		\brief Default constructor that creates the window in windowed mode with the given dimensions.
		*/
		Window(unsigned int initWidth, unsigned int initHeight, const std::string& initTitle = "");
		Window(const Window& window);
		virtual ~Window();

		unsigned int getWidth() const;
		unsigned int getHeight() const;

		void setSize(unsigned int newWidth, unsigned int newHeight);
		void setPosition(int newPosX, int newPosY);
		void setTitle(const std::string& newTitle);

		void display();
		void displayPostBuffer();
		void displayDepthBuffer();
		void clear(unsigned int red = 0, unsigned int green = 0, unsigned int blue = 0);
		void clearDepth();

		/*
		\brief	Recreate the window in windowed mode without titlebar or controls, like a splash screen.
		@newWidth	The width of the window to be created
		@newHeight	The height of the window to be created
		*/
		void recreateNoDecoration(unsigned int newWidth, unsigned int newHeight);
		/*
		\brief Recreate the window in full screen mode.
		*/
		void recreateFullScreen();
		/*
		\brief Recreate the window in windowed mode with the specified width and height.
		@newWidth	The width of the window to be created
		@newHeight	The height of the window to be created
		*/
		void recreateWindowed(unsigned int newWidth, unsigned int newHeight);
		/*
		\brief	Close the window and destroy all attached resources. Can still be recreated after.
		*/
		void close();

		/*
		\brief	Returns whether the window instance currently controls an open window.
		@return	Whether the window is open or not
		*/
		bool isOpen();

		/*
		\brief	Makes all draw operations after this function is called to be drawn in the post buffer.
		*/
		void switchToPostBuffer();
		/*
		\brief	Makes all draw operations after this function is called to be drawn in the default (visible) framebuffer.
		*/
		void switchToDefaultBuffer();

		/*
		\brief	Draw the diffuse texture of a drawable object. 
		*/
		void drawDiffuse(const DrawableDT& drawableDT, const sf::RenderStates& states = sf::RenderStates::Default);
		/*
		\brief	Draw the depth texture of a drawable object.
		*/
		void drawDepth(const DrawableDT& drawableDT, const sf::RenderStates& states = sf::RenderStates::Default);
		/*
		\brief	Draw the visible parts of a drawable object. This is the "common" draw function.
		*/
		void drawDT(const DrawableDT& drawableDT, float positionalDepth = 0.0f, const sf::RenderStates& states = sf::RenderStates::Default);
		/*
		\brief	Use the old SFML draw function to draw sf::Drawables only.
		*/
		void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

		/*
		\brief	Draw an array of vertices constrained by a given RenderState
		*/
		void draw(const sf::Vertex vertices[4], float positionalDepth = 0.0f,
			const sf::RenderStates& states = sf::RenderStates::Default);
		/*
		\brief	Draw an array of vertices constrained by a given RenderState AS WELL as a given depth texture.
		*/
		void draw(const sf::Vertex vertices[4], const sf::Texture* depthTexture, float positionalDepth = 0.0f,
			const sf::RenderStates& states = sf::RenderStates::Default);

		/*
		\brief	Capture a screenshot of the window contents and save it to disk with the given filename.

		NOTE: Supported formats are bmp, png, tga, and jpg only. Destination is overwritten if already exists.

		@filename	The path and name of the file to save
		@return		Whether the image was saved successfully or not
		*/
		bool saveCapture(const std::string& filename) const;

		/*
		\brief	Get the positional depth of something with respect to the window's current view.

		@yPos		The y-coordinate of the thing
		@return		The positional depth of the thing
		*/
		float getPositionalDepth(float yPos) const;

	protected:
		//actual window stuff
		//sf::RenderWindow window;
		unsigned int width;
		unsigned int height;

	private:

		void create(unsigned int newWidth, unsigned int newHeight, unsigned long style);
		void createFrameBuffers();
		void create2DVAO();

		//framebuffer stuff for post processing------------------------
		GLuint quadVAO; //to allow 2D drawing of textures (cannot be static, needs reset every time sf::Window recreated)
		GLuint postBuffer;
		//GLuint texColorBuffer; //framebuffer gets rendered to this texture
		MyGL::Texture texColorBuffer; //color buffer gets rendered to this texture
		MyGL::Texture texDepthStencil; //depth and stencil buffers get rendered to this texture
		GLuint activeBuffer; //the buffer currently bound to GL_FRAMEBUFFER
		void switchActiveBuffer(GLuint buffer);

		void initStatics(); //initialize window static variables
		void uninitStatics();

		//STATIC stuff--------------------------
		//All statics are guaranteed to be created and uploaded to GPU before instance variables.
		//--------------------------------------------------------------
		static GLuint shaderProgram_sfmlDT;
		static GLuint shader_sfmlDTVert;
		static GLuint shader_sfmlDTFrag;
		static GLint shaderUniform_sfmlDT_positionalDepth;

		static GLuint quadVBO; //buffer holding vertices for 2D quad
		static GLuint shaderProgram_screenDiffuse;
		static GLuint shaderProgram_screenDepth;
		static GLuint shader_screenVert;
		static GLuint shader_screenFrag;
		static GLuint shader_screenFragDepth;
		static GLuint createShaderProgram(const std::string& vertSourcePath, const std::string& fragSourcePath, GLuint& vertShader, GLuint& fragShader);

		static bool staticsInitialized;  //checks whether statics have been initialized correctly
		static int extantWindows; //the current number of open OR closed window instances - if 0, statics are deleted from GPU
	};

	void checkFramebufferError(GLenum error);
}





#endif