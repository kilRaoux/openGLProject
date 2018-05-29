#pragma once
#include "..\GLObject\VertexBufferObject.h"
#include "..\GLObject\IndexBufferObject.h"
#include "..\GLObject\VertexArrayObject.h"
#include "TextureObject.h"
#include "IRenderObjects.h"
#include "ShaderObject.h"
#include "glm/glm.hpp"
#include "renderData.h"
class GameObject : public IRenderObjects
{
public:
	GameObject();
	GameObject(renderData *render);
	~GameObject();
	void setTexture(std::string filename);
	void draw(const glm::mat4 PVmatrix);
	/* transform function */
	// translation func
	void translate(float x, float y, float z);
	void translate(glm::vec3 npos);

	// rotation func
	void rotate(float angle, glm::vec3 drot);

	// scale func
	void rescale(float v);
	void rescale(float x, float y, float z);
	void rescale(glm::vec3 nscale);

private:
	renderData * data;
	glm::mat4 m_matrix;
	glm::vec3 pos, rot, scale;
	float incrementColor;
	VertexBufferObject * vbo;
	IndexBufferObject * ibo;
	VertexArrayObject * vao;
	TextureObject *texo;
	ShaderObject *shader;
	unsigned int m_vaoId;
	glm::mat4 m_translate;
	glm::mat4 m_rotate;
	glm::mat4 m_scale;
	bool isChange;
};

