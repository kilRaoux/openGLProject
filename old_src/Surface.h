#pragma once
#include <GL/glew.h>



// Includes GLM

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// Autres includes

#include <SDL.h>
#include <iostream>
#include <string>
#include "Scene.h"

class Surface
{
public:
	Surface(std::string title,
		unsigned int,
		unsigned int);
	~Surface();
	bool initWindow();
	bool initGL();
	void run(Scene scn);
private:
	void main_loop();
	std::string title;
	unsigned int width, height;
	bool winState, glState;
	bool isAlive;

	SDL_Window* window;
	SDL_GLContext contextGL;
	Scene currentScene;

};

