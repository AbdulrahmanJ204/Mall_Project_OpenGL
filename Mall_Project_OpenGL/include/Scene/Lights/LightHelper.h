#pragma once
#include "core.h"
struct Attenuation {
	float constant;
	float linear;
	float quadratic;
};

struct LightColorProperties {
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
};

class LightHelper {
public:
	LightHelper();

	static Attenuation getAttenuationForRange(float distance) {
		if (!attenuationMap.count((int)distance)) return attenuationMap[50];
		std::cout << "Found ATT For : " << distance << std::endl;
		return attenuationMap[(int)distance];

	}
	
	static LightColorProperties getLightColor(const std::string& colorName) {
		if (colorMap.count(colorName)) {
			return colorMap[colorName];
		}
		else {
			spdlog::error("Color Not Found");
			return colorMap["default"];
		}
	}
private:
	static std::map<int, Attenuation> attenuationMap;
	static std::map<std::string, LightColorProperties> colorMap;
};