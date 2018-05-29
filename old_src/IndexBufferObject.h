#pragma once
#include <GL/glew.h>
class IndexBufferObject
{
public:
	IndexBufferObject(unsigned int buffer[], unsigned int size);
	~IndexBufferObject();
	void bind();
	void unbind();
private:
	GLuint m_id;
};

