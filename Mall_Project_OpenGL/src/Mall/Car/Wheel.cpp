#include <Mall/Car/Wheel.h>

Wheel::Wheel():
	c(0.5f, 0.5f, 0.3f, 32, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Wheel::drawOpaque()
{
	c.setParentModel(getModel());
	c.setRotation(90, glm::vec3(0.0f, 0.0f, 1.0f));
	c.drawOpaque();
}

void Wheel::getTransparent()
{
}

void Wheel::onImguiRender()
{
}

void Wheel::setTex()
{
	c.setSideTexture("assets/textures/wheel1.jpg");
	c.setBottomTexture("assets/textures/wheel2.png");
	c.setTopTexture("assets/textures/wheel2.png");
}
