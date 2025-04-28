#include "Library/clock.h" 


Clock::Clock() :
	Object(), clock(1.0f, 1.0f, 0.2f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", glm::vec3(0.0f, 0.0f, 0.0f))
{
	setTex();
}

void Clock::drawOpaque()
{
	clock.setParentModel(getModel());
	clock.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	clock.drawOpaque();
}

void Clock::setTex()
{
	std::string texturePath = "assets/textures/Library/clock.jpg";

	clock.setTopTexture(texturePath);
	clock.setBottomTexture(texturePath);
	clock.setSideTexture(texturePath);

}
