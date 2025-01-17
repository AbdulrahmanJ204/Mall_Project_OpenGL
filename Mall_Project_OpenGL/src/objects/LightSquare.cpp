#include "LightSquare.h"
#include <Scene.h>
#include <set>
#include "LightHelper.h"
#include "Texture.h"
struct Vec3Comparator {
	bool operator()(const glm::vec3& a, const glm::vec3& b) const {
		if (a.x != b.x) return a.x < b.x;
		if (a.y != b.y) return a.y < b.y;
		return a.z < b.z;
	}
};




LightSquare::LightSquare(const float* vertices, float size, const std::string& vertexPath, const std::string& fragmentPath)
	:
	defaultLight(glm::vec3(0.0f, 0.0f, 0.0f), LightHelper::getLightColor(Color::DEFAULT), 600.0f),
	m_IsTransparent(false) {
	m_VAO = std::make_unique<VAO>();
	std::vector<float> data = addTangentsAndBitangents(vertices, 6);
	m_VBO = std::make_unique<VBO>(data.data(), data.size());
	VBOLayout layout;
	layout.Push<float>(3); // Position
	layout.Push<float>(3); // Normals
	layout.Push<float>(2); // Texture coordinates
	layout.Push<float>(3); // Tan coordinates
	layout.Push<float>(3); // BitTan coordinates
	m_Normal = glm::vec3(vertices[3], vertices[4], vertices[5]);
	m_VAO->AddBuffer(*m_VBO, layout);
	std::set<glm::vec3, Vec3Comparator> unVertices;
	for (int i = 0; i < 6; ++i) {
		glm::vec3 vertex(vertices[i * 8 + 0], vertices[i * 8 + 1], vertices[i * 8 + 2]);
		unVertices.insert(vertex);
	}

	rectVertices.assign(unVertices.begin(), unVertices.end());
	sortRectangleVertices();
	pointLights.emplace_back(defaultLight);
	m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);
	m_VAO->Unbind();
}

LightSquare::~LightSquare() {}


std::vector<float> LightSquare::addTangentsAndBitangents(const float* vertices, int vertexCount) {
	std::vector<Vertex1> vertexData(vertexCount * 8);

	// Parse the input vertices into a more manageable format
	for (int i = 0; i < vertexCount; ++i) {
		vertexData[i].position = glm::vec3(vertices[i * 8 + 0], vertices[i * 8 + 1], vertices[i * 8 + 2]);
		vertexData[i].normal = glm::vec3(vertices[i * 8 + 3], vertices[i * 8 + 4], vertices[i * 8 + 5]);
		vertexData[i].texCoord = glm::vec2(vertices[i * 8 + 6], vertices[i * 8 + 7]);
	}

	// Calculate tangents and bitangents for each triangle
	for (int i = 0; i < vertexCount; i += 3) {
		Vertex1& v0 = vertexData[i + 0];
		Vertex1& v1 = vertexData[i + 1];
		Vertex1& v2 = vertexData[i + 2];

		// Edges of the triangle
		glm::vec3 deltaPos1 = v1.position - v0.position;
		glm::vec3 deltaPos2 = v2.position - v0.position;

		// UV delta
		glm::vec2 deltaUV1 = v1.texCoord - v0.texCoord;
		glm::vec2 deltaUV2 = v2.texCoord - v0.texCoord;

		// Calculate tangent and bitangent
		float r = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV1.y * deltaUV2.x);
		glm::vec3 tangent = (deltaPos1 * deltaUV2.y - deltaPos2 * deltaUV1.y) * r;
		glm::vec3 bitangent = (deltaPos2 * deltaUV1.x - deltaPos1 * deltaUV2.x) * r;

		// Assign the same tangent and bitangent to all three vertices of the triangle
		v0.tangent = tangent;
		v1.tangent = tangent;
		v2.tangent = tangent;

		v0.bitangent = bitangent;
		v1.bitangent = bitangent;
		v2.bitangent = bitangent;
	}

	// Convert the vertex data back into a flat array
	std::vector<float> result;
	for (const auto& vertex : vertexData) {
		result.push_back(vertex.position.x);
		result.push_back(vertex.position.y);
		result.push_back(vertex.position.z);

		result.push_back(vertex.normal.x);
		result.push_back(vertex.normal.y);
		result.push_back(vertex.normal.z);

		result.push_back(vertex.texCoord.x);
		result.push_back(vertex.texCoord.y);

		result.push_back(vertex.tangent.x);
		result.push_back(vertex.tangent.y);
		result.push_back(vertex.tangent.z);

		result.push_back(vertex.bitangent.x);
		result.push_back(vertex.bitangent.y);
		result.push_back(vertex.bitangent.z);
	}

	return result;
}

