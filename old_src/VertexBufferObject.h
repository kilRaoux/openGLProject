#pragma once
#ifndef BUFFER_OFFSET

#define BUFFER_OFFSET(offset) ((char*)0 + (offset))

#endif
#include <GL/glew.h>
#include <iostream>
class VertexBufferObject
{
public:
	VertexBufferObject();
	VertexBufferObject(float buffer[], unsigned int count);
	VertexBufferObject(
		float buffer1[], unsigned int count1,
		float buffer2[], unsigned int count2);
	~VertexBufferObject();
	void load();
	void bind();
	void unbind();
	GLuint getId();
private:
	GLuint m_id;
	char nSubData;
	unsigned int m_size[16];
};

