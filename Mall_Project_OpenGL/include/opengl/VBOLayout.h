#pragma once
#include "core.h"
struct VBOElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	VBOElement(unsigned int tp, unsigned int cnt, unsigned char n) :
		count(cnt), type(tp), normalized(n)
	{

	}
	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
			case  GL_FLOAT:					 return 4;
			case  GL_UNSIGNED_INT:	 return 4;
			case  GL_UNSIGNED_BYTE:  return 1;
		}
		ASSERT(false);
		return 0;

	}
};

class VBOLayout
{
private:
	std::vector<VBOElement> m_Elements;
	unsigned int m_Stride;
public:
	VBOLayout() 
		: m_Stride(0) {};

	template<typename T>
	void Push(unsigned int count) {
		std::_Xruntime_error;
	}

	// could be like this instead of templates , or add a new parameter "type". 
	void PushFloats(unsigned int count) {
		m_Elements.emplace_back(GL_FLOAT, count, GL_FALSE);
		m_Stride += count * VBOElement::GetSizeOfType(GL_FLOAT);
	}
	template<>
	void Push<float>(unsigned int count) {
		m_Elements.emplace_back(GL_FLOAT, count, GL_FALSE);
		m_Stride += count * VBOElement::GetSizeOfType(GL_FLOAT);
	}
	template<>
	void Push<unsigned int>(unsigned  int count) {
		m_Elements.emplace_back(GL_UNSIGNED_INT, count, GL_FALSE);
		m_Stride += count * VBOElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		m_Elements.emplace_back(GL_UNSIGNED_BYTE ,count, GL_TRUE);
		m_Stride += count * VBOElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}


	inline const std::vector<VBOElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }


};

