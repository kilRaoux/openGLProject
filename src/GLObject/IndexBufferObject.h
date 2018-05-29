#pragma once
class IndexBufferObject
{
public:
	IndexBufferObject(unsigned int buffer[], unsigned int count);
	~IndexBufferObject();
	void bind();
	void unbind();
private:
	unsigned int m_id;
};

