#include "Square.h"
#include <VBOLayout.h>
#include <Scene.h>


Square::Square(const float* vertices ,float size, const std::string& vertexPath, const std::string& fragmentPath)
    : m_IsTransparent(false) {
    m_VAO = std::make_unique<VAO>();
    m_VBO = std::make_unique<VBO>(vertices, size );
    VBOLayout layout;
    layout.Push<float>(3); // Position
    layout.Push<float>(3); // Normals
    layout.Push<float>(2); // Texture coordinates
    m_Normal = glm::vec3(vertices[3], vertices[4], vertices[5]);
    m_VAO->AddBuffer(*m_VBO, layout);
    std::set<float> stx , sty , stz;
    for (int i = 0; i < 6; ++i) { // Assuming 4 vertices
        stx.insert(vertices[i * 8 + 0]); // x 
        sty.insert(vertices[i * 8 + 1]); // y coordinate
        stz.insert(vertices[i * 8 + 2]); // z coordinate
    }
    for (auto x : stx) {
        m_Center.x += x;
    }
    for (auto x : sty) {
        m_Center.y += x;
    }
    for (auto x : stz) {
        m_Center.z += x;
    }
    m_Center /= 4.0f; // Average
    m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);
    m_VAO->Unbind();
}

Square::~Square() {}

void Square::setTexture(const std::string& texturePath, bool isTransparent, bool mirrorX, bool mirrorY) {
    m_IsTransparent = isTransparent;
    m_Texture = std::make_shared<Texture>(texturePath, mirrorX, mirrorY);
}

void Square::drawOpaque() {
    if (m_IsTransparent) return;

    updateModelMatrix();
   
    m_Shader->Bind();
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->setUniformMat4f("model", getModel());
    m_Shader->setUniformMat4f("view", Scene::getView());

    //if (m_Texture) {
        m_Texture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    //}

    m_VAO->Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); // 6 vertices per face
    m_VAO->Unbind();
    m_Shader->Unbind();
}

void Square::drawTransparent()
{
    if (!m_IsTransparent) return;
    updateModelMatrix();
    m_Shader->Bind();
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->setUniformMat4f("model", getModel());
    m_Shader->setUniformMat4f("view", Scene::getView());

    //if (m_Texture) {
        m_Texture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    //}

    m_VAO->Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); // 6 vertices per face
    m_VAO->Unbind();
    m_Shader->Unbind();
}
float Square::calculateDistanceToPlane(const glm::vec3& cameraPosition)  {
    glm::vec3 transformedNormal = glm::mat3(glm::transpose(glm::inverse(getModel()))) * m_Normal;

    // Normalize the transformed normal to ensure it has unit length
    transformedNormal = glm::normalize(transformedNormal);

    // Calculate the distance from the camera to the plane in world space
    float distance = glm::dot(transformedNormal, cameraPosition - getModifiedPosition());
    return distance; // Perpendicular distance (unsigned)
}
void Square::getTransparent() {
    if (!m_IsTransparent) return;
    glm::vec3 pos(getModifiedPosition());
    Scene::addTransparent(this,m_Position);
}

void Square::onImguiRender() {
    ImGui::SliderFloat3("Position", &m_Position.x, -100, 100);
}