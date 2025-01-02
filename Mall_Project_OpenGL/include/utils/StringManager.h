#pragma once
#include "string"
class StringManager {
static std::string texturesPath;
static std::string objectsPath;
static std::string shadersPath;
};

std::string StringManager::texturesPath = "assets/objects/";
std::string StringManager::shadersPath =  "assets/shaders/";
std::string StringManager::objectsPath =  "assets/textures/";