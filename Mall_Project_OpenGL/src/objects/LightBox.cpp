#include "LightBox.h"
#include <glm/gtc/matrix_transform.hpp>
#include <Scene.h>

LightBox::LightBox(float width, float height, float depth, const std::string& vertexPath, const std::string& fragmentPath, const faceRepeatMap& repeat, glm::vec3 trans)
    : m_Width(width), m_Height(height), m_Depth(depth) {

    // Default repetition values if not provided
    m_Repeat = {
            {Face::Back, {1, 1}},
            {Face::Front, {1, 1}},
            {Face::Left, {1, 1}},
            {Face::Right, {1, 1}},
            {Face::Up, {1, 1}},
            {Face::Down, {1, 1}}
    };
    for (const auto& pair : repeat) {
        m_Repeat[pair.first] = pair.second;
    }
    // Extract repetition values for each face
    auto backRepeat = m_Repeat[Face::Back];
    auto frontRepeat = m_Repeat[Face::Front];
    auto leftRepeat = m_Repeat[Face::Left];
    auto rightRepeat = m_Repeat[Face::Right];
    auto upRepeat = m_Repeat[Face::Up];
    auto downRepeat = m_Repeat[Face::Down];

    // Define vertices for each face
    float backVertices[] = {
        // Back face
              -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 0.0f,
               width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 0.0f,
               width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 1.0f,

              -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 0.0f,
               width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 1.0f, backRepeat.second * 1.0f,
              -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  backRepeat.first * 0.0f, backRepeat.second * 1.0f,
    };

    float frontVertices[] = {
        // Front face
          -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 0.0f,
           width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 0.0f,
           width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 1.0f,

          -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 0.0f,
           width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 1.0f, frontRepeat.second * 1.0f,
          -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  frontRepeat.first * 0.0f, frontRepeat.second * 1.0f,
    };

    float leftVertices[] = {
        // Left face
            -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 0.0f,
            -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 1.0f,
            -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 1.0f,

            -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 1.0f, leftRepeat.second * 0.0f,
            -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 1.0f,
            -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  leftRepeat.first * 0.0f, leftRepeat.second * 0.0f,

    };

    float rightVertices[] = {
        // Right face
         width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 0.0f,
         width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 1.0f,
         width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 1.0f,

         width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 1.0f, rightRepeat.second * 0.0f,
         width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 1.0f,
         width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  rightRepeat.first * 0.0f, rightRepeat.second * 0.0f,
    };

    float upVertices[] = {
        // Top face
        -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 1.0f,
         width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 1.0f,
         width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 0.0f,

        -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 1.0f,
         width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 1.0f, upRepeat.second * 0.0f,
        -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  upRepeat.first * 0.0f, upRepeat.second * 0.0f,
    };

    float downVertices[] = {
        // Bottom face
        -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 1.0f,
         width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 1.0f,
         width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 0.0f,

        -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 1.0f,
         width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 1.0f, downRepeat.second * 0.0f,
        -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  downRepeat.first * 0.0f, downRepeat.second * 0.0f,
    };

    // Create squares for each face
    m_Faces[static_cast<int>(Face::Back)] = std::make_unique<LightSquare>(backVertices,sizeof(backVertices), vertexPath, fragmentPath);
    m_Faces[static_cast<int>(Face::Front)] = std::make_unique<LightSquare>(frontVertices,sizeof(frontVertices), vertexPath, fragmentPath);
    m_Faces[static_cast<int>(Face::Left)] = std::make_unique<LightSquare>(leftVertices,sizeof(leftVertices),  vertexPath, fragmentPath);
    m_Faces[static_cast<int>(Face::Right)] = std::make_unique<LightSquare>(rightVertices,sizeof(rightVertices), vertexPath, fragmentPath);
    m_Faces[static_cast<int>(Face::Up)] = std::make_unique<LightSquare>(upVertices,sizeof(upVertices),  vertexPath, fragmentPath);
    m_Faces[static_cast<int>(Face::Down)] = std::make_unique<LightSquare>(downVertices,sizeof(downVertices), vertexPath, fragmentPath);
}

LightBox::~LightBox() {}

void LightBox::setFaceTexture(Face face, textureMap& texturePath, bool isTransparent, bool mirrorX, bool mirrorY) {
    int faceIndex = static_cast<int>(face);
    if (faceIndex >= 0 && faceIndex < 6) {
        m_Faces[faceIndex]->setTexture(texturePath, isTransparent, mirrorX, mirrorY);
    }
}

void LightBox::drawOpaque() {
    updateModelMatrix();
    for (auto& face : m_Faces) {
        face->setParentModel(getModel());
        face->drawOpaque();
    }
}

void LightBox::getTransparent() {
   updateModelMatrix();
    for (auto& face : m_Faces) {
        face->setParentModel(getModel());
        face->getTransparent();
    }
}

void LightBox::setFaceLight(Face face, std::vector<PointLight>& lights)
{
    int faceIndex = static_cast<int>(face);
    if (faceIndex >= 0 && faceIndex < 6) {
        m_Faces[faceIndex]->setLights(lights);
    }
}

void LightBox::onImguiRender(std::string name) {
    ImGui::SliderFloat3((name + " Position").c_str(), &m_Position.x, -300, 300);
    for (int i = 0; i < 6; ++i) {
        std::string faceName = name + " Face " + std::to_string(i);
        if (ImGui::TreeNode(faceName.c_str())) {
            m_Faces[i]->onImguiRender();
            ImGui::TreePop();
        }
    }
}