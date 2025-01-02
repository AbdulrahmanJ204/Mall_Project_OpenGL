#include "Circle.h"
#include "Scene.h"

Circle::Circle() :
	m_Model(glm::mat4(1.0f))
{

}

Circle::Circle(float radius, int segments, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans) :
	m_Position(trans), m_Radius(radius), m_Segments(segments),
	m_Model(glm::mat4(1.0f))
{
	// Center of the circle
	glm::vec3 m_Position = trans;

	GenerateVertices();
	
	m_VBO = std::make_unique<VBO>(m_Vertices.data(), m_Vertices.size());
	VBOLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	m_VAO = std::make_unique<VAO>();
	m_VAO->AddBuffer(*m_VBO, layout);
	m_Texture = std::make_unique<Texture>("assets/textures/brickwall.jpg");
	m_Shader = std::make_unique<Shader>(vertexPath, fragPath);
	m_Texture->Bind();
	m_Shader->Bind();
	m_Shader->setUniformMat4f("projection", Scene::getProjection());
	m_VAO->Unbind();
	m_Shader->Unbind();
}

Circle::~Circle()
{
}

void Circle::draw()
{
	m_VAO->Bind();
	m_Texture->Bind();
	m_Shader->Bind();
	updateUniforms();
	GLCall(glDrawArrays(GL_TRIANGLE_FAN, 0, m_Segments+2));
}
void Circle::updateUniforms() {
	m_Shader->Bind();
	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", Scene::getView());
	m_Shader->SetUniform1i("u_Texture", 0);
}


void Circle::setParentModel(glm::mat4 pModel)
{
	m_ParentModel = pModel;
}


void Circle::setPosition(const glm::vec3& position) {
	m_Position = position;
	updateModelMatrix();
}

void Circle::setRotation(float angle, const glm::vec3& axis) {
	m_RotationAngle = angle;
	m_RotationAxis = axis;
	updateModelMatrix();
}

void Circle::setScale(const glm::vec3& scale) {
	m_Scale = scale;
	updateModelMatrix();
}


void Circle::updateModelMatrix() {
	m_Model = glm::mat4(1.0f);
	m_Model = glm::translate(m_Model, m_Position);
	m_Model = glm::rotate(m_Model, glm::radians(m_RotationAngle), m_RotationAxis);
	m_Model = glm::scale(m_Model, m_Scale);
	m_Model = m_Model * m_ParentModel;
}

void Circle::GenerateVertices()
{
	float x = m_Position.x, y = m_Position.y, z = m_Position.z;
	float radius = m_Radius;
	const int numberOfSides = m_Segments;
	const int numberOfVertices = numberOfSides+2;

	GLfloat twicePi = 2.0f * M_PI;
	m_Vertices.push_back(m_Position.x);  // x
	m_Vertices.push_back(m_Position.y);  // y
	m_Vertices.push_back(m_Position.z);  // z
	m_Vertices.push_back(0.5f);          // u
	m_Vertices.push_back(0.5f);          // v

	for (int i = 1; i <= numberOfVertices ; i++)
	{
		float angle = twicePi* i / numberOfSides; // Angle in radians
		float xx = radius * cos(angle);
		float yy = radius * sin(angle);
		float u = 0.5f + 0.5f * cos(angle);
		float v = 0.5f + 0.5f * sin(angle); 
		m_Vertices.push_back(x + xx);
		m_Vertices.push_back(y + yy);
		m_Vertices.push_back(z);
		m_Vertices.push_back(u);
		m_Vertices.push_back(v);
		u = 0.5f - 0.5f * cos(angle);
		v = 0.5f + 0.5f * sin(angle);
		m_Vertices.push_back(x - xx);
		m_Vertices.push_back(y + yy);
		m_Vertices.push_back(z);
		m_Vertices.push_back(u);
		m_Vertices.push_back(v);

		u = 0.5f - 0.5f * cos(angle);
		v = 0.5f - 0.5f * sin(angle);
		m_Vertices.push_back(x - xx);
		m_Vertices.push_back(y - yy);
		m_Vertices.push_back(z);
		m_Vertices.push_back(u);
		m_Vertices.push_back(v);

		u = 0.5f + 0.5f * cos(angle);
		v = 0.5f - 0.5f * sin(angle);
		m_Vertices.push_back(x + xx);
		m_Vertices.push_back(y - yy);
		m_Vertices.push_back(z);
		m_Vertices.push_back(u);
		m_Vertices.push_back(v);

	}
}

