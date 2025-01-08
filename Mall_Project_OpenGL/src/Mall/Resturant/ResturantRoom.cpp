#include "ResturantRoom.h"


ResturantRoom::ResturantRoom():
room(300.0f, 300.0f, 300.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
cylinder(30.0f, 20.0f, 100.0f, 6, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
chair()
{
	
	setTex();

}


void ResturantRoom::drawOpaque()
{
	updateModelMatrix();
	chair.setParentModel(getModel());
	cylinder.setParentModel(getModel());
	room.setParentModel(getModel());

	chair.drawOpaque();
	cylinder.drawOpaque();
	room.drawOpaque();
}

void ResturantRoom::getTransparent()
{
	room.getTransparent();
	cylinder.getTransparent();
	chair.getTransparent();
}

void ResturantRoom::onImguiRender()
{
	ImGui::SliderFloat3("Resturant", &m_Position.x, -200, 200);
	room.onImguiRender("Resturnant Room");
	chair.onImguiRender();
	cylinder.onImguiRender();
}

void ResturantRoom::setTex()
{

	room.setFaceTexture(Face::Up,    "assets/textures/container2.png");
	room.setFaceTexture(Face::Down,  "assets/textures/container2.png");
	room.setFaceTexture(Face::Left,  "assets/textures/container2.png");
	room.setFaceTexture(Face::Right, "assets/textures/container2.png");
	room.setFaceTexture(Face::Back,  "assets/textures/container2.png");
	room.setFaceTexture(Face::Front, "assets/textures/container2.png");

	cylinder.setBottomTexture("assets/textures/brickwall.jpg");
	cylinder.setSideTexture("assets/textures/container2.png");
	cylinder.setTopTexture("assets/textures/container.jpg");
}
