#pragma once
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Model.h"
#include "Shader.h"
#include "PointLight.h"
#include "SpotLight.h"

class ModelObject {
public:
    ModelObject() {};
    ModelObject(const std::string& modelPath, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans = glm::vec3(0.0f));
    ModelObject(ModelObject&&) noexcept = default;
    ModelObject& operator=(ModelObject&&) noexcept = default;
    ~ModelObject();

    void draw();
    void updateUniforms();
    void setParentModel(glm::mat4 pModel);

    void setPosition(const glm::vec3& position);
    void setRotation(float angle, const glm::vec3& axis);
    void setScale(const glm::vec3& scale);
    void updateModelMatrix();
    void onImguiRender();
    //void SetView(glm::mat4 view);
    //void SetProj(glm::mat4 proj);
    //void SetLightPos(glm::vec3 pos);
    //inline void toggleSpot() { isSpotOn = !isSpotOn; }
    //inline glm::vec3 getPos() const { return m_Pos; }
    //inline glm::vec3 getLightPos() const { return m_LightPos; }

private:
    std::unique_ptr<Model> m_Model;
    std::unique_ptr<Shader> m_Shader;

    glm::mat4 m_Proj, m_View, m_ModelTransform , m_ParentModel;
    //glm::vec3 m_Pos, m_LightPos;
    glm::vec3 m_Position, m_Scale, m_RotationAxis;
    float m_RotationAngle;


    //LightColorProperties lightProp = LightHelper::getLightColor("default");
    //PointLight m_PointLight;
    //SpotLight m_SpotLight;
    //bool isSpotOn = false;
};
