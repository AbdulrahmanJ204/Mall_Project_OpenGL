#include "drabzen.h"

Drabzen::Drabzen(float width) :Object(),
blor(width, 2.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
amod(0.15f, 0.15f, 2.2f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{

	blor.setFaceTexture(Face::Up, "assets/textures/plan/p14.png",1);
	blor.setFaceTexture(Face::Down, "assets/textures/plan/p14.png",1);
	blor.setFaceTexture(Face::Left, "assets/textures/plan/p14.png",1);
	blor.setFaceTexture(Face::Right, "assets/textures/plan/p14.png",1);
	blor.setFaceTexture(Face::Back, "assets/textures/plan/p14.png"),1;
	blor.setFaceTexture(Face::Front, "assets/textures/plan/p14.png",1);

	amod.setBottomTexture("assets/textures/plan/p11.jpg");
	amod.setSideTexture("assets/textures/plan/p11.jpg");
	amod.setTopTexture("assets/textures/plan/p11.jpg");

}

void Drabzen::drawOpaque()
{
	blor.setParentModel(getModel());
	amod.setParentModel(getModel());
	
	amod.setPosition(glm::vec3(0,1.1,0));
	amod.drawOpaque();
	/*amod.setPosition(glm::vec3(blor.getWidth(), 1.1, 0));
	amod.drawOpaque();*/
	
	
	
}

void Drabzen::getTransparent()
{
	blor.setPosition(glm::vec3(+0.0f + blor.getWidth() / 2, 0.0f + blor.getHeight() / 2, 0.0f));
	blor.getTransparent();
}

void Drabzen::onImguiRender()
{
	ImGui::SliderFloat3("Drabzen Position ", &m_Position.x, -200.0f, 200.0f);
}
