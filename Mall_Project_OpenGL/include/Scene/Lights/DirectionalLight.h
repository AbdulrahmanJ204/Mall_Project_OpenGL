#pragma once

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(const glm::vec3& direction,
        const glm::vec3& ambient,
        const glm::vec3& diffuse,
        const glm::vec3& specular) {
        this->direction = direction;
        this->ambient = ambient;
        this->diffuse = diffuse;
        this->specular = specular;
    }

    void uploadToShader(Shader& shader, const std::string& uniformName) const override {
        shader.SetUniform3fv(uniformName + ".direction", direction);
        shader.SetUniform3fv(uniformName + ".ambient", ambient);
        shader.SetUniform3fv(uniformName + ".diffuse", diffuse);
        shader.SetUniform3fv(uniformName + ".specular", specular);
    }

private:
    glm::vec3 direction;
};
