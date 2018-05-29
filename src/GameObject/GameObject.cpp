#include "GameObject.h"
#include <GL\glew.h>
#include <iostream>
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "..\debugFoo.h"


GameObject::GameObject()
{
}

GameObject::GameObject(renderData *render): data(render)
{
	/*
	vbo = new VertexBufferObject(render->vertice.data(), render->verticeCount);
	ibo = new IndexBufferObject(render->index.data(), render->indexCount);
	*/
	vao = new VertexArrayObject(data);
	shader = new ShaderObject(
		"res\\shaders\\basic.shader");
	m_matrix = glm::mat4();
	rescale(0.5);
}

GameObject::~GameObject()
{
}

void GameObject::setTexture(std::string filename)
{
	texo = new TextureObject(filename);
}

void GameObject::draw(const glm::mat4 PVmatrix)
{
	if (isChange)
	{
		isChange = false;
		m_matrix = m_translate * m_rotate*m_scale*m_matrix;
		m_translate = glm::mat4();
		m_rotate = glm::mat4();
		m_scale = glm::mat4();
	}
	rotate(0.01f,{ 1,1,1 });
	shader->bind();
	vao->bind();
	texo->bind();
	shader->setUniformMat4("u_MVP", m_matrix);//*PVmatrix);
	shader->setUniform4f("u_Color", 0.0, 1.0, 0.0, 1.0);
	glDrawElements(GL_TRIANGLES, data->indexCount, GL_UNSIGNED_INT, 0);
	texo->unbind();
	vao->unbind();
	shader->unbind();
	incrementColor += 0.05f;
	if (incrementColor > 1.0)
		incrementColor = 0.0;
}

void GameObject::translate(float x, float y, float z)
{
	isChange = true;
	m_translate = glm::translate(glm::vec3(x, y, z))*m_translate;
}

void GameObject::translate(glm::vec3 npos)
{
	isChange = true;
	m_translate = glm::translate(npos)*m_translate;
}

void GameObject::rotate(float angle, glm::vec3 drot)
{
	isChange = true;
	m_rotate = glm::rotate(angle, drot)*m_rotate;
}

void GameObject::rescale(float v)
{
	isChange = true;
	m_scale = glm::scale(glm::vec3(v,v,v))*m_rotate;
}

void GameObject::rescale(float x, float y, float z)
{
	isChange = true;
	m_scale = glm::scale(glm::vec3(x,y,z))*m_scale;
}

void GameObject::rescale(glm::vec3 nscale)
{
	isChange = true;
	m_scale = glm::scale(nscale)*m_scale;
}
