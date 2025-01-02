#include "Cup.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <Scene.h>

Cup::Cup(float topRadius, float innerTopRadius, float bottomRadius, float innerBottomRadius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans)
    : m_TopRadius(topRadius), m_InnerTopRadius(innerTopRadius), m_BottomRadius(bottomRadius), m_InnerBottomRadius(innerBottomRadius), m_Height(height), m_SegmentCount(segmentCount),
    m_Model(1.0f), m_Position(0.0f), m_Scale(1.0f),
    m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) {

    int vertexCount = segmentCount * 12; // Adjusted for top, bottom, and side
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
    m_VAO->Unbind();
    delete[] vertices;
}

Cup::~Cup() {}

void Cup::setTopTexture(const std::string& texturePath) {
    m_TopTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setSideTexture(const std::string& texturePath) {
    m_SideTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setBottomTexture(const std::string& texturePath) {
    m_BottomTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setParentModel(glm::mat4 pModel) {
    m_ParentModel = pModel;
}

void Cup::updateModelMatrix() {
    // Implementation here...
}

void Cup::generateVertices(float* vertices, int& vertexCount) {
    float angleStep = 360.0f / m_SegmentCount;
    int index = 0;

    // Outer wall
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        float x1 = m_TopRadius * cos(angle1);
        float z1 = m_TopRadius * sin(angle1);
        float x2 = m_TopRadius * cos(angle2);
        float z2 = m_TopRadius * sin(angle2);

        float x1Bottom = m_BottomRadius * cos(angle1);
        float z1Bottom = m_BottomRadius * sin(angle1);
        float x2Bottom = m_BottomRadius * cos(angle2);
        float z2Bottom = m_BottomRadius * sin(angle2);

        // Triangle 1
        vertices[index++] = x1Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1Bottom;
        vertices[index++] = x1Bottom - x1; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

        vertices[index++] = x1; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1;
        vertices[index++] = x1Bottom - x1; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

        vertices[index++] = x2; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2;
        vertices[index++] = x2Bottom - x2; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;

        // Triangle 2
        vertices[index++] = x1Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1Bottom;
        vertices[index++] = x1Bottom - x1; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

        vertices[index++] = x2; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2;
        vertices[index++] = x2Bottom - x2; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;

        vertices[index++] = x2Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2Bottom;
        vertices[index++] = x2Bottom - x2; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;
    }

    // Inner wall (reverse winding)
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        float x1 = m_InnerTopRadius * cos(angle1);
        float z1 = m_InnerTopRadius * sin(angle1);
        float x2 = m_InnerTopRadius * cos(angle2);
        float z2 = m_InnerTopRadius * sin(angle2);

        float x1Bottom = m_InnerBottomRadius * cos(angle1);
        float z1Bottom = m_InnerBottomRadius * sin(angle1);
        float x2Bottom = m_InnerBottomRadius * cos(angle2);
        float z2Bottom = m_InnerBottomRadius * sin(angle2);

        // Triangle 1
        vertices[index++] = x1; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1;
        vertices[index++] = x1 - x1Bottom; vertices[index++] = 0.0f; vertices[index++] = z1 - z1Bottom;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

        vertices[index++] = x1Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1Bottom;
        vertices[index++] = x1 - x1Bottom; vertices[index++] = 0.0f; vertices[index++] = z1 - z1Bottom;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

        vertices[index++] = x2Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2Bottom;
        vertices[index++] = x2 - x2Bottom; vertices[index++] = 0.0f; vertices[index++] = z2 - z2Bottom;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

        // Triangle 2
        vertices[index++] = x1; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1;
        vertices[index++] = x1 - x1Bottom; vertices[index++] = 0.0f; vertices[index++] = z1 - z1Bottom;
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

        vertices[index++] = x2Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2Bottom;
        vertices[index++] = x2 - x2Bottom; vertices[index++] = 0.0f; vertices[index++] = z2 - z2Bottom;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

        vertices[index++] = x2; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2;
        vertices[index++] = x2 - x2Bottom; vertices[index++] = 0.0f; vertices[index++] = z2 - z2Bottom;
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;
    }
}


void Cup::draw() {
    m_Shader->Bind();
    m_Shader->setUniformMat4f("model", m_Model);
    m_Shader->setUniformMat4f("view", Scene::getView());
    m_VAO->Bind();

    // Draw top
    if (m_TopTexture) {
        m_TopTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, 0, m_SegmentCount * 3);

    // Draw bottom
    if (m_BottomTexture) {
        m_BottomTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, m_SegmentCount * 3, m_SegmentCount * 3);

    // Draw sides
    if (m_SideTexture) {
        m_SideTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, m_SegmentCount * 6, m_SegmentCount * 6);

    m_Shader->Unbind();
    m_VAO->Unbind();
}
