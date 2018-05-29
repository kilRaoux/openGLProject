#pragma once
#include "VertexBufferObject.h"
#include "IndexBufferObject.h"
#include "..\GameObject\renderData.h"
class VertexArrayObject
{
public:
	VertexArrayObject(renderData *data);
	~VertexArrayObject();
	void bind();
	void unbind();
private:
	unsigned int m_id, m_vbo, m_ibo, m_tc;
};

