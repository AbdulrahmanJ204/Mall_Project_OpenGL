#include "electronic_room.h"

ElectronicRoom::ElectronicRoom():
electronic_wall_base(10.0f, 8.484f, 24.94f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {10, 24}},{Face::Down, {10, 24}},{Face::Right, {1, 1}} ,{Face::Left, {24, 8}},{Face::Front, {10, 8}},{Face::Back, {10, 8}} }),
electronic_wall_sec(6.0f, 8.484f, 7.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
n(1.0f, 1.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
{
	setTex();
	x = -30;
	y = 1.5001f;
	z = 5.0001f;
	electronic_wall_base.setPosition(glm::vec3(-30 + (electronic_wall_base.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_base.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_base.getDepth() / 2) + 0.001));
	electronic_wall_sec.setPosition(glm::vec3(-20 + (electronic_wall_sec.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_sec.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_sec.getDepth() / 2) + 0.001));
}

void ElectronicRoom::draw() {
	//Postions 
	
	//Draw
	electronic_wall_base.draw();
	//electronic_wall_sec.draw();
	n.setPosition(glm::vec3(x+(n.getWidth()/2), y+ (n.getHeight()/2), z+(n.getDepth()/2)));
	//n.draw();
	glm::vec3 mm=glm::vec3(x + (n.getWidth() / 2), y + (n.getHeight() / 2), z + (n.getDepth() / 2));
	
}

void ElectronicRoom::onImguiRender() {
}

void ElectronicRoom::setTex()
 {
	electronic_wall_base.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	electronic_wall_base.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Right, "assets/textures/mall/m15.png", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);

	electronic_wall_sec.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	electronic_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);
}						