#include "ModelObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "Scene.h"

ModelObject::ModelObject()
    : m_Model(nullptr),
    m_Shader(nullptr),
    m_ModelTransform(glm::mat4(1.0f)),
    m_View(glm::mat4(1.0f)),
    m_Proj(glm::mat4(1.0f)),
    m_Pos(glm::vec3(0.0f)),
    m_LightPos(glm::vec3(10.0f, 10.0f, 20.0f)),
    m_PointLight(m_LightPos, lightProp, 600.0f),
    m_SpotLight(m_LightPos, glm::vec3(0.0f, 0.0f, 0.0f), lightProp, 30.0f)
{
    int width, height;
    glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
    m_Proj = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / height, 0.1f, 2000.0f);
}

ModelObject::ModelObject(const std::string& modelPath, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans)
    : ModelObject() // Initialize defaults
{
    m_Pos = trans;
    m_Model = std::make_unique<Model>(modelPath);
    m_Shader = std::make_unique<Shader>(vertexPath, fragPath);
    m_ModelTransform = glm::translate(glm::mat4(1.0f), trans);
}

ModelObject::~ModelObject() {}

void ModelObject::draw() {
    if (m_Shader) {
        m_Shader->Bind();
        updateUniforms();
        if (m_Model) {
            m_Model->Draw(*m_Shader);
        }
    }
}

void ModelObject::updateUniforms() {
    if (!m_Shader) return;

    m_Shader->Bind();
    m_Shader->setUniformMat4f("model", m_ModelTransform);
    m_Shader->setUniformMat4f("view", m_View);
    m_Shader->setUniformMat4f("projection", m_Proj);

    if (m_Shader->getPath().find("light_cube") != std::string::npos) return;

    m_Shader->SetUniform3fv("viewPos", Scene::instancePtr->getCameraPosition());
    m_PointLight.updatePosition(m_LightPos);
    m_PointLight.uploadToShader(*m_Shader, "pointLight");

    if (isSpotOn) {
        m_SpotLight.updateDircetion(Scene::instancePtr->getCamera().Front);
        m_SpotLight.updatePosition(Scene::instancePtr->getCameraPosition());
        m_SpotLight.uploadToShader(*m_Shader, "spotLight");
    }
    else {
        m_SpotLight.turnOff(*m_Shader, "spotLight");
    }

    m_Shader->SetUniform1f("shininess", 8.0f);
}

void ModelObject::Rotate(float degree, glm::vec3& axis) {
    m_ModelTransform = glm::rotate(m_ModelTransform, glm::radians(degree), axis);
}

void ModelObject::Translate(glm::vec3& translate) {
    m_ModelTransform = glm::translate(m_ModelTransform, translate);
    m_Pos += translate;
}

void ModelObject::Scale(glm::vec3& scale) {
    m_ModelTransform = glm::scale(m_ModelTransform, scale);
}

void ModelObject::Scale(float scale) {
    m_ModelTransform = glm::scale(m_ModelTransform, glm::vec3(scale));
}

void ModelObject::SetView(glm::mat4 view) {
    m_View = view;
}

void ModelObject::SetProj(glm::mat4 proj) {
    m_Proj = proj;
}

void ModelObject::SetLightPos(glm::vec3 pos) {
    m_LightPos = pos;
}
