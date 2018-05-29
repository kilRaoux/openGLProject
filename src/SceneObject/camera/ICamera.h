#pragma once
#include <glm\glm.hpp>
#include <SDL.h>
#include "..\InputManager.h"
class ICamera
{
public:
	virtual glm::mat4 getViewMatrix();
	virtual glm::mat4 getProjectionMatrix();
	virtual glm::mat4 getMatrix();
	virtual void update() = 0;
	void init(InputManager *input, unsigned int width, unsigned int height);
	void setProjection(float fov,
		float ratio,
		float minRange,
		float maxRange);
	void setView(glm::vec3 pos, glm::vec3 target, glm::vec3 up);
	void setView();
	void setPositon(glm::vec3 pos);
protected:
	InputManager *m_input;
	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;
	glm::vec3 m_pos;
	glm::vec3 m_target;
	glm::vec3 m_up;
};
