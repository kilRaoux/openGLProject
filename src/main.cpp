/*
Fonctionnement general du Moteur:
->definire une fenetre grace a la une instance de la classe Window
	cette classe va generer plusieur managers dont un InputManageur qui permet de
	gerer les inputs claviers souris. on peut le recuperer grace a la methode
	"InputManager* getInputManager()"
-> definire une scene qui permetra de gerer les objets du jeu (gameobject,...)
-> definire une camera et utiliser la methode "void setCamera(ICamera*)" de la classe
	Scene.
*/
#include <SDL.h>
#include <GL/glew.h>
#include "SceneObject/Window.h"
#include "SceneObject/Scene.h"
#include "SceneObject/InputManager.h"
#include "SceneObject/camera/CameraFirstPersonne.h"
#include "GameObject\GameObject.h"
#include "GameObject/ObjLoader.h"

//#include "GameObject/renderData.h"
#include "debugFoo.h"

#include "GameObject/ObjLoader.h"
#include <iostream>
int main(int argc, char **argv)
{
	ObjLoader *objLoader = new ObjLoader();
	renderData data = objLoader->parse("res\\obj3D\\cube.txt");
	int width = 1000;
	int height = 1000;
	Window *win = new Window(1000, 1000);
	InputManager* input = win->getInputManager();
	Scene  *scn = new Scene(input, 1000,1000);
	CameraFirstPersonne *camera = new CameraFirstPersonne(input, width, height);
	scn->setCamera(camera);
	scn->addGameObject(new GameObject(&data));
	win->run(scn);
	std::cin.get();
    return 0;
}
