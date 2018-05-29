#include "VertexArrayObject.h"

#include <GL\glew.h>

VertexArrayObject::VertexArrayObject(renderData *data)
{
	glGenVertexArrays(1, &m_id);
	glBindVertexArray(m_id);

	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, data->verticeCount * sizeof(float), &(data->vertice[0]), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indexCount*sizeof(unsigned int),
		&(data->index[0]), GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
	glGenBuffers(1, &m_tc);
	glBindBuffer(GL_ARRAY_BUFFER, m_tc);
	glBufferData(GL_ARRAY_BUFFER, data->texCount * sizeof(GL_FLOAT),
		&(data->texCoord), GL_STATIC_DRAW);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}


VertexArrayObject::~VertexArrayObject()
{
}

void VertexArrayObject::bind()
{
	glBindVertexArray(m_id);
}
void VertexArrayObject::unbind()
{
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}
