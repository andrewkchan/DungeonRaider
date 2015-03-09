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


char buffer[512]; //debug log buffer


int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2;
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Close, settings);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Failed to initialize GLEW\n");
		return 1;
	}

	//create vertex array object (VAO)
	GLuint vertexArrayObject;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);



	static float vertices[] = {
		//posX	posY   posZ  R     G	 B     texS  texT
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};
	GLuint vertexBufferObj; //creates VBO, vertex buffer object (uint holding address of buffer)
	glGenBuffers(1, &vertexBufferObj); //generate 1 buffer with vertexBuffer as reference to it
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj); //make vertex buffer the active array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //allocate data to the active array buffer
	printf("vertexBuffer: %u \n", vertexBufferObj);

	static GLuint elements[] = {
		0, 1, 2, //tri 0
		0, 3, 1  //tri 1
	};
	GLuint elementBufferObj;
	glGenBuffers(1, &elementBufferObj);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObj);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	//----------------shaders-----------------------------

	//declare and compile vertex shader (definition outside of main)
	GLuint vertexShader = MyGLFunctions::createShaderFromFile(GL_VERTEX_SHADER, "Shaders/VertexShader.glsl");
	//declare and compile fragment shader
	GLuint fragmentShader = MyGLFunctions::createShaderFromFile(GL_FRAGMENT_SHADER, "Shaders/FragmentShader.glsl");

	//check shader compilation statuses
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		printf("vertexShader did not compile successfully\n");
	}
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		printf("fragmentShader did not compile successfully\n");
	}
	//glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
	//printf("%s\n", buffer);


	//-----link the vertex and fragment shaders into a shader program---------
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor"); //not necessary?
	glLinkProgram(shaderProgram); //apply changes of program
	glUseProgram(shaderProgram);

	//specify layout of vertex data
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
	glEnableVertexAttribArray(posAttrib);
	GLint colAttrib = glGetAttribLocation(shaderProgram, "inVColor");
	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(3 * sizeof(float)));
	glEnableVertexAttribArray(colAttrib);
	GLint texAttrib = glGetAttribLocation(shaderProgram, "texCoord");
	glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), reinterpret_cast<void*>(6 * sizeof(float)));
	glEnableVertexAttribArray(texAttrib);


	//----------------texture object-------------------
	
	MyGL::Texture texture1;
	texture1.loadFromFile("Textures/zachsq.jpg", 0);
	glUniform1i(glGetUniformLocation(shaderProgram, "texSeptember"), texture1.getSamplerUnit());
	MyGL::Texture texture2;
	texture2.loadFromFile("Textures/test2.png", 1);
	glUniform1i(glGetUniformLocation(shaderProgram, "texPuppy"), texture2.getSamplerUnit());

	//--------transformations---------------------------

	glm::mat4 modelTrans;
	modelTrans = glm::rotate(modelTrans, glm::radians(180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	GLint uniTrans = glGetUniformLocation(shaderProgram, "modelTrans");
	glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(modelTrans));

	glm::mat4 viewTrans;
	viewTrans = glm::lookAt(glm::vec3(1.2f, 1.2f, 1.2),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f));
	GLint uniView = glGetUniformLocation(shaderProgram, "viewTrans");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(viewTrans));

	glm::mat4 projTrans = glm::perspective(45.0f, 800.0f / 600.0f, 1.0f, 10.0f);
	GLint uniProj = glGetUniformLocation(shaderProgram, "projTrans");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(projTrans));

	
	sf::Clock clock;
	float deltaTime; //time between frames
	float prevFrameTime = clock.getElapsedTime().asSeconds();
	float rotateX = 0.0f;
	while (window.isOpen())
	{
		deltaTime = clock.getElapsedTime().asSeconds() - prevFrameTime;
		prevFrameTime = clock.getElapsedTime().asSeconds();
		printf("deltaTime : %f \n", deltaTime);
		sf::Event event;
		window.clear();
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
		glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(modelTrans));
		glUniform1f(glGetUniformLocation(shaderProgram, "size"), fabs(sinf(clock.getElapsedTime().asSeconds())));
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		//draw cube
		glDrawArrays(GL_TRIANGLES, 0, 36);
		window.display();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close(); //do NOT call any opengl functions after this!
		}
	}

	glDeleteProgram(shaderProgram);
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteBuffers(1, &vertexBufferObj);
	glDeleteVertexArrays(1, &vertexArrayObject);

	return 0;
}