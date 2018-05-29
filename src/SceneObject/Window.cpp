#include "Window.h"
#include "..\debugFoo.h"

Window::Window(unsigned int width, unsigned int height):
	m_width(width), m_height(height), window(0), contexte(0),m_input()
{
	initSDL();
	initGLEW();
}


Window::~Window()
{
	LOG(">Destruction de la fenetre");
	SDL_GL_DeleteContext(contexte);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

InputManager * Window::getInputManager()
{
	return &m_input;
}

void Window::run(Scene *scn)
{
	m_scene = scn;
	mainLoop();
}

void Window::initGLEW()
{
	GLenum initGlewEnum(glewInit());
	glewExperimental = true;
	if (initGlewEnum != GLEW_OK) {
		LOG("[OpenGL] Error : Probleme dans l'initialisation de glew");
	}
}

void Window::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("<!>Error: initialisation de la SDL");
		SDL_Quit();
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow("Test SDL 2.0",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		m_width, m_height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	contexte = SDL_GL_CreateContext(window);

	if (contexte == 0) {
		LOG("<!> Error : GLContext mal definie");
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

}

void Window::mainLoop()
{
	isAlive = true;
	unsigned int begin;
	unsigned int deltaTime;
	unsigned int fps = 1000 / 60;
	while (!m_input.terminer()) {
		begin = SDL_GetTicks();
		m_input.update();
		m_scene->update();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_scene->draw();

		SDL_GL_SwapWindow(window);

		deltaTime = SDL_GetTicks() - begin;
		if (deltaTime < fps)
			SDL_Delay(fps - deltaTime);
	}

}
