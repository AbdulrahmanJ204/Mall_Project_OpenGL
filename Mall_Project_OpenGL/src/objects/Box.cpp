#include "Box.h"
#include <glm/gtc/matrix_transform.hpp>
#include <Scene.h>

Box::Box(float width, float height, float depth, const std::string vertexPath, const std::string fragmentPath, const faceRepeatMap& repeat, glm::vec3 trans)
	: m_Width(width), m_Height(height), m_Depth(depth),
	m_Model(1.0f), m_ParentModel(1.0f), m_Position(trans), m_Scale(1.0f),
	m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) {

	// Default repetition values if not provided
		m_Repeat = {
			{Face::Back, {1, 1}},
			{Face::Front, {1, 1}},
			{Face::Left, {1, 1}},
			{Face::Right, {1, 1}},
			{Face::Up, {1, 1}},
			{Face::Down, {1, 1}}
		};
	for (const auto& pair : repeat) {
		m_Repeat[pair.first] = pair.second;
	}
// Extract repetition values for each face
auto backRepeat = m_Repeat[Face::Back];
auto frontRepeat = m_Repeat[Face::Front];
auto leftRepeat = m_Repeat[Face::Left];
auto rightRepeat = m_Repeat[Face::Right];
auto upRepeat = m_Repeat[Face::Up];
auto downRepeat = m_Repeat[Face::Down];

float vertices[] = {
	// Back face
	-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 0.0f,
	 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 1.0f,

	-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 1.0f,
	-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 1.0f,

	// Front face
	-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 0.0f,
	 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 1.0f,

	-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 1.0f,
	-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 1.0f,

	// Left face
	-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 0.0f,
	-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 1.0f,
	-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 1.0f,

	-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 0.0f,
	-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 1.0f,
	-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 0.0f,

	// Right face
	 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 1.0f,
	 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 1.0f,

	 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 0.0f,
	 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 1.0f,
	 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 0.0f,

	 // Top face
	 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 1.0f,
	  width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 1.0f,
	  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 0.0f,

	 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 1.0f,
	  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 0.0f,
	 -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 0.0f,

	 // Bottom face
	 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 1.0f,
	  width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 1.0f,
	  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 0.0f,

	 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 1.0f,
	  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 0.0f,
	 -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 0.0f,
};

m_VAO = std::make_unique<VAO>();
m_VBO = std::make_unique<VBO>(vertices, sizeof(vertices));

VBOLayout layout;
layout.Push<float>(3); // Position
layout.Push<float>(3); // Normals
layout.Push<float>(2); // Texture coordinates
m_VAO->AddBuffer(*m_VBO, layout);
m_Textures.resize(6); // Allocate space for 6 faces
m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);


m_Shader->Bind();
m_Shader->setUniformMat4f("projection", Scene::getProjection());

m_Shader->Unbind();
m_VAO->Unbind();
}

Box::~Box() {}

void Box::setParentModel(glm::mat4 pModel) {
	m_ParentModel = pModel;
}

void Box::setFaceTexture(Face face, const std::string& texturePath , bool isTransparent, bool mirrorX, bool mirrorY) {
	int faceIndex = static_cast<int>(face);
	if (faceIndex < 0 || faceIndex >= 6) return;
	isTransparentFace[faceIndex] = isTransparent;
	m_Textures[faceIndex] = std::make_shared<Texture>(texturePath, mirrorX, mirrorY);
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
	m_Model = m_ParentModel * m_Model;
}

void Box::onImguiRender(std::string name)
{	
	const std::string pos = name + " Position";
	ImGui::SliderFloat3(pos.c_str(), &m_Position.x, -100, 100);
	//const std::string pos = name + "Rotaion";
	//ImGui::SliderFloat3(pos.c_str(), &m_Position.x, -100, 100);
	//const std::string pos = name + "Position";
	//ImGui::SliderFloat3(pos.c_str(), &m_Position.x, -100, 100);
}

void Box::drawOpaque() {
	updateModelMatrix();
	m_Shader->Bind();
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_VAO->Bind();
	for (int i = 0; i < 6; ++i) {
		if (isTransparentFace[i]) continue;
		if (m_Textures[i]) {
			m_Textures[i]->Bind();
			m_Shader->SetUniform1i("u_Texture", 0);
			GLCall(glDrawArrays(GL_TRIANGLES, i * 6, 6));
		}
	}

	m_Shader->Unbind();
	m_VAO->Unbind();
}

void Box::drawTransparent()
{
	m_Shader->Bind();
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_VAO->Bind();
	//GLCall(glDisable(GL_DEPTH_TEST));
	for (int i = 0; i < 6; ++i) {
		if (!isTransparentFace[i]) continue;
		if (m_Textures[i]) {
			m_Textures[i]->Bind();
			m_Shader->SetUniform1i("u_Texture", 0);
			GLCall(glDrawArrays(GL_TRIANGLES, i * 6, 6));
		}
	}

	//GLCall(glEnable(GL_DEPTH_TEST));
	m_Shader->Unbind();
	m_VAO->Unbind();

}
