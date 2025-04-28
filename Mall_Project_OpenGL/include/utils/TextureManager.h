#pragma once
#include "core.h"
#include "Texture.h"
class TextureManager {
    std::unordered_map<std::string, std::shared_ptr<Texture>> textureCache;
public:
    std::shared_ptr<Texture> getTexture(const std::string& texturePath) {
        if (textureCache.find(texturePath) == textureCache.end()) {
            textureCache[texturePath] = std::make_shared<Texture>(texturePath);
        }
        return textureCache[texturePath];
    }
};
