#include "Cup.h"
#include <Scene.h>

Cup::Cup(float topRadius, float bottomRadius, float height, float thickness, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans)
    : m_TopRadius(topRadius), m_BottomRadius(bottomRadius), m_Height(height), m_Thickness(thickness), m_SegmentCount(segmentCount),
    m_Model(1.0f), m_Position(trans), m_Scale(1.0f),
    m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) {

    int vertexCount = segmentCount * 18; // Adjusted for outer, inner, rim
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

void Cup::setOuterTexture(const std::string& texturePath) {
    m_OuterTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setInnerTexture(const std::string& texturePath) {
    m_InnerTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setRimTexture(const std::string& texturePath) {
    m_RimTexture = std::make_shared<Texture>(texturePath);
}

void Cup::setPosition(const glm::vec3& position) {
    m_Position = position;
    updateModelMatrix();
}

void Cup::setRotation(float angle, const glm::vec3& axis) {
    m_RotationAngle = angle;
    m_RotationAxis = axis;
    updateModelMatrix();
}

void Cup::setScale(const glm::vec3& scale) {
    m_Scale = scale;
    updateModelMatrix();
}

void Cup::setParentModel(glm::mat4 pModel) {
    m_ParentModel = pModel;
}

void Cup::updateModelMatrix() {
    m_Model = glm::mat4(1.0f);
    m_Model = glm::translate(m_Model, m_Position);
    m_Model = glm::rotate(m_Model, glm::radians(m_RotationAngle), m_RotationAxis);
    m_Model = glm::scale(m_Model, m_Scale);
    m_Model = m_ParentModel * m_Model;
}

void Cup::generateVertices(float* vertices, int& vertexCount) {
        float angleStep = 360.0f / m_SegmentCount;
        int index = 0;

        // Outer surface
        for (int i = 0; i < m_SegmentCount; ++i) {
            float angle1 = glm::radians(i * angleStep);
            float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

            // Top outer edge vertices
            float x1OuterTop = m_TopRadius * cos(angle1);
            float z1OuterTop = m_TopRadius * sin(angle1);
            float x2OuterTop = m_TopRadius * cos(angle2);
            float z2OuterTop = m_TopRadius * sin(angle2);

            // Bottom outer edge vertices
            float x1OuterBottom = m_BottomRadius * cos(angle1);
            float z1OuterBottom = m_BottomRadius * sin(angle1);
            float x2OuterBottom = m_BottomRadius * cos(angle2);
            float z2OuterBottom = m_BottomRadius * sin(angle2);

            // Triangle 1 (outer side)
            vertices[index++] = x1OuterBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1OuterBottom;
            vertices[index++] = x1OuterBottom; vertices[index++] = 0.0f; vertices[index++] = z1OuterBottom;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x1OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = x1OuterTop; vertices[index++] = 0.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x2OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = x2OuterTop; vertices[index++] = 0.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;

            // Triangle 2 (outer side)
            vertices[index++] = x1OuterBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1OuterBottom;
            vertices[index++] = x1OuterBottom; vertices[index++] = 0.0f; vertices[index++] = z1OuterBottom;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x2OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = x2OuterTop; vertices[index++] = 0.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x2OuterBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2OuterBottom;
            vertices[index++] = x2OuterBottom; vertices[index++] = 0.0f; vertices[index++] = z2OuterBottom;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;
        }

        // Inner surface
        float innerTopRadius = m_TopRadius - m_Thickness;
        float innerBottomRadius = m_BottomRadius - m_Thickness;
        for (int i = 0; i < m_SegmentCount; ++i) {
            float angle1 = glm::radians(i * angleStep);
            float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

            // Top inner edge vertices
            float x1InnerTop = innerTopRadius * cos(angle1);
            float z1InnerTop = innerTopRadius * sin(angle1);
            float x2InnerTop = innerTopRadius * cos(angle2);
            float z2InnerTop = innerTopRadius * sin(angle2);

            // Bottom inner edge vertices
            float x1InnerBottom = innerBottomRadius * cos(angle1);
            float z1InnerBottom = innerBottomRadius * sin(angle1);
            float x2InnerBottom = innerBottomRadius * cos(angle2);
            float z2InnerBottom = innerBottomRadius * sin(angle2);

            // Triangle 1 (inner side)
            vertices[index++] = x1InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = x1InnerTop; vertices[index++] = 0.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x1InnerBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z1InnerBottom;
            vertices[index++] = x1InnerBottom; vertices[index++] = 0.0f; vertices[index++] = z1InnerBottom;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x2InnerBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2InnerBottom;
            vertices[index++] = x2InnerBottom; vertices[index++] = 0.0f; vertices[index++] = z2InnerBottom;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

            // Triangle 2 (inner side)
            vertices[index++] = x1InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = x1InnerTop; vertices[index++] = 0.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x2InnerBottom; vertices[index++] = -m_Height / 2.0f; vertices[index++] = z2InnerBottom;
            vertices[index++] = x2InnerBottom; vertices[index++] = 0.0f; vertices[index++] = z2InnerBottom;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x2InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2InnerTop;
            vertices[index++] = x2InnerTop; vertices[index++] = 0.0f; vertices[index++] = z2InnerTop;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;
        }

        // Rim surface
        for (int i = 0; i < m_SegmentCount; ++i) {
            float angle1 = glm::radians(i * angleStep);
            float angle2 = glm::radians((i + 1) % m_SegmentCount * angleStep);

            // Outer rim vertices
            float x1OuterTop = m_TopRadius * cos(angle1);
            float z1OuterTop = m_TopRadius * sin(angle1);
            float x2OuterTop = m_TopRadius * cos(angle2);
            float z2OuterTop = m_TopRadius * sin(angle2);

            // Inner rim vertices
            float x1InnerTop = innerTopRadius * cos(angle1);
            float z1InnerTop = innerTopRadius * sin(angle1);
            float x2InnerTop = innerTopRadius * cos(angle2);
            float z2InnerTop = innerTopRadius * sin(angle2);

            // Triangle 1 (rim)
            vertices[index++] = x1OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = x1OuterTop; vertices[index++] = 0.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x1InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = x1InnerTop; vertices[index++] = 0.0f; vertices[index++] = z1InnerTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x2InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2InnerTop;
            vertices[index++] = x2InnerTop; vertices[index++] = 0.0f; vertices[index++] = z2InnerTop;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

            // Triangle 2 (rim)
            vertices[index++] = x1OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = x1OuterTop; vertices[index++] = 0.0f; vertices[index++] = z1OuterTop;
            vertices[index++] = static_cast<float>(i) / m_SegmentCount; vertices[index++] = 1.0f;

            vertices[index++] = x2InnerTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2InnerTop;
            vertices[index++] = x2InnerTop; vertices[index++] =
                0.0f; vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 0.0f;

            vertices[index++] = x2OuterTop; vertices[index++] = m_Height / 2.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = x2OuterTop; vertices[index++] = 0.0f; vertices[index++] = z2OuterTop;
            vertices[index++] = static_cast<float>(i + 1) / m_SegmentCount; vertices[index++] = 1.0f;
        }

        vertexCount = index / 8; // Update the actual number of vertices generated
}


void Cup::draw() {
    m_Shader->Bind();
    m_Shader->setUniformMat4f("model", m_Model);
    m_Shader->setUniformMat4f("view", Scene::getView());
    m_VAO->Bind();

    // Draw outer surface
    if (m_OuterTexture) {
        m_OuterTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, 0, m_SegmentCount * 6);

    // Draw inner surface
    if (m_InnerTexture) {
        m_InnerTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, m_SegmentCount * 6, m_SegmentCount * 6);

    // Draw rim
    if (m_RimTexture) {
        m_RimTexture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    }
    glDrawArrays(GL_TRIANGLES, m_SegmentCount * 12, m_SegmentCount * 6);

    m_Shader->Unbind();
    m_VAO->Unbind();
}
