#pragma once

#include "..\InputManager.h"
#include "ICamera.h"
#include <glm/glm.hpp>
#include "glm/gtc/matrix_transform.hpp"
class CameraFirstPersonne :
	public ICamera
{
public:
	CameraFirstPersonne(InputManager *input, int width, int height);
	~CameraFirstPersonne();
	void update();
private:
	InputManager * m_input;
	void orientation();
	void move();
	glm::vec3 m_lateralMove;
	glm::vec3 m_orientation;
	float m_phi, m_theta;
	float m_speed;
};

