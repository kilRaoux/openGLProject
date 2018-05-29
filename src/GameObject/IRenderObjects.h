#pragma once
#include <glm\glm.hpp>

class IRenderObjects
{
public:
	IRenderObjects();
	~IRenderObjects();
	virtual void draw(glm::mat4 PV) = 0;
};

