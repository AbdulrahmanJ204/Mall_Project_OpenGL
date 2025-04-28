#pragma once
#include "core.h"
#include "Shader.h"
class ShaderManager {
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaderCache;

public:
    // Get or load a shader
    std::shared_ptr<Shader> getShader(const std::string& vertexPath, const std::string& fragmentPath) {
        // Combine paths to form a unique key
        std::string key = vertexPath + "|" + fragmentPath;

        // Check if the shader already exists in the cache
        if (shaderCache.find(key) == shaderCache.end()) {
            // If not, create it and add it to the cache
            shaderCache[key] = std::make_shared<Shader>(vertexPath, fragmentPath);
        }

        // Return the cached shader
        return shaderCache[key];
    }
};