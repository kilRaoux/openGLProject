#include "VertexArrayObject.h"



VertexArrayObject::VertexArrayObject(VertexBufferObject vbo){
	glGenVertexArrays(1, &m_id);
	glBindVertexArray(m_id);

	vbo.bind();

	vbo.load();

	vbo.unbind();


	glBindVertexArray(0);
}

VertexArrayObject::~VertexArrayObject()
{
}

void VertexArrayObject::bind(){
	glBindVertexArray(m_id);
}

void VertexArrayObject::unbind(){
	glBindVertexArray(0);
}
