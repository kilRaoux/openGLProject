#pragma once
#include <GL/glew.h>
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
class VertexArrayObject
{
public:
	VertexArrayObject(VertexBufferObject vbo);
	~VertexArrayObject();
	void bind();
	void unbind();
	GLuint* getId();
private:
	GLuint m_id;

};

