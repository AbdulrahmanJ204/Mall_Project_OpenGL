#include "Square.h"
#include <Scene.h>
#include <set>
struct Vec3Comparator {
	bool operator()(const glm::vec3& a, const glm::vec3& b) const {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.z < b.z;
	}
};




Square::Square(const float* vertices, float size, const std::string& vertexPath, const std::string& fragmentPath)
	: m_IsTransparent(false) {
	m_VAO = std::make_unique<VAO>();
	m_VBO = std::make_unique<VBO>(vertices, size);
	VBOLayout layout;
	layout.Push<float>(3); // Position
	layout.Push<float>(3); // Normals
	layout.Push<float>(2); // Texture coordinates
	m_Normal = glm::vec3(vertices[3], vertices[4], vertices[5]);
	m_VAO->AddBuffer(*m_VBO, layout);

	std::set<glm::vec3, Vec3Comparator> unVertices;
	for (int i = 0; i < 6; ++i) { 
		glm::vec3 vertex(vertices[i * 8 + 0], vertices[i * 8 + 1], vertices[i * 8 + 2]);
		unVertices.insert(vertex);
	}

	rectVertices.assign(unVertices.begin(), unVertices.end());
	sortRectangleVertices();

	m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);
	m_VAO->Unbind();
}

Square::~Square() {}

void Square::setTexture(const std::string& texturePath, bool isTransparent, bool mirrorX, bool mirrorY) {
	m_IsTransparent = isTransparent;
	m_Texture = std::make_shared<Texture>(texturePath, mirrorX, mirrorY);
}

void Square::drawOpaque() {
	if (m_IsTransparent) return;

	updateModelMatrix();

	m_Shader->Bind();
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", getModel());
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_Texture->Bind();
	m_Shader->SetUniform1i("u_Texture", 0);
	m_VAO->Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	m_VAO->Unbind();
	m_Shader->Unbind();
}
void Square::sortRectangleVertices() {	
	for (int i = 0; i < 4; ++i) {
		m_Center += rectVertices[i];
	}
	m_Center /= 4.0f;
	m_Center = getModifiedPosition(m_Center);
	glm::vec3 edge1 = rectVertices[1] - rectVertices[0];
	glm::vec3 edge2 = rectVertices[2] - rectVertices[1];
	glm::vec3 normal = glm::normalize(glm::cross(edge1, edge2));
	std::sort(rectVertices.begin(), rectVertices.end(), [&](const glm::vec3& a, const glm::vec3& b) {
		glm::vec3 vecA = a - m_Center;
		glm::vec3 vecB = b - m_Center;
		float angleA = atan2(glm::dot(glm::cross(normal, vecA), normal), glm::dot(vecA, normal));
		float angleB = atan2(glm::dot(glm::cross(normal, vecB), normal), glm::dot(vecB, normal));
		return angleA < angleB;
		});
}


float Square::dist() {
	const glm::vec3 point = Scene::instancePtr->getCameraPosition();
	float minDistance = FLT_MAX; // Initialize with a large value
	glm::vec3 closestPoint; // Closest point on the rectangle

	// Iterate through all 4 sides of the rectangle
	for (int i = 0; i < 4; ++i) {
		glm::vec3 v1 = getModifiedPosition( rectVertices[i]);
		glm::vec3 v2 = getModifiedPosition( rectVertices[(i + 1) % 4]); // Next vertex (wraps around)

		// Vector from v1 to v2
		glm::vec3 edge = v2 - v1;

		// Vector from v1 to the point
		glm::vec3 pointToV1 = point - v1;

		// Project pointToV1 onto the edge
		float edgeLengthSquared = glm::length(edge);
		float t = glm::dot(pointToV1, edge) / edgeLengthSquared;

		// Clamp t to [0, 1] to ensure the projection lies on the edge
		t = glm::clamp(t, 0.0f, 1.0f);

		// Find the closest point on the edge
		glm::vec3 projection = v1 + t * edge;

		// Calculate the distance from the point to the projection
		float distance = glm::distance(point, projection);

		// Update the minimum distance and closest point
		if (distance < minDistance) {
			minDistance = distance;
			closestPoint = projection;
		}
	}


	// Calculate the hypotenuse (distance from the point to the closest point on the rectangle)
	float hypotenuse = glm::distance(point, closestPoint);

	return hypotenuse;
}

void Square::drawTransparent()
{
	if (!m_IsTransparent) return;
	updateModelMatrix();
	m_Shader->Bind();
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", getModel());
	m_Shader->setUniformMat4f("view", Scene::getView());


	m_Texture->Bind();
	m_Shader->SetUniform1i("u_Texture", 0);
	

	m_VAO->Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); 
	m_VAO->Unbind();
	m_Shader->Unbind();
}

void Square::getTransparent() {
	if (!m_IsTransparent) return;
	Scene::addTransparent(this);
}

void Square::onImguiRender() {
	
	float d = dist();
	ImGui::InputFloat("Distance", &d);
	ImGui::SliderFloat3("Position", &m_Position.x, -100, 100);
}