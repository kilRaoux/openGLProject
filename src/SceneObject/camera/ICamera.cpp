#include "ICamera.h"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>
#include "..\..\debugFoo.h"

glm::mat4 ICamera::getViewMatrix()
{
	return m_ViewMatrix;
}

glm::mat4 ICamera::getProjectionMatrix()
{
	return m_ProjectionMatrix;;
}

glm::mat4 ICamera::getMatrix()
{
	update();
	//printMat4(m_ProjectionMatrix);
	//printMat4(m_ViewMatrix);
	//std::cin.get();
	return m_ProjectionMatrix*m_ViewMatrix;
}

void ICamera::init(InputManager *input, unsigned int width, unsigned int height)
{
}

void ICamera::setProjection(float fov, float ratio, float minRange, float maxRange)
{
	m_ProjectionMatrix = glm::perspective(
		glm::radians(fov),
		ratio,
		minRange, maxRange);
}

void ICamera::setView(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
{
	m_pos = pos;
	m_target = target;
	m_up = up;
	m_ViewMatrix = glm::lookAt(
		m_pos,
		m_target,
		m_up);
}

void ICamera::setView()
{
	m_ViewMatrix = glm::lookAt(
		m_pos,
		m_target,
		m_up);
}

void ICamera::setPositon(glm::vec3 pos)
{
	m_pos = pos;
}

