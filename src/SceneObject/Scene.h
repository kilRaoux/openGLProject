#pragma once
#include "..\GLObject\VertexBufferObject.h"
#include "..\GameObject\GameObject.h"
#include "InputManager.h"
#include "camera/ICamera.h"
#include <vector>
#include <glm/glm.hpp>
#include <SDL.h>

/*
@desc Classe definissant le fonctionnement d'une scene du jeu
*/
class Scene
{
public:
	Scene(InputManager*input, int width, unsigned int height);
	~Scene();
	void eventManager();
	void draw();
	int addGameObject(GameObject *go);
	void setCamera(ICamera *camera);
	void setInput(InputManager *input);
	void update();
	void init();
private:
	unsigned int m_width, m_height;
	ICamera	*m_camera;
	InputManager *m_input;
	VertexBufferObject *vbo;
	std::vector<GameObject*> gameObjects;
};

