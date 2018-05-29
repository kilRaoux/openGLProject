#include "CameraFirstPersonne.h"



CameraFirstPersonne::CameraFirstPersonne(
	InputManager *input, int width, int height) :
	m_input(input)
{
	m_ViewMatrix = glm::mat4();
	m_input = input;
	m_pos = glm::vec3(0,0,-2);
	m_target = glm::vec3(0, 0, 0);
	m_up = glm::vec3(0, 1, 0);
	setProjection(
		45.0f,
		((float)width) / ((float)height),
		0.1f, 100.0f);
	m_ViewMatrix = glm::lookAt(
		m_pos,
		m_target,
		m_up);
}


CameraFirstPersonne::~CameraFirstPersonne()
{
	delete m_input;
}

void CameraFirstPersonne::orientation()
{
	int xRel = m_input->getXRel();
	int yRel = m_input->getYRel();

	m_phi -= yRel * m_speed;
	m_theta -= xRel * m_speed;

	if (m_phi > 89.0) m_phi = 89.0;
	else if (m_phi < -89.0) m_phi = -89.0;

	float phiRadian = m_phi * M_PI / 180;
	float thetaRadian = m_theta * M_PI / 180;

	m_orientation.x = cos(phiRadian) * sin(thetaRadian);
	m_orientation.y = sin(phiRadian);
	m_orientation.z = cos(phiRadian) * cos(thetaRadian);

	m_lateralMove = glm::normalize(glm::cross(m_up, m_orientation));

	m_target = m_pos + m_orientation;
}

void CameraFirstPersonne::move()
{
	if (m_input->mouseMove())
		orientation();
	if (m_input->getKey(SDL_SCANCODE_UP))
	{
		m_pos = m_pos + m_orientation * 0.5f;
		m_target = m_pos + m_orientation;
	}

	if (m_input->getKey(SDL_SCANCODE_DOWN))
	{
		m_pos = m_pos - m_orientation * 0.5f;
		m_target = m_pos + m_orientation;
	}

	if (m_input->getKey(SDL_SCANCODE_LEFT))
	{
		m_pos = m_pos + m_lateralMove * 0.5f;
		m_target = m_pos + m_orientation;
	}

	if (m_input->getKey(SDL_SCANCODE_RIGHT))
	{
		m_pos = m_pos - m_lateralMove * 0.5f;
		m_target = m_pos + m_orientation;
	}
	if (m_input->getKey(SDL_SCANCODE_SPACE))
	{
		m_pos = glm::vec3(0, 0, -2);
		m_target = glm::vec3(0, 0, 0);
		m_up = glm::vec3(0, 1, 0);
	}
}

void CameraFirstPersonne::update()
{
	move();
	setView();
}
