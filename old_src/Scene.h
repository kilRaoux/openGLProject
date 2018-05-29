#pragma once
#ifndef DEF_SCENE
#define DEF_SCENE
/* OpenGL include */
#include <GL/glew.h>

/* Mathematique */
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* std/SDL */
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>

/* Local include */
#include "Input.h"
#include "Camera.h"
#include "GameObject.h"

/* Classe Gerant les Objects du jeu */
class Scene
{
public:
	Scene();
	~Scene();
	bool drawManager();
	bool inputManager();
	void set_camera(Camera cam);
	void set_input(Input in);
	unsigned int add_GO(GameObject * go);
	Camera get_camera();
	Input get_input();
private:
	Input m_input;
	Camera m_camera;
	std::vector<GameObject*> list_GO;
	glm::mat4 matrix_projection;
	glm::mat4 * matrix_view;
};

#endif