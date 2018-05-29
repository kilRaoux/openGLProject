/*
La classe Window permet l'affichage d'une fenetre et l'initialisation d'OpenGL.
Fonctionnement:
	L'instanciation de la classe permet les initialisation.
	Pour lancer la fenetre il suffit dappeler la methode "void run(Scene)" qui
		prend en parametre la Premiere scene de jeu.
*/
#pragma once
#include "..\GLObject\VertexBufferObject.h"
#include "..\SceneObject\Scene.h"
#include "InputManager.h"
#include <SDL.h>

class Window
{
public:
	Window(unsigned int width, unsigned int height);
	~Window();
	InputManager* getInputManager();
	void run(Scene *scn);
private:
	void initGLEW();
	void initSDL();
	void mainLoop();

	unsigned int m_width, m_height;
	bool isAlive;
	SDL_Window *window;
	SDL_GLContext contexte;
	SDL_Event *events;
	InputManager m_input;
	Scene *m_scene;


};

