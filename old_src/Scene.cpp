#include "Scene.h"

// Includes GLM

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Scene::Scene() :
	m_camera(Camera()),
	m_input(Input())
{
}


Scene::~Scene()
{
}

bool Scene::drawManager()
{
	m_camera.deplacer(m_input);

	for (unsigned int i = 0; 0 != list_GO.size(); ++i) {
		list_GO[i]->draw();
	}

	return false;
}
bool Scene::inputManager()
{
	m_input.updateEvenements();
	if (m_input.getTouche(SDL_SCANCODE_ESCAPE))
		return true;
	return false;
}
/* GET/SET */
void Scene::set_camera(Camera cam)
{
	m_camera = cam;
}

void Scene::set_input(Input in)
{
	m_input = in;
}

unsigned int Scene::add_GO(GameObject * go)
{
	list_GO.push_back(go);
	return 0;
}

Camera Scene::get_camera()
{
	return m_camera;
}

Input Scene::get_input()
{
	return m_input;
}
