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
enum class  Color {
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	CYAN,
	MAGENTA,
	DEFAULT,

};
class LightHelper {
public:
	LightHelper();
	static Attenuation getAttenuationForRange(float dist) {
		auto distanceIDX = std::upper_bound(attMapIdx.begin(), attMapIdx.end(), (int)(dist)) - attMapIdx.begin() - 1;
		int distance = attMapIdx[distanceIDX];
		if (!attenuationMap.count((int)distance)) return attenuationMap[50];
		std::cout << "Found ATT For : " << distance << std::endl;
		return attenuationMap[(int)distance];

	}
	
	static LightColorProperties getLightColor(const Color& colorName) {
		if (colorMap.count(colorName)) {
			return colorMap[colorName];
		}
		else {
			spdlog::error("Color Not Found");
			return colorMap[Color::DEFAULT];
		}
	}
private:
	static std::map<int, Attenuation> attenuationMap;
	static std::vector<int>  attMapIdx;
	static std::map<Color, LightColorProperties> colorMap;
};