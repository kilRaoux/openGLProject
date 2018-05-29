#include "VertexBufferObject.h"

#include <GL/glew.h>

VertexBufferObject::VertexBufferObject(): m_id(0)
{

}

VertexBufferObject::VertexBufferObject(float buffer[], unsigned int count) :
	m_id(0)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER,
		count * sizeof(float),
		buffer, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBufferObject::~VertexBufferObject()
{
	glDeleteBuffers(1, &m_id);
}

void VertexBufferObject::bind()
{
 	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (const void*)12);
}

void VertexBufferObject::unbind()
{

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int VertexBufferObject::getId()
{
	return m_id;
}

