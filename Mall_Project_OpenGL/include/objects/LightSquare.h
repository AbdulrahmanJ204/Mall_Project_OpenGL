#pragma once
#include "core.h"
#include "Object.h"
#include "VBO.h"
#include "VAO.h"
#include "Texture.h"
#include "Shader.h"
#include "PointLight.h"
//    ? NOTE:
//    ! Dont use this class 
//    ! If you want to make a square , use the box class and make the depth = 0.
//    ! or you can use it, but send the vertices :-)
struct Vertex1 {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoord;
	glm::vec3 tangent;
	glm::vec3 bitangent;
};

class LightSquare : public Object {
public:
	LightSquare(const float* vertices, float size, const std::string& vertexPath, const std::string& fragmentPath);
	~LightSquare();

	void drawOpaque() override;
	void drawTransparent() override;
	void getTransparent() override;
	void onImguiRender() override;
	void sortRectangleVertices();
	float dist() override;

	std::vector<float> addTangentsAndBitangents(const float* vertices, int vertexCount);

	void setTexture(textureMap& texturePath, bool isTransparent = false, bool mirrorX = false, bool mirrorY = false);
	void setLights(std::vector<PointLight>& lights);
	std::vector <glm::vec3> rectVertices;
private:
	std::unique_ptr<VAO> m_VAO;
	std::unique_ptr<VBO> m_VBO;
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<Texture> m_Texture;
	std::shared_ptr<Texture> m_AOMAP;
	std::shared_ptr<Texture> m_NormalMap;
	std::shared_ptr<Texture> m_RoughnessMap;
	std::shared_ptr<Texture> m_MetalicMap;

	glm::vec3 m_Normal;
	bool m_IsTransparent;
	std::vector<PointLight> pointLights;
	PointLight defaultLight;
};