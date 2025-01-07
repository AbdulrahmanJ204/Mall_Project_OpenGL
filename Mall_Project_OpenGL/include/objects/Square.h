#pragma once
#include "core.h"
#include "Object.h"
#include "VBO.h"
#include "VAO.h"
#include "Texture.h"
#include "Shader.h"

class Square : public Object {
public:
    Square(const float* vertices, float size, const std::string& vertexPath, const std::string& fragmentPath);
    ~Square();

    void drawOpaque() override;
    void drawTransparent() override;
    void onImguiRender() override;

    void setTexture(const std::string& texturePath, bool isTransparent, bool mirrorX, bool mirrorY);

private:
    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Shader> m_Shader;
    std::shared_ptr<Texture> m_Texture;
    bool m_IsTransparent;
};