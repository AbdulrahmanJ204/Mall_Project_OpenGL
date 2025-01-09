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
    m_VAO->AddBuffer(*m_VBO, layout);

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

void Square::drawTransparent() {
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

void Square::onImguiRender() {
    ImGui::SliderFloat3("Position", &m_Position.x, -100, 100);
}