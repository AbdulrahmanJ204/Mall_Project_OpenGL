#include "Cylinder.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <Scene.h>

Cylinder::Cylinder(float topRadius, float bottomRadius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans)
    : m_TopRadius(topRadius), m_BottomRadius(bottomRadius), m_Height(height), m_SegmentCount(segmentCount)
{

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

Cylinder::~Cylinder() {}

void Cylinder::setTopTexture(const std::string& texturePath, bool mirrorX, bool mirrorY) {
    m_TopTexture = std::make_shared<Texture>(texturePath);
}

void Cylinder::setSideTexture(const std::string& texturePath, bool mirrorX, bool mirrorY) {
    m_SideTexture = std::make_shared<Texture>(texturePath);
}

void Cylinder::setBottomTexture(const std::string& texturePath, bool mirrorX, bool mirrorY) {
    m_BottomTexture = std::make_shared<Texture>(texturePath);
}




void Cylinder::generateVertices(float* vertices, int& vertexCount) {
    float angleStep = 360.0f / m_SegmentCount;
    int index = 0;

    // Top circle
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        // Center vertex
        vertices[index++] = 0.0f; // x
        vertices[index++] = m_Height / 2.0f; // y
        vertices[index++] = 0.0f; // z
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f; // Normal
        vertices[index++] = 0.5f; vertices[index++] = 0.5f; // Texture

        // First edge vertex
        vertices[index++] = m_TopRadius * cos(angle1);
        vertices[index++] = m_Height / 2.0f;
        vertices[index++] = m_TopRadius * sin(angle1);
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle1);
        vertices[index++] = 0.5f + 0.5f * sin(angle1);

        // Second edge vertex
        vertices[index++] = m_TopRadius * cos(angle2);
        vertices[index++] = m_Height / 2.0f;
        vertices[index++] = m_TopRadius * sin(angle2);
        vertices[index++] = 0.0f; vertices[index++] = 1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle2);
        vertices[index++] = 0.5f + 0.5f * sin(angle2);
    }

    // Bottom circle
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        // Center vertex
        vertices[index++] = 0.0f; // x
        vertices[index++] = -m_Height / 2.0f; // y
        vertices[index++] = 0.0f; // z
        vertices[index++] = 0.0f; vertices[index++] = -1.0f; vertices[index++] = 0.0f; // Normal
        vertices[index++] = 0.5f; vertices[index++] = 0.5f; // Texture

        // First edge vertex
        vertices[index++] = m_BottomRadius * cos(angle1);
        vertices[index++] = -m_Height / 2.0f;
        vertices[index++] = m_BottomRadius * sin(angle1);
        vertices[index++] = 0.0f; vertices[index++] = -1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle1);
        vertices[index++] = 0.5f + 0.5f * sin(angle1);

        // Second edge vertex
        vertices[index++] = m_BottomRadius * cos(angle2);
        vertices[index++] = -m_Height / 2.0f;
        vertices[index++] = m_BottomRadius * sin(angle2);
        vertices[index++] = 0.0f; vertices[index++] = -1.0f; vertices[index++] = 0.0f;
        vertices[index++] = 0.5f + 0.5f * cos(angle2);
        vertices[index++] = 0.5f + 0.5f * sin(angle2);
    }

    // Side surface
    for (int i = 0; i < m_SegmentCount; ++i) {
        float angle1 = glm::radians(i * angleStep);
        float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

        float x1Top = m_TopRadius * cos(angle1);
        float z1Top = m_TopRadius * sin(angle1);
        float x2Top = m_TopRadius * cos(angle2);
        float z2Top = m_TopRadius * sin(angle2);

        float x1Bottom = m_BottomRadius * cos(angle1);
        float z1Bottom = m_BottomRadius * sin(angle1);
        float x2Bottom = m_BottomRadius * cos(angle2);
        float z2Bottom = m_BottomRadius * sin(angle2);

        // Triangle 1
        vertices[index++] = x1Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1Bottom; // Bottom-left
        vertices[index++] = x1Bottom - x1Top; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1Top; // Normal
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f; // Texture

        vertices[index++] = x1Top; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1Top; // Top-left
        vertices[index++] = x1Bottom - x1Top; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1Top; // Normal
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f; // Texture

        vertices[index++] = x2Top; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2Top; // Top-right
        vertices[index++] = x2Bottom - x2Top; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2Top; // Normal
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f; // Texture

        // Triangle 2
        vertices[index++] = x1Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1Bottom; // Bottom-left
        vertices[index++] = x1Bottom - x1Top; vertices[index++] = 0.0f; vertices[index++] = z1Bottom - z1Top; // Normal
        vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f; // Texture

        vertices[index++] = x2Top; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2Top; // Top-right
        vertices[index++] = x2Bottom - x2Top; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2Top; // Normal
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f; // Texture

        vertices[index++] = x2Bottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2Bottom; // Bottom-right
        vertices[index++] = x2Bottom - x2Top; vertices[index++] = 0.0f; vertices[index++] = z2Bottom - z2Top; // Normal
        vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f; // Texture
    }
}


void Cylinder::drawOpaque() {
    //updateModelMatrix();
    updateModelMatrix();
    m_Shader->Bind();
    m_Shader->setUniformMat4f("model", getModel());
    m_Shader->setUniformMat4f("view", Scene::getView());
    m_VAO->Bind();
    // Draw top
    if (m_TopTexture) {
        m_TopTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    GLCall(glDrawArrays(GL_TRIANGLES, 0, m_SegmentCount * 3));

    // Draw bottom
    if (m_BottomTexture) {
        m_BottomTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    GLCall(glDrawArrays(GL_TRIANGLES, m_SegmentCount * 3, m_SegmentCount * 3));

    // Draw sides
    if (m_SideTexture) {
        m_SideTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    GLCall(glDrawArrays(GL_TRIANGLES, m_SegmentCount * 6, m_SegmentCount * 6));

    m_Shader->Unbind();
    m_VAO->Unbind();
}

void Cylinder::getTransparent()
{
}

void Cylinder::onImguiRender(std::string name)
{
    std::string pos = name + " Position ";
    ImGui::SliderFloat3(pos.c_str(), &m_Position.x, -100.0f, 100.0f);
    
}
