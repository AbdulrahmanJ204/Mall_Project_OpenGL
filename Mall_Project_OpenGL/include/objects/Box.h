#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
enum Face {
    Front,
    Back,
    Left,
    Right,
    Up,
    Down,
};
class Box {
public:
    Box(float width, float height, float depth, const std::string vertexPath, const std::string fragmentPath, glm::vec3 trans = glm::vec3(0.0f, 0.0f, 0.0f));
    ~Box();
    void setParentModel(glm::mat4 pModel);
    void setFaceTexture(Face face, const std::string& texturePath);
    void draw(const glm::mat4& view, const glm::mat4& projection);

    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    inline float getWidth() const { return m_Width;}
    inline float getHeight() const { return m_Height;}
    inline float getDepth() const { return m_Depth;}
private:
    float m_Width, m_Height, m_Depth;
    glm::mat4 m_Model , m_ParentModel;
    glm::vec3 m_Position, m_Scale;
    
    float m_RotationAngle;
    glm::vec3 m_RotationAxis;

    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::vector<std::shared_ptr<Texture>> m_Textures; // One texture for each face
    std::shared_ptr<Shader> m_Shader;

    void updateModelMatrix();
};
