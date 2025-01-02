#pragma once

#include "core.h"
#include "Shader.h"

class Light {
public:
    virtual ~Light() = default;

    virtual void uploadToShader(Shader& shader, const std::string& uniformName) const = 0;
    template <typename T>
    void uploadLightsArray(Shader& shader, const std::string& uniformBaseName, const std::vector<T>& lights) {
        for (size_t i = 0; i < lights.size(); ++i) {
            std::string uniformName = uniformBaseName + "[" + std::to_string(i) + "]";
            lights[i].uploadToShader(shader, uniformName);
        }
    }
protected:
    glm::vec3 ambient = glm::vec3(0.0f);
    glm::vec3 diffuse = glm::vec3(0.0f);
    glm::vec3 specular= glm::vec3(0.0f);
};
