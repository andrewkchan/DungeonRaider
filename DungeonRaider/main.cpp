#include <GL/glew.h>
#include "Game.h"
#include "GameStateMainMenu.h"
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include "MyGLFunctions.h"
#include "MyGLTexture.h"
#include <math.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "GraphicsWrappers\Window.h"
#include "GraphicsWrappers\GLCheck.h"

/*
Dungeon Raider, an isometric 2D procedurally generated action-RPG.

*/

/*
int main(int argc, char* args[])
{
	
	Game game;
	game.pushState(new GameStateMainMenu(&game));
	game.runGameLoop();
	


	std::cin.clear();
	std::cin.ignore(255, '\n');
	std::cin.get();
	
	return 0;
}
*/

#include "GraphicsWrappers\Sprite.h"
#include "GraphicsWrappers\Texture.h"

int main(int argc, char* args[])
{
	gWrap::Window window;
	window.recreateWindowed(800, 600);

	sf::Texture diffuse;
	diffuse.loadFromFile("Textures/calcunaut1.png");
	sf::Texture depth;
	depth.loadFromFile("Textures/calcunaut1depth.png");
	sf::Texture background;
	background.loadFromFile("UserData/Captures/capture01.png");

	gWrap::Sprite sprite;
	sprite.setDiffuseTex(diffuse);
	sprite.setDepthTex(depth);
	gWrap::Sprite back;
	back.setDiffuseTex(background);
	back.setDepthTex(background);
	back.setOrigin(0.0f, 0.0f);

	gWrap::Sprite sprite2;
	sprite2.setDiffuseTex(diffuse);
	sprite2.setDepthTex(depth);
	sprite2.setPosition(100.0f, 0.0f);

	sf::Transformable spriteTransform;
	float spriteX = 0.0f;
	float spriteY = 0.0f;

	sf::View view1;
	view1.setSize(sf::Vector2f(400, 400));
	view1.setCenter(2.0f, 2.0f);
	window.setView(view1);
	

	while (window.isOpen())
	{
		window.switchToPostBuffer();
		window.clear(255, 255, 255);
		window.clearDepth();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			spriteX += -1.0f;
			std::cout << "x:\t" << spriteX << "y:\t" << spriteY << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			spriteX += 1.0f;
			std::cout << "x:\t" << spriteX << "y:\t" << spriteY << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			spriteY += 1.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			spriteY += -1.0f;
		}
		//spriteTransform.setPosition(sf::Vector2f(spriteX, spriteY));
		sprite.setPosition(sf::Vector2f(spriteX, spriteY));

		window.drawDT(sprite, window.getPositionalDepth(spriteY));
		std::cout << "positionalDepth:" << window.getPositionalDepth(spriteY) << "\ty:" << spriteY << std::endl;
		window.drawDT(sprite2);
		window.drawDT(back, false);
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				window.displayDepthBuffer();
			}
			else
			{
				window.displayPostBuffer();
			}
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); //do NOT call any opengl functions after this!
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::P)
				{
					window.saveCapture("UserData/Captures/capture.png");
				}
			}
		}
	}
}

