#include "IndexBufferObject.h"



IndexBufferObject::IndexBufferObject(unsigned int buffer[], unsigned int count){
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), buffer, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


IndexBufferObject::~IndexBufferObject(){
}

void IndexBufferObject::bind(){

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IndexBufferObject::unbind(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
