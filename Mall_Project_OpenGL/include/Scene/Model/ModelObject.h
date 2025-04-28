#pragma once
#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include "Model.h"
#include "Shader.h"
#include "PointLight.h"
#include "SpotLight.h"

class ModelObject :public Object {
public:
    //ModelObject() {};
    ModelObject(const std::string& modelPath, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans = glm::vec3(0.0f));
    ModelObject(ModelObject&&) noexcept = default;
    ModelObject& operator=(ModelObject&&) noexcept = default;
    ~ModelObject();

    void drawOpaque() override;
    void getTransparent() override;

    void updateUniforms();
    
    void onImguiRender();
    //void SetView(glm::mat4 view);
    //void SetProj(glm::mat4 proj);
    //void SetLightPos(glm::vec3 pos);
    //inline void toggleSpot() { isSpotOn = !isSpotOn; }
    //inline glm::vec3 getPos() const { return m_Pos; }
    //inline glm::vec3 getLightPos() const { return m_LightPos; }

private:
    std::unique_ptr<Model> m_LoadedModel;
    std::unique_ptr<Shader> m_Shader;

    //glm::vec3 m_Pos, m_LightPos;
 

    //LightColorProperties lightProp = LightHelper::getLightColor("default");
    //PointLight m_PointLight;
    //SpotLight m_SpotLight;
    //bool isSpotOn = false;
};