/*
int main()
{

	gWrap::Window window;
	window.recreateWindowed(800, 600);
	//create vertex array object (VAO)
	GLuint vertexArrayObject;
	glCheck(glGenVertexArrays(1, &vertexArrayObject));
	glCheck(glBindVertexArray(vertexArrayObject));
	printf("vertexArrayObject: %u \n", vertexArrayObject);

	static float vertices[] = {
		//posX	posY   posZ  R     G	 B     texS  texT
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, //0
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, //6
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, //12
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 

		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, //18
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, //24
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, //30
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		//-----------------------Floor vertices--------------------
		- 1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, //36
		1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
	};

	GLuint vertexBufferObj; //creates VBO, vertex buffer object (uint holding address of buffer)
	glGenBuffers(1, &vertexBufferObj); //generate 1 buffer with vertexBuffer as reference to it
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj); //make vertex buffer the active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //allocate data to the active array buffer
	printf("vertexBuffer: %u \n", vertexBufferObj);
	//----------------shaders-----------------------------

	//declare and compile vertex shader (definition outside of main)
	GLuint vertexShader = MyGLFunctions::createShaderFromFile(GL_VERTEX_SHADER, "Shaders/VertexShader.glsl");
	//declare and compile fragment shader
	GLuint fragmentShader = MyGLFunctions::createShaderFromFile(GL_FRAGMENT_SHADER, "Shaders/FragmentShader.glsl");

	//-----link the vertex and fragment shaders into a shader program---------
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor"); //not necessary?
	glLinkProgram(shaderProgram); //apply changes of program, upload shaders to gpu
	glUseProgram(shaderProgram);
	
	
	//specify layout of vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glCheck(glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0));
	glCheck(glEnableVertexAttribArray(posAttrib));
	GLint colAttrib = glGetAttribLocation(shaderProgram, "inVColor");
	glCheck(glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float))));
	glCheck(glEnableVertexAttribArray(colAttrib));
	GLint texAttrib = glGetAttribLocation(shaderProgram, "texCoord");
	glCheck(glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float))));
	glCheck(glEnableVertexAttribArray(texAttrib));



	//----------------texture object-------------------
	
	MyGL::Texture texture1;
	texture1.loadFromFile("Textures/test.bmp", GL_TEXTURE5);
	MyGL::Texture texture2;
	texture2.loadFromFile("Textures/test2.png", GL_TEXTURE6);
	glCheck(glUseProgram(shaderProgram));
	{
		glCheck(glUniform1i(glGetUniformLocation(shaderProgram, "texSeptember"), texture1.getSamplerUnit()));
		glCheck(glUniform1i(glGetUniformLocation(shaderProgram, "texPuppy"), texture2.getSamplerUnit()));
	}
	texture1.bind();
	texture2.bind();

	//--------transformations---------------------------

	glm::mat4 modelTrans;
	modelTrans = glm::rotate(modelTrans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	GLint uniModel = glGetUniformLocation(shaderProgram, "modelTrans");
	glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glm::mat4 viewTrans;
	viewTrans = glm::lookAt(
		glm::vec3(2.0f, 2.0f, 2.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f));
	GLint uniView = glGetUniformLocation(shaderProgram, "viewTrans");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(viewTrans));

	glm::mat4 projTrans = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "projTrans");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(projTrans));

	//enable openGL depth testing
	glEnable(GL_DEPTH_TEST);
	GLint uniAlpha = glGetUniformLocation(shaderProgram, "alpha");

	
	sf::Clock clock;
	float deltaTime; //time between frames
	float prevFrameTime = clock.getElapsedTime().asSeconds();
	float rotateX = 0.0f;
	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds() - prevFrameTime;
		prevFrameTime = clock.getElapsedTime().asSeconds();
		
		//read input------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			rotateX += deltaTime * 180.0f;
		}
		else
		{
			if (rotateX > 0.0f)
				rotateX -= deltaTime * 180.0f;
		}
		modelTrans = glm::rotate(modelTrans, glm::radians(deltaTime * 90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		modelTrans = glm::rotate(modelTrans, glm::radians(deltaTime * rotateX), glm::vec3(1.0f, 0.0f, 0.0f));
		glCheck(glUseProgram(shaderProgram));
		{
			glCheck(glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(modelTrans)));
			glCheck(glUniform1f(uniAlpha, 1.0f));
		}
		//------------------------------------------DRAWING OPERATIONS-------------------------------
		window.switchToPostBuffer();
		//clear window-----------------------------------
		window.clearDepth();
		window.clear(255, 255, 255);
		glCheck(glBindVertexArray(vertexArrayObject));
		//draw cube-----------------------------
		glCheck(glDepthMask(GL_TRUE));
		glCheck(glEnable(GL_DEPTH_TEST));
		glCheck(glDrawArrays(GL_TRIANGLES, 0, 36));
		//draw floor----------------------------
		glCheck(glDepthMask(GL_FALSE)); //don't write to depth buffer
		glCheck(glEnable(GL_STENCIL_TEST));
		glCheck(glStencilFunc(GL_ALWAYS, 1, 0xFF));
		glCheck(glStencilMask(0xFF)); //allow writing to stencil buffer
		glCheck(glClear(GL_STENCIL_BUFFER_BIT)); //clear to 0 (counts as writing to stencil buffer, mask must be set to 0xFF before this!)
		glCheck(glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE)); //write stencil val 1 for all pixels drawn here
		glCheck(glDrawArrays(GL_TRIANGLES, 36, 6)); //draw floor vertices
		//draw cube reflection------------------
		glCheck(glUniform1f(uniAlpha, 0.3f));
		glCheck(glDepthMask(GL_TRUE));
		glCheck(glStencilFunc(GL_EQUAL, 1, 0xFF)); //only draw reflection when stencil val is 1
		glCheck(glStencilMask(0x00)); //don't write to stencil buffer when drawing reflection!
		modelTrans = glm::scale(
			glm::translate(modelTrans, glm::vec3(0.0f, 0.0f, -1.0f)),
			glm::vec3(1.0f, 1.0f, -1.0f)
			);
		glCheck(glUniformMatrix4fv(uniModel, 1, GL_FALSE, glm::value_ptr(modelTrans)));
		glCheck(glDrawArrays(GL_TRIANGLES, 0, 36)); //draw the actual reflection vertices
		glCheck(glDisable(GL_STENCIL_TEST));
		modelTrans = glm::scale(
			glm::translate(modelTrans, glm::vec3(0.0f, 0.0f, -1.0f)),
			glm::vec3(1.0f, 1.0f, -1.0f)
			);
		//---------------display stuff---------
		//window.display();
		//now draw post buffer-------------
		window.displayPostBuffer();
		
		
		
		
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); //do NOT call any opengl functions after this!
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::P)
				{
					window.saveCapture("UserData/Captures/capture01.png");
				}
			}
		}
	}

	
	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteBuffers(1, &vertexBufferObj);
	glDeleteVertexArrays(1, &vertexArrayObject);

	return 0;
}
*/

