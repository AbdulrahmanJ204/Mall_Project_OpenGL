#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
#include "Object.h"
// TODO Edit transparent draw.
class Cylinder : public Object {
public:
    Cylinder(float topRadius, float bottomRadius, float height, int segmentCount, const std::string& vertexPath, const std::string& fragmentPath, glm::vec3 trans = glm::vec3(0.0f));
    ~Cylinder();

    void setTopTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void setSideTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void setBottomTexture(const std::string& texturePath, bool mirrorX = false, bool mirrorY = false);
    void drawOpaque() override;
    void getTransparent() override;
    void onImguiRender(std::string name = "Cylinder ");
    
private:
    float m_TopRadius, m_BottomRadius, m_Height;
    int m_SegmentCount;


    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::shared_ptr<Texture> m_TopTexture, m_SideTexture, m_BottomTexture;
    std::shared_ptr<Shader> m_Shader;
    bool isTransparentFace[3];
    void generateVertices(float* vertices, int& vertexCount);
};
