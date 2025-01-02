#pragma once
#include <VBO.h>
#include <Shader.h>
#include <EBO.h>
#include <VAO.h>
#include <memory>
#include <Texture.h>

#include<glm/glm.hpp>	
#include<glm/gtc/matrix_transform.hpp>
class Circle
{

public:
	Circle();
	Circle(float radius, int segments, const std::string& vertexPath , const std::string& fragPath , glm::vec3 trans = glm::vec3(0.0f , 0.0f , 0.0f) );

	// Allow moving
	Circle(Circle&&) noexcept = default;
	Circle& operator=(Circle&&) noexcept = default;
	~Circle();
	void draw();
	void updateUniforms();
	void setParentModel(glm::mat4 pModel);
	
	void setPosition(const glm::vec3& position);
	void setRotation(float angle, const glm::vec3& axis);
	void setScale(const glm::vec3& scale);

	void GenerateVertices();

private:
	std::unique_ptr<VAO>m_VAO;
	std::unique_ptr<VBO>m_VBO;
	std::unique_ptr<Shader>m_Shader;
	std::unique_ptr<Texture>m_Texture;

	glm::mat4 m_Model, m_ParentModel;
	std::vector<float> m_Vertices;
	glm::vec3 m_Position,m_Scale;
	float m_Radius;
	int m_Segments;
	float M_PI = acos(-1.0f);

	float m_RotationAngle;
	glm::vec3 m_RotationAxis;

	void updateModelMatrix();
	
};

