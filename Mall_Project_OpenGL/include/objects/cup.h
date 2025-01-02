#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"

class Cup {
public:
    Cup(float topRadius, float innerTopRadius, float bottomRadius, float innerBottomRadius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans = glm::vec3(0.0f));
    ~Cup();

    void setTopTexture(const std::string& texturePath);
    void setSideTexture(const std::string& texturePath);
    void setBottomTexture(const std::string& texturePath);
    void setParentModel(glm::mat4 pModel);
    void draw();

    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);

private:
    float m_TopRadius, m_BottomRadius, m_InnerTopRadius, m_InnerBottomRadius, m_Height;
    int m_SegmentCount;
    glm::mat4 m_Model, m_ParentModel;
    glm::vec3 m_Position, m_Scale;

    float m_RotationAngle;
    glm::vec3 m_RotationAxis;

    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Texture> m_TopTexture, m_SideTexture, m_BottomTexture;
    std::shared_ptr<Shader> m_Shader;

    void updateModelMatrix();
    void generateVertices(float* vertices, int& vertexCount);
};
