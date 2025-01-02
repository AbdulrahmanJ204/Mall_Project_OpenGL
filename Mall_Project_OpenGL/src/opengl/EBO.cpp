#include"EBO.h"

EBO::EBO(const unsigned int* data, unsigned int count) : m_Count(count) {
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(glGenBuffers(1, &m_rendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW));
}

EBO::~EBO()  {
	GLCall(glDeleteBuffers(1 , &m_rendererID));
}

void EBO::Bind()const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}
void EBO::Unbind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}