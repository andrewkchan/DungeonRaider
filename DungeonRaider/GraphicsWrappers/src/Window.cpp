#include "..\Window.h"
#include "..\GLUtils.h"
#include "..\..\MyGLFunctions.h"
#include "..\GLCheck.h"
#include "..\DrawableDT.h"
#include <SFML\Graphics.hpp>
#include <iostream>

const GLenum TEXUNIT_texColorBuffer = GL_TEXTURE1;
const GLenum TEXUNIT_texDepthStencil = GL_TEXTURE2;
const GLenum TEXUNIT_diffuse = GL_TEXTURE0; //sf::Textures are bound to 0 when using sfml draw functions
const GLenum TEXUNIT_depth = GL_TEXTURE4;

typedef sf::RenderWindow BaseWindow;
namespace gWrap
{
	Window::Window() :
		BaseWindow(),
		width(0),
		height(0),
		activeBuffer(0)
	{
		GLUtils::ensureGLInit();
		++extantWindows;
		initStatics();
	}
	Window::Window(unsigned int initWidth, unsigned int initHeight, const std::string& initTitle) :
		BaseWindow(),
		width(initWidth),
		height(initHeight),
		activeBuffer(0)
	{
		GLUtils::ensureGLInit();
		++extantWindows;
		initStatics();
		recreateWindowed(initWidth, initHeight);
	}
	Window::~Window()
	{
		if (isOpen())
		{
			close();
		}
		--extantWindows;
		uninitStatics();
	}

	//------------------------------------------------------------------------
	//		PUBLIC FUNCTIONS
	//------------------------------------------------------------------------

	unsigned int Window::getWidth() const { return width; }
	unsigned int Window::getHeight() const { return height; }
	void Window::setSize(unsigned int newWidth, unsigned int newHeight)
	{
		width = newWidth;
		height = newHeight;
		BaseWindow::setSize(sf::Vector2u(width, height));
	}
	void Window::setPosition(int newPosX, int newPosY)
	{
		BaseWindow::setPosition(sf::Vector2i(newPosX, newPosY));
	}
	void Window::setTitle(const std::string& newTitle)
	{
		BaseWindow::setTitle(newTitle);
	}

	void Window::display()
	{
		switchToDefaultBuffer();
		BaseWindow::display();
	}
	void Window::displayPostBuffer()
	{
		switchToDefaultBuffer();
		glCheck(glBindVertexArray(quadVAO));
		{
			glCheck(glDisable(GL_DEPTH_TEST));
			glCheck(glDisable(GL_STENCIL_TEST));
			glCheck(glUseProgram(shaderProgram_screenDiffuse));
			//texColorBuffer.bind();
			//draw the 2D quad
			glCheck(glDrawArrays(GL_TRIANGLES, 0, 6));
			BaseWindow::display();
		}
		glCheck(glBindVertexArray(0));
	}
	void Window::displayDepthBuffer()
	{
		switchToDefaultBuffer();
		glCheck(glBindVertexArray(quadVAO));
		{
			glCheck(glDisable(GL_DEPTH_TEST));
			glCheck(glDisable(GL_STENCIL_TEST));
			glCheck(glUseProgram(shaderProgram_screenDepth));
			//texColorBuffer.bind();
			//draw the 2D quad
			glCheck(glDrawArrays(GL_TRIANGLES, 0, 6));
			BaseWindow::display();
		}
		glCheck(glBindVertexArray(0));
	}
	void Window::clear(unsigned int red, unsigned int green, unsigned int blue)
	{
		BaseWindow::clear(sf::Color(red, green, blue));
	}
	void Window::clearDepth()
	{
		glCheck(glClear(GL_DEPTH_BUFFER_BIT));
	}

