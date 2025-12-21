#pragma once

#include "Light.h"
#include "LightHelper.h"
class PointLight : public Light {
public:
    PointLight(const glm::vec3& position,
        const glm::vec3& ambient,
        const glm::vec3& diffuse,
        const glm::vec3& specular, float linear, float quadratic,
        float constant = 1.0f) {
        this->position = position;
        this->ambient = ambient;
        this->diffuse = diffuse;
        this->specular = specular;
        this->constant = constant;
        this->linear = linear;
        this->quadratic = quadratic;
    }
    PointLight(const glm::vec3& position,
        const LightColorProperties lightProp, float range) {
        this->position = position;
        this->originalPosition = position;
        this->ambient = lightProp.ambient;
        this->diffuse = lightProp.diffuse;
        this->specular = lightProp.specular;

        Attenuation att = LightHelper::getAttenuationForRange(range);

        this->constant = att.constant;
        this->linear = att.linear;
        this->quadratic = att.quadratic;
    }
    void updatePosition(glm::vec3& pos) {
        this->position = pos;
    }
   
    void uploadToShader(Shader& shader, const std::string& uniformName) const override {
        shader.SetUniform3fv(uniformName + ".position", position);
        shader.SetUniform3fv(uniformName + ".ambient", ambient);
        shader.SetUniform3fv(uniformName + ".diffuse", diffuse);
        shader.SetUniform3fv(uniformName + ".specular", specular);
        shader.SetUniform1f(uniformName + ".constant", constant);
        shader.SetUniform1f(uniformName + ".linear", linear);
        shader.SetUniform1f(uniformName + ".quadratic", quadratic);
    }
    inline glm::vec3 getPosition() const { return originalPosition; }
    inline glm::vec3 getModifiedPosition() const { return position; }
private:
    glm::vec3 position, originalPosition;
    float constant, linear, quadratic;
};
