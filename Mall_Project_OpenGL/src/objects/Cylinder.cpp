#include "Cylinder.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <Scene.h>

Cylinder::Cylinder(float radius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans)
    : m_Radius(radius), m_Height(height), m_SegmentCount(segmentCount),
    m_Model(1.0f), m_Position(0.0f), m_Scale(1.0f),
    m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) {

    int vertexCount = segmentCount * 12; // Top circle, bottom circle, and side.
    float* vertices = new float[vertexCount * 8]; // Position, Normal, Texture
    generateVertices(vertices, vertexCount);

    m_VAO = std::make_unique<VAO>();
    m_VBO = std::make_unique<VBO>(vertices, vertexCount * 8 * sizeof(float));

    VBOLayout layout;
    layout.Push<float>(3); // Position
    layout.Push<float>(3); // Normal
    layout.Push<float>(2); // Texture coordinates
    m_VAO->AddBuffer(*m_VBO, layout);

    m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);
    m_Shader->Bind();
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->Unbind();

    delete[] vertices;
}

Cylinder::~Cylinder() {}

void Cylinder::generateVertices(float* vertices, int& vertexCount) {
    float angleStep = 360.0f / m_SegmentCount;
    int index = 0;

    // Top circle
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        vertices[index++] = 0.0f; // Center
        vertices[index++] = m_Height / 2.0f;
        vertices[index++] = 0.0f;
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f; vertices[index++] = 0.5f;

        vertices[index++] = m_Radius * cos(angle1);
        vertices[index++] = m_Height / 2.0f;
        vertices[index++] = m_Radius * sin(angle1);
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle1); vertices[index++] = 0.5f + 0.5f * sin(angle1);

        vertices[index++] = m_Radius * cos(angle2);
        vertices[index++] = m_Height / 2.0f;
        vertices[index++] = m_Radius * sin(angle2);
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle2); vertices[index++] = 0.5f + 0.5f * sin(angle2);
    }

    // Side surfaces
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        float x1 = m_Radius * cos(angle1), z1 = m_Radius * sin(angle1);
        float x2 = m_Radius * cos(angle2), z2 = m_Radius * sin(angle2);

        // Quad as two triangles
        vertices[index++] = x1; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1;
        vertices[index++] = x1; vertices[index++] = 0.0f; vertices[index++] = z1;
        vertices[index++] = angle1 / 360.0f; vertices[index++] = 0.0f;

        // Repeat similarly for the other vertices...
    }
}

void Cylinder::draw() {
    m_Shader->Bind();
    m_Shader->setUniformMat4f("model", m_Model);
    m_Shader->setUniformMat4f("view", Scene::getView());
    m_VAO->Bind();

    if (m_Texture) {
        m_Texture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, 0, m_SegmentCount * 12);

    m_Shader->Unbind();
    m_VAO->Unbind();
}