	void Window::recreateNoDecoration(unsigned int newWidth, unsigned int newHeight)
	{
		create(newWidth, newHeight, sf::Style::None);
	}
	void Window::recreateWindowed(unsigned int newWidth, unsigned int newHeight)
	{
		create(newWidth, newHeight, sf::Style::Default);
	}
	void Window::recreateFullScreen()
	{
		create(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height, sf::Style::Fullscreen);
	}
	void Window::close()
	{
		if (isOpen())
		{
			BaseWindow::close();
		}
		glDeleteBuffers(1, &postBuffer);
		glDeleteVertexArrays(1, &quadVAO);
	}
	bool Window::isOpen()
	{
		return BaseWindow::isOpen();
	}
	void Window::switchToPostBuffer()
	{
		switchActiveBuffer(postBuffer);
	}
	void Window::switchToDefaultBuffer()
	{
		switchActiveBuffer(0);
	}
	void Window::drawDiffuse(const DrawableDT& drawableDT, const sf::RenderStates& states)
	{
		drawableDT.drawDiffuse(*this, states);
	}
	void Window::drawDepth(const DrawableDT& drawableDT, const sf::RenderStates& states)
	{
		drawableDT.drawDepth(*this, states);
	}
	void Window::drawDT(const DrawableDT& drawableDT, float positionalDepth, const sf::RenderStates& states)
	{
		drawableDT.draw(*this, positionalDepth, states);
	}
	void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states)
	{
		BaseWindow::draw(drawable, states);
	}
	void Window::draw(const sf::Vertex vertices[4], float positionalDepth,
		const sf::RenderStates& states)
	{
		switchToPostBuffer();
		glCheck(glUseProgram(shaderProgram_sfmlDT));
		{
			glCheck(glEnable(GL_DEPTH_TEST));

			//--------------------->bind null to the depth texture sampler unit
			glCheck(glActiveTexture(TEXUNIT_depth));
			glCheck(glBindTexture(GL_TEXTURE_2D, 0));

			//--------------------->ensure SFML binds diffuse texture to diffuse sampler unit when drawn
			glCheck(glActiveTexture(TEXUNIT_diffuse));

			glCheck(glUniform1f(shaderUniform_sfmlDT_positionalDepth, positionalDepth));

			BaseWindow::draw(vertices, 4, sf::TrianglesStrip, states);
		}
	}
	void Window::draw(const sf::Vertex vertices[4], const sf::Texture* depthTexture, 
		float positionalDepth, const sf::RenderStates& states)
	{
		if (!depthTexture)
		{
			//TODO: maybe add a default blank depth texture instead of skipping entirely?
			return;
		}
		switchToPostBuffer();
		glCheck(glUseProgram(shaderProgram_sfmlDT));
		{
			glCheck(glEnable(GL_DEPTH_TEST));

			//--------------------->bind the depth texture to the depth texture sampler unit
			glCheck(glActiveTexture(TEXUNIT_depth));
			sf::Texture::bind(depthTexture);

			//--------------------->ensure SFML binds diffuse texture to diffuse sampler unit when drawn
			glCheck(glActiveTexture(TEXUNIT_diffuse));

			glCheck(glUniform1f(shaderUniform_sfmlDT_positionalDepth, positionalDepth));


			BaseWindow::draw(vertices, 4, sf::TrianglesStrip, states);

			//--------------------->unbind depth texture sampler units
			glCheck(glActiveTexture(TEXUNIT_depth));
			glCheck(glBindTexture(GL_TEXTURE_2D, 0));
		}
	}
	bool Window::saveCapture(const std::string& filename) const
	{
		return BaseWindow::capture().saveToFile(filename);
	}
	float Window::getPositionalDepth(float yPos) const
	{
		return (static_cast<float>(BaseWindow::mapCoordsToPixel(sf::Vector2f(0.0f, yPos)).y)
			/
			static_cast<float>(getHeight())
			* 0.5f);
	}

	//-----------------------------------------------------------------------
	//				PRIVATE/PROTECTED FUNCTIONS
	//-----------------------------------------------------------------------

	void Window::create(unsigned int newWidth, unsigned int newHeight, unsigned long style)
	{
		//note: this function may be called multiple times
		width = newWidth;
		height = newHeight;
		sf::ContextSettings settings;
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.antialiasingLevel = 2;
		BaseWindow::create(sf::VideoMode(width, height), "DungeonRaider Window", style, settings);
		BaseWindow::setFramerateLimit(120);
		//window.setVerticalSyncEnabled(true);

		create2DVAO();
		createFrameBuffers(); //should be after the window is created, so sfml doesn't mess with the framebuffer
	}
	void Window::createFrameBuffers()
	{
		//create postbuffer
		glGenFramebuffers(1, &postBuffer);
		printf("framebuffer after gen: %u \n", postBuffer);

		switchActiveBuffer(postBuffer);
		{
			//create texture to render framebuffer to 
			texColorBuffer.createUnboundTexture(width, height, TEXUNIT_texColorBuffer);
			texColorBuffer.bind();
			glCheck(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texColorBuffer.getTextureID(), 0));
			glCheck(glUseProgram(shaderProgram_screenDiffuse));
			{
				glCheck(glUniform1i(glGetUniformLocation(shaderProgram_screenDiffuse, "texColorbuffer"), texColorBuffer.getSamplerUnit()));
			}
			glCheck(glUseProgram(shaderProgram_screenDepth));
			{
				glCheck(glUniform1i(glGetUniformLocation(shaderProgram_screenDepth, "texColorbuffer"), texColorBuffer.getSamplerUnit()));
			}
			checkFramebufferError(glCheckFramebufferStatus(GL_FRAMEBUFFER));
			//create a texture to store depth and stencil image
			texDepthStencil.createUnboundTexture(width, height, TEXUNIT_texDepthStencil, GL_DEPTH_STENCIL);
			texDepthStencil.bind();
			glCheck(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texDepthStencil.getTextureID(), 0));
			glCheck(glUseProgram(shaderProgram_screenDiffuse));
			{
				glCheck(glUniform1i(glGetUniformLocation(shaderProgram_screenDiffuse, "texDepthStencil"), texDepthStencil.getSamplerUnit()));
			}
			glCheck(glUseProgram(shaderProgram_screenDepth));
			{
				glCheck(glUniform1i(glGetUniformLocation(shaderProgram_screenDepth, "texDepthStencil"), texDepthStencil.getSamplerUnit()));
			}
			checkFramebufferError(glCheckFramebufferStatus(GL_FRAMEBUFFER));
		}
		switchActiveBuffer(0);

		glCheck(glBindRenderbuffer(GL_RENDERBUFFER, 0));
	}
	void Window::create2DVAO()
	{
		//create vertex array object
		glCheck(glGenVertexArrays(1, &quadVAO));
		glCheck(glBindBuffer(GL_ARRAY_BUFFER, quadVBO)); //bind vbo
		glCheck(glUseProgram(shaderProgram_screenDiffuse));
		{
			glCheck(glBindVertexArray(quadVAO));
			{
				//set screen vertex attributes
				GLint posCoord = glGetAttribLocation(shaderProgram_screenDiffuse, "position");
				{
					glCheck(
						glVertexAttribPointer(posCoord,
						2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0)
						);
					glCheck(glEnableVertexAttribArray(posCoord););
					posCoord = glGetAttribLocation(shaderProgram_screenDepth, "position");
					glCheck(
						glVertexAttribPointer(posCoord,
						2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0)
						);
					glCheck(glEnableVertexAttribArray(posCoord););
				}
				GLint texCoord = glGetAttribLocation(shaderProgram_screenDiffuse, "texCoord");
				{
					glCheck(
						glVertexAttribPointer(texCoord,
						2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)))
						);
					glCheck(glEnableVertexAttribArray(texCoord););
					texCoord = glGetAttribLocation(shaderProgram_screenDepth, "texCoord");
					glCheck(
						glVertexAttribPointer(texCoord,
						2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)))
						);
					glCheck(glEnableVertexAttribArray(texCoord););
				}
			}
			glCheck(glBindVertexArray(0)); //unbind vao
		}
		glCheck(glBindBuffer(GL_ARRAY_BUFFER, 0)); //unbind vbo
	}
	void Window::switchActiveBuffer(GLuint buffer)
	{
		if (activeBuffer != buffer)
		{
			glCheck(glBindFramebuffer(GL_FRAMEBUFFER, buffer));
			
			activeBuffer = buffer;
		}
	}

	void Window::initStatics()
	{
		if (!staticsInitialized)
		{
			//create sfml shaders----------------------
			shaderProgram_sfmlDT = createShaderProgram(
				"Shaders/SFML_with_depth.vert",
				"Shaders/SFML_with_depth.frag",
				shader_sfmlDTVert,
				shader_sfmlDTFrag);
			//-----------------------------------------


			shaderUniform_sfmlDT_positionalDepth = glGetUniformLocation(shaderProgram_sfmlDT, "positionalDepth");
			GLuint diffuseLoc = glGetUniformLocation(shaderProgram_sfmlDT, "texture");
			GLuint depthLoc = glGetUniformLocation(shaderProgram_sfmlDT, "depthTexture");
			glCheck(glUseProgram(shaderProgram_sfmlDT));
			{
				glCheck(glUniform1f(shaderUniform_sfmlDT_positionalDepth, 0.0f));
				glCheck(glUniform1i(diffuseLoc, TEXUNIT_diffuse - GL_TEXTURE0));
				glCheck(glUniform1i(depthLoc, TEXUNIT_depth - GL_TEXTURE0));
			}

			//create screen program shaders-----------
			shaderProgram_screenDiffuse = createShaderProgram(
				"Shaders/VertexShaderSimple2D.glsl", 
				"Shaders/FragmentShaderSimple2D.glsl", 
				shader_screenVert,
				shader_screenFrag);

			shader_screenFragDepth = MyGLFunctions::createShaderFromFile(GL_FRAGMENT_SHADER, "Shaders/FragmentShaderSimple2D_depth.frag");
			shaderProgram_screenDepth = glCheck(glCreateProgram());
			glCheck(glAttachShader(shaderProgram_screenDepth, shader_screenVert));
			glCheck(glAttachShader(shaderProgram_screenDepth, shader_screenFragDepth));
			glCheck(glBindFragDataLocation(shaderProgram_screenDepth, 0, "outColor"));
			glCheck(glLinkProgram(shaderProgram_screenDepth));


			//create vertices of 2D quad and upload to GPU
			float quadVertices[] = {
				//posX	posY	texS	texT
				-1.0f, 1.0f, 0.0f, 1.0f,
				1.0f, 1.0f, 1.0f, 1.0f,
				1.0f, -1.0f, 1.0f, 0.0f,

				1.0f, -1.0f, 1.0f, 0.0f,
				-1.0f, -1.0f, 0.0f, 0.0f,
				-1.0f, 1.0f, 0.0f, 1.0f
			};
			glCheck(glGenBuffers(1, &quadVBO));
			glCheck(glBindBuffer(GL_ARRAY_BUFFER, quadVBO));
			glCheck(glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW)); //upload vertice data to GPU
			//-----------------------------------------
		}
		//if gl already initialized, do nothing
	}
	void Window::uninitStatics()
	{
		if (extantWindows <= 0)
		{
			glDeleteProgram(shaderProgram_screenDiffuse);
			glDeleteShader(shader_screenVert);
			glDeleteShader(shader_screenFrag);
			glDeleteProgram(shaderProgram_screenDepth);
			glDeleteShader(shader_screenFragDepth);

			glDeleteProgram(shaderProgram_sfmlDT);
			glDeleteShader(shader_sfmlDTFrag);
			glDeleteShader(shader_sfmlDTVert);
			

			glDeleteBuffers(1, &quadVBO);

			staticsInitialized = false;
		}
	}
	GLuint Window::createShaderProgram(const std::string& vertSourcePath, const std::string& fragSourcePath, GLuint& vertShader, GLuint& fragShader)
	{
		vertShader = MyGLFunctions::createShaderFromFile(GL_VERTEX_SHADER, vertSourcePath);
		fragShader = MyGLFunctions::createShaderFromFile(GL_FRAGMENT_SHADER, fragSourcePath);
		GLuint shaderProgram = glCreateProgram();
		glCheck(glAttachShader(shaderProgram, vertShader));
		glCheck(glAttachShader(shaderProgram, fragShader));
		glCheck(glBindFragDataLocation(shaderProgram, 0, "outColor"));
		glCheck(glLinkProgram(shaderProgram));
		return shaderProgram;
	}
	void checkFramebufferError(GLenum error)
	{
		switch (error)
		{
		case GL_FRAMEBUFFER_COMPLETE:
			printf("framebuffer complete!\n");
			break;
		case GL_FRAMEBUFFER_UNDEFINED:
			printf("ERROR: GL_FRAMEBUFFER_UNDEFINED\n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT\n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT\n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER \n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER \n");
			break;
		case GL_FRAMEBUFFER_UNSUPPORTED:
			printf("ERROR: GL_FRAMEBUFFER_UNSUPPORTED \n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE \n");
			break;
		case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
			printf("ERROR: GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS  \n");
			break;
		default:
			printf("Error returning framebuffer status: unknown error\n");
			break;
		}
	}

	//static variable stuff
	GLuint Window::shaderProgram_sfmlDT = 0;
	GLuint Window::shader_sfmlDTFrag = 0;
	GLuint Window::shader_sfmlDTVert = 0;
	GLint Window::shaderUniform_sfmlDT_positionalDepth = 0;
	GLuint Window::quadVBO = 0;
	GLuint Window::shaderProgram_screenDiffuse = 0;
	GLuint Window::shaderProgram_screenDepth = 0;
	GLuint Window::shader_screenVert = 0;
	GLuint Window::shader_screenFrag = 0;
	GLuint Window::shader_screenFragDepth = 0;
	bool Window::staticsInitialized = false;
	int Window::extantWindows = 0;
}

