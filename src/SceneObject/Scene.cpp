#include "Scene.h"
#include "GL/glew.h"
#include "..\debugFoo.h"


Scene::Scene(InputManager *input, int width, unsigned int height) :
	m_width(width), m_height(height), m_input(input)
{
}


Scene::~Scene()
{
	delete vbo;
}

void Scene::draw()
{
	if (m_camera == nullptr) {
		std::cout << "error camera nullptr" << std::endl;
		return;
	}
	glm::mat4 PV = m_camera->getMatrix();
	for (unsigned int i = 0; i < gameObjects.size(); i++)
		gameObjects[i]->draw(PV);
}

void Scene::eventManager()
{
}

int Scene::addGameObject(GameObject * go)
{
	gameObjects.push_back(go);
	return 0;
}

void Scene::setCamera(ICamera * camera)
{
	if (m_input == nullptr)
	{
		std::cout << "Error : L'InputManager n'est pas definie" << std::endl;
		return;
	}
	m_camera = camera;
	camera->init(m_input, m_width, m_height);
	if (m_camera == nullptr)
		std::cout << "Error : la camera na pas ete correctement definie" << std::endl;
}

void Scene::setInput(InputManager *input)
{
	m_input = input;
}

void Scene::update()
{
	m_camera->update();
}

void Scene::init()
{
	addGameObject(new GameObject);
}
