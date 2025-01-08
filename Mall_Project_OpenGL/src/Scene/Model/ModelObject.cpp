#include "ModelObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include "Scene.h"

//ModelObject::ModelObject()
    //: m_Model(nullptr),
    //m_Shader(nullptr),
    //m_ModelTransform(glm::mat4(1.0f)),
    //m_View(glm::mat4(1.0f)),
    //m_Proj(glm::mat4(1.0f)),
    //m_Pos(glm::vec3(0.0f)),
    //m_LightPos(glm::vec3(10.0f, 10.0f, 20.0f)),
    //m_PointLight(m_LightPos, lightProp, 600.0f),
    //m_SpotLight(m_LightPos, glm::vec3(0.0f, 0.0f, 0.0f), lightProp, 30.0f)
//{}

ModelObject::ModelObject(const std::string& modelPath, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans)
    :m_ModelTransform(1.0f), m_ParentModel(1.0f), m_Position(trans), m_Scale(1.0f),
    m_RotationAngle(0.0f), m_RotationAxis(0.0f, 1.0f, 0.0f) 
{
    m_Model = std::make_unique<Model>(modelPath);
    m_Shader = std::make_unique<Shader>(vertexPath, fragPath);
}

ModelObject::~ModelObject() {}

void ModelObject::draw() {
    updateModelMatrix();
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
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->setUniformMat4f("view", Scene::getView());

   /* if (m_Shader->getPath().find("light_cube") != std::string::npos) return;

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

    m_Shader->SetUniform1f("shininess", 8.0f);*/
}

void ModelObject::setParentModel(glm::mat4 pModel)
{
    m_ParentModel = pModel; 
}

void ModelObject::setPosition(const glm::vec3& position) {
    m_Position = position;
    updateModelMatrix();
}

void ModelObject::setRotation(float angle, const glm::vec3& axis) {
    m_RotationAngle = angle;
    m_RotationAxis = axis;
    updateModelMatrix();
}

void ModelObject::setScale(const glm::vec3& scale) {
    m_Scale = scale;
    updateModelMatrix();
}

void ModelObject::updateModelMatrix() {
    m_ModelTransform = glm::mat4(1.0f);
    m_ModelTransform = glm::translate(m_ModelTransform, m_Position);
    m_ModelTransform = glm::rotate(m_ModelTransform, glm::radians(m_RotationAngle), m_RotationAxis);
    m_ModelTransform = glm::scale(m_ModelTransform, m_Scale);
    m_ModelTransform = m_ParentModel * m_ModelTransform;
}

void ModelObject::onImguiRender()
{
    ImGui::SliderFloat3("Model Scale", &m_Scale.x, -1, 20);
}



//void ModelObject::SetLightPos(glm::vec3 pos) {
//    m_LightPos = pos;
//}
