#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
// TODO Edit transparent draw.
class Cylinder {
public:
    Cylinder(float topRadius, float bottomRadius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans = glm::vec3(0.0f));
    ~Cylinder();

    void setTopTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void setSideTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void setBottomTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void setParentModel(glm::mat4 pModel);
    void drawOpaque();
    void onImguiRender(std::string name = "Cylinder ");
    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);

private:
    float m_TopRadius, m_BottomRadius, m_Height;
    int m_SegmentCount;
    glm::mat4 m_Model, m_ParentModel;
    glm::vec3 m_Position, m_Scale;

    float m_RotationAngle;
    glm::vec3 m_RotationAxis;

    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Texture> m_TopTexture, m_SideTexture, m_BottomTexture;
    std::shared_ptr<Shader> m_Shader;
    bool isTransparentFace[3];
    void updateModelMatrix();
    void generateVertices(float* vertices, int& vertexCount);
};
