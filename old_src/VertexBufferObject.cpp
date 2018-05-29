#include "VertexBufferObject.h"



VertexBufferObject::VertexBufferObject()
{
}

VertexBufferObject::VertexBufferObject(float buffer[], unsigned int count)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER,
		count * sizeof(float),
		buffer, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	nSubData = 1;
	m_size[0] = count ;
}


VertexBufferObject::VertexBufferObject(
	float buffer1[], unsigned int size1,
	float buffer2[], unsigned int size2)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);

	glBufferData(GL_ARRAY_BUFFER,
		size1+size2,
		0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size1, buffer1);
	glBufferSubData(GL_ARRAY_BUFFER, size1, size2, buffer2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	nSubData = 2;
	m_size[0] = size1;
	m_size[1] = size2;
}


VertexBufferObject::~VertexBufferObject(){
	glDeleteBuffers(1, &m_id);
}

void VertexBufferObject::load(){
	bind();
	if (nSubData == 1) {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
		glEnableVertexAttribArray(0);
	}
		
	else if (nSubData == 2) {
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_size[0]));
		glEnableVertexAttribArray(2);

		std::cout << "Hello" << std::endl;
	}
	unbind();
}

void VertexBufferObject::bind(){
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBufferObject::unbind(){
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint VertexBufferObject::getId(){
	return GLuint();
}
