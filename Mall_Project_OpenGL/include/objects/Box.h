#pragma once
#include "core.h"
#include "Shader.h"
#include "Texture.h"
#include "VAO.h"
#include "VBO.h"
#include "Object.h"
#include "Square.h"
#define faceRepeatMap std::map<Face, std::pair<int, int>>
enum Face {
    Back,
    Front,
    Left,
    Right,
    Up,
    Down,
};

class Box : public Object {
public:
    Box(float width, float height, float depth, const std::string& vertexPath, const std::string& fragmentPath,
       const faceRepeatMap&  repeat = {
            {Face::Back, {1, 1}},
            {Face::Front, {1, 1}},
            {Face::Left, {1, 1}},
            {Face::Right, {1, 1}},
            {Face::Up, {1, 1}},
            {Face::Down, {1, 1}}
        },
        glm::vec3 trans = glm::vec3(0.0f, 0.0f, 0.0f));

    ~Box();
    void setFaceTexture(Face face, const std::string& texturePath, bool isTransparent = false, bool mirrorX = false, bool mirrorY = false);
    void drawOpaque() override;
    void drawTransparent() override;

    
    inline float getWidth() const { return m_Width; }
    inline float getHeight() const { return m_Height; }
    inline float getDepth() const { return m_Depth; }
    std::map<Face, std::pair<int, int>> m_Repeat;
    void onImguiRender(std::string name = "Box ");
private:
    float m_Width, m_Height, m_Depth;
    bool isTransparentFace[6] = { 0 };
    std::unique_ptr<VAO> m_VAO;
    std::unique_ptr<VBO> m_VBO;
    std::array<std::unique_ptr<Square>, 6> m_Faces;
    std::vector<std::shared_ptr<Texture>> m_Textures;
    std::shared_ptr<Shader> m_Shader;
};