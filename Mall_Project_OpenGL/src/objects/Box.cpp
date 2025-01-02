#include "Box.h"
#include <glm/gtc/matrix_transform.hpp>

Box::Box(float width, float height, float depth , const std::string vertexPath , const std::string fragmentPath , glm::vec3 trans)
	: m_Width(width), m_Height(height), m_Depth(depth),
	m_Model(1.0f), m_Position(0.0f), m_Scale(1.0f),
	m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) {

	float vertices[] = {
		// Front face
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 1.0f,

		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 1.0f,

		// Back face
		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 1.0f,

		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 1.0f,


		// Left face
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,

		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 0.0f,

		// Right face
		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 1.0f,

		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 0.0f,

		 // Top face
		 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,

		 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
		 -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 0.0f,

		 // Bottom face
		 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 0.0f,

		 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		 -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
	};

	m_VAO = std::make_unique<VAO>();
	m_VBO = std::make_unique<VBO>(vertices, sizeof(vertices));

	VBOLayout layout;
	layout.Push<float>(3); // Position
	layout.Push<float>(3); // normals
	layout.Push<float>(2); // Texture coordinates
	m_VAO->AddBuffer(*m_VBO, layout);
	m_Textures.resize(6); // Allocate space for 6 faces
	m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);

	//m_Textures[6] = std::make_shared<Texture>("assets/textures/bare-wood1_roughness.png");
	
}

Box::~Box() {}

void Box::setParentModel(glm::mat4 pModel)
{
	m_ParentModel = pModel;
}

void Box::setFaceTexture(Face face, const std::string& texturePath) {
	int faceIndex = (int)face;
	if (faceIndex < 0 || faceIndex >= 6) return;
	m_Textures[faceIndex] = std::make_shared<Texture>(texturePath);
}

void Box::setPosition(const glm::vec3& position) {
	m_Position = position;
	updateModelMatrix();
}

void Box::setRotation(float angle, const glm::vec3& axis) {
	m_RotationAngle = angle;
	m_RotationAxis = axis;
	updateModelMatrix();
}

void Box::setScale(const glm::vec3& scale) {
	m_Scale = scale;
	updateModelMatrix();
}

void Box::updateModelMatrix() {
	m_Model = glm::mat4(1.0f);
	m_Model = glm::translate(m_Model, m_Position);
	m_Model = glm::rotate(m_Model, glm::radians(m_RotationAngle), m_RotationAxis);
	m_Model = glm::scale(m_Model, m_Scale);
	m_Model = m_Model * m_ParentModel;
}

void Box::draw(const glm::mat4& view, const glm::mat4& projection) {
	m_Shader->Bind();
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", view);
	m_Shader->setUniformMat4f("proj", projection);
	m_VAO->Bind();
	//m_Shader->SetUniform1i("u_Texture2", 1);
	//m_Textures[6]->Bind(1);
	for (int i = 0; i < 6; ++i) {
		if (m_Textures[i]) {
			m_Textures[i]->Bind();
			unsigned int start = i*6, end = i * 6 + 6;
			//std::cout << start << " " << end << std::endl;
			m_Shader->SetUniform1i("u_Texture", 0);
			GLCall(glDrawArrays(GL_TRIANGLES, i*6,  6));
		}
	}

	m_Shader->Unbind();
	m_VAO->Unbind();
}
