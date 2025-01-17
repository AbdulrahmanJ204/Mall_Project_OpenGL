#pragma once
#include "core.h"
enum class TextureType {
	ALBEDO,
	NORMAL,
	AO,
	ROUGHNESS,
	METALIC
};
#define textureMap std::map<TextureType, std::string> 
#include<string>
class Texture
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP; // byte per pexil
public:
	Texture(const std::string& filepath, bool mirrorX = false, bool mirrorY = false);
	~Texture();
	void Bind(unsigned int slot = 0) const; 
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

};

