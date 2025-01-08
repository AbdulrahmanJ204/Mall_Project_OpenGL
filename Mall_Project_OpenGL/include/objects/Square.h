#pragma once
#include "core.h"
#include "Object.h"
#include "VBO.h"
#include "VAO.h"
#include "Texture.h"
#include "Shader.h"
//    ! NOTE:
//    ! Dont use this class 
//    ! If you want to make a square , use the box class and make the depth = 0.
//    ! or you can use it, but send the vertices :-)

class Square : public Object {
public:
    Square(const float* vertices, float size, const std::string& vertexPath, const std::string& fragmentPath);
    ~Square();

    void drawOpaque() override;
    void drawTransparent() override;
    float calculateDistanceToPlane(const glm::vec3& cameraPosition);
    void getTransparent() override;
    void onImguiRender() override;

    void setTexture(const std::string& texturePath, bool isTransparent, bool mirrorX, bool mirrorY);

private:
    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_Texture;
    glm::vec3 m_Normal;
    bool m_IsTransparent;
};