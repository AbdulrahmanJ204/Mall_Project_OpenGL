#include "LightHelper.h"
std::map<int, Attenuation> LightHelper::attenuationMap = {
	{7, {1.0f, 0.7f, 1.8f}},
	{13, {1.0f, 0.35f, 0.44f}},
	{20, {1.0f, 0.22f, 0.20f}},
	{32, {1.0f, 0.14f, 0.07f}},
	{50, {1.0f, 0.09f, 0.032f}},
	{65, {1.0f, 0.07f, 0.017f}},
	{100, {1.0f, 0.045f, 0.0075f}},
	{160, {1.0f, 0.027f, 0.0028f}},
	{200, {1.0f, 0.022f, 0.0019f}},
	{325, {1.0f, 0.014f, 0.0007f}},
	{600, {1.0f, 0.007f, 0.0002f}},
	{3250, {1.0f, 0.0014f, 0.000007f}}
};


std::map<std::string, LightColorProperties> LightHelper::colorMap = {
	{"white", {glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f)}},
	{"red", {glm::vec3(0.3f, 0.0f, 0.0f), glm::vec3(0.7f, 0.0f, 0.0f), glm::vec3(1.0f, 0.5f, 0.5f)}},
	{"green", {glm::vec3(0.0f, 0.3f, 0.0f), glm::vec3(0.0f, 0.7f, 0.0f), glm::vec3(0.5f, 1.0f, 0.5f)}},
	{"blue", {glm::vec3(0.0f, 0.0f, 0.3f), glm::vec3(0.0f, 0.0f, 0.7f), glm::vec3(0.5f, 0.5f, 1.0f)}},
	{"yellow", {glm::vec3(0.3f, 0.3f, 0.0f), glm::vec3(0.7f, 0.7f, 0.0f), glm::vec3(1.0f, 1.0f, 0.5f)}},
	{"cyan", {glm::vec3(0.0f, 0.3f, 0.3f), glm::vec3(0.0f, 0.7f, 0.7f), glm::vec3(0.5f, 1.0f, 1.0f)}},
	{"magenta", {glm::vec3(0.3f, 0.0f, 0.3f), glm::vec3(0.7f, 0.0f, 0.7f), glm::vec3(1.0f, 0.5f, 1.0f)}},
	{"default", {glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f)}}
};
LightHelper::LightHelper()
{

}
