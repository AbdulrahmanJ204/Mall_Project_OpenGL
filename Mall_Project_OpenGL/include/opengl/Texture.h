#pragma once
#include "core.h"

#include<string>
class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP; // byte per pexil

public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(unsigned int slot = 0)  const; // optional
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

};

