#pragma once
#include "IGameObject.h"
class Componant :
	public IGameObject
{
public:
	Componant();
	~Componant();
	void draw() override;
};