void LightSquare::setTexture(textureMap& texturePath, bool isTransparent, bool mirrorX, bool mirrorY) {
	m_IsTransparent = isTransparent;

	m_Texture = std::make_shared<Texture>(texturePath[TextureType::ALBEDO], mirrorX, mirrorY);
	m_AOMAP = std::make_shared<Texture>(texturePath[TextureType::AO], mirrorX, mirrorY);
	m_NormalMap = std::make_shared<Texture>(texturePath[TextureType::NORMAL], mirrorX, mirrorY);
	m_RoughnessMap = std::make_shared<Texture>(texturePath[TextureType::ROUGHNESS], mirrorX, mirrorY);
	m_MetalicMap = std::make_shared<Texture>(texturePath[TextureType::METALIC], mirrorX, mirrorY);

}

void LightSquare::setLights(std::vector<PointLight>& lights)
{
	pointLights = lights;
	pointLights.emplace_back(defaultLight);
}

void LightSquare::drawOpaque() {
	if (m_IsTransparent) return;

	updateModelMatrix();
	m_Shader->Bind();
	m_Texture->Bind();
	m_AOMAP->Bind(1);
	m_NormalMap->Bind(2);
	m_RoughnessMap->Bind(3);
	m_MetalicMap->Bind(4);
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", getModel());
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_Shader->SetUniform3fv("viewPos", Scene::instancePtr->getCameraPosition());
	m_Shader->SetUniform1i("albedoMap", 0);
	m_Shader->SetUniform1i("aoMap", 1);
	m_Shader->SetUniform1i("normalMap", 2);
	m_Shader->SetUniform1i("roughnessMap", 3);
	m_Shader->SetUniform1i("metallicMap", 4);
	m_Shader->SetUniform1i("pointLightsNumber", static_cast<int>(pointLights.size()));
	glm::vec3 pos(0.0f);
	pos = getModifiedPosition(pos);
	pointLights.rbegin()->updatePosition(pos);
	defaultLight.uploadLightsArray(*m_Shader, "pointLights", pointLights);
	m_VAO->Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	m_VAO->Unbind();
	m_Shader->Unbind();
}

void LightSquare::drawTransparent()
{
	if (!m_IsTransparent) return;

	updateModelMatrix();
	m_Shader->Bind();
	m_Texture->Bind();
	m_AOMAP->Bind(1);
	m_NormalMap->Bind(2);
	m_RoughnessMap->Bind(3);
	m_MetalicMap->Bind(4);
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_Shader->setUniformMat4f("model", getModel());
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_Shader->SetUniform3fv("viewPos", Scene::instancePtr->getCameraPosition());
	m_Shader->SetUniform1i("albedoMap", 0);
	m_Shader->SetUniform1i("aoMap", 1);
	m_Shader->SetUniform1i("normalMap", 2);
	m_Shader->SetUniform1i("roughnessMap", 3);
	m_Shader->SetUniform1i("metallicMap", 4);
	m_Shader->SetUniform1i("pointLightsNumber", static_cast<int>(pointLights.size()));
	glm::vec3 pos(0.0f);
	pos = getModifiedPosition(pos);
	pointLights.rbegin()->updatePosition(pos);
	defaultLight.uploadLightsArray(*m_Shader, "pointLights", pointLights);
	m_VAO->Bind();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 6));
	m_VAO->Unbind();
	m_Shader->Unbind();

}

void LightSquare::getTransparent() {
	if (!m_IsTransparent) return;
	Scene::addTransparent(this);
}

void LightSquare::onImguiRender() {

	float d = dist();
	ImGui::InputFloat("Distance", &d);

	ImGui::SliderFloat3("Position", &m_Position.x, -500, 500);
	int i = 0;
	for (PointLight& light : pointLights) {
		glm::vec3 pos(light.getModifiedPosition());
		ImGui::SliderFloat3(("Light[" + std::to_string(i++) + "] ").c_str(), &pos.x, -500, 500);
		pos = getModifiedPosition(pos);
		//light.updatePosition(pos);
	}
	//glm::vec3 pos(getModifiedPosition(lP));
	//pt.updatePosition(pos);
}


void LightSquare::sortRectangleVertices() {
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


float LightSquare::dist() {
	const glm::vec3 point = Scene::instancePtr->getCameraPosition();
	float minDistance = FLT_MAX; // Initialize with a large value
	glm::vec3 closestPoint; // Closest point on the rectangle

	// Iterate through all 4 sides of the rectangle
	for (int i = 0; i < 4; ++i) {
		glm::vec3 v1 = getModifiedPosition(rectVertices[i]);
		glm::vec3 v2 = getModifiedPosition(rectVertices[(i + 1) % 4]); // Next vertex (wraps around)

		// Vector from v1 to v2
		glm::vec3 edge = v2 - v1;

		// Vector from v1 to the point
		glm::vec3 pointToV1 = point - v1;

		// Project pointToV1 onto the edge
		float edgeLengthLightSquared = glm::length(edge);
		float t = glm::dot(pointToV1, edge) / edgeLengthLightSquared;

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
