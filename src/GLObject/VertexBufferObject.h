#pragma once
class VertexBufferObject
{
public:
	VertexBufferObject();
	VertexBufferObject(float buffer[], unsigned int count);
	~VertexBufferObject();
	void bind();
	void unbind();
	unsigned int getId();
private:
	unsigned int m_id;
};

