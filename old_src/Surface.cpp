#include "Surface.h"



Surface::Surface(std::string title, unsigned int, unsigned int) :
	title(title), width(width), height(height), window(0), contextGL(0), isAlive(false)
{
}

Surface::~Surface()
{
	SDL_GL_DeleteContext(contextGL);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Surface::initWindow()
{
	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error SDL init:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}


	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	// Init Window
	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (window == 0) {
		std::cout << "Error SDL window:" << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	// Create Opengl context

	contextGL = SDL_GL_CreateContext(window);

	if (contextGL == 0) {
		std::cout << "Error GL context:" << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	// all is done.
	winState = true;
	return true;
}

bool Surface::initGL()
{
	//init GLEW
	glewExperimental = GL_TRUE;
	GLenum initGLEW(glewInit());

	if (initGLEW != GLEW_OK) {
		std::cout << "Error GL glew:" << glewGetErrorString(initGLEW) << std::endl;

		SDL_GL_DeleteContext(contextGL);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}

	// Depth Buffer

	glEnable(GL_DEPTH_TEST);

	// all is done
	glState = true;
	return true;
}

void Surface::run(Scene scn)
{
	currentScene = scn;

	initWindow();
	initGL();
	isAlive = true;
	main_loop();
}

void Surface::main_loop()
{
	unsigned int frameRate(1000 / 50);
	Uint32 startLoop(0), endLoop(0), dtLoop(0);

	//loop

	while (isAlive) {
		startLoop = SDL_GetTicks();

		currentScene.inputManager();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		currentScene.drawManager();

		SDL_GL_SwapWindow(window);

		endLoop = SDL_GetTicks();
		dtLoop = endLoop - startLoop;

		if (dtLoop < frameRate) {
			SDL_Delay(frameRate - dtLoop);
		}

	}
}
