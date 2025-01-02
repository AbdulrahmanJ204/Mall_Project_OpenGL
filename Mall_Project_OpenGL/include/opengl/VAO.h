#pragma once
#include "core.h"
#include "VBO.h"
#include "VBOLayout.h"
class VAO
{
private:
	unsigned int m_RendererID;
public:
	VAO();
	~VAO();

	
	void AddBuffer(const VBO& vb, const VBOLayout& layout) const;
	void Bind() const;
	void Unbind();
	
};

