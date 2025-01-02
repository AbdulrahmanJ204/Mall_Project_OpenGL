#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"


class Cup {
public:
    Cup(float topRadius, float bottomRadius, float height, float thickness, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans = glm::vec3(0.0f));
    ~Cup();

    void setOuterTexture(const std::string& texturePath);
    void setInnerTexture(const std::string& texturePath);
    void setRimTexture(const std::string& texturePath);

    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    void setParentModel(glm::mat4 pModel);

    void draw();

private:
    void generateVertices(float* vertices, int& vertexCount);
    void updateModelMatrix();

    float m_TopRadius, m_BottomRadius, m_Height, m_Thickness;
    int m_SegmentCount;
    glm::mat4 m_Model;
    glm::vec3 m_Position;
    glm::vec3 m_Scale;
    float m_RotationAngle;
    glm::vec3 m_RotationAxis;
    glm::mat4 m_ParentModel;

    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_OuterTexture, m_InnerTexture, m_RimTexture;
};
