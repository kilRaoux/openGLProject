#pragma once
#include <glm/glm.hpp>
class IGameObject
{
public:
	virtual void draw() = 0;
private:
	bool isVisible;
};

