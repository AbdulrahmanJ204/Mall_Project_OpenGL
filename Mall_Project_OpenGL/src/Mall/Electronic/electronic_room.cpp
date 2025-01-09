#include "electronic_room.h"

ElectronicRoom::ElectronicRoom():
electronic_wall_base(10.0f, 6.0f, 24.94f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {10, 24}},{Face::Right, {1, 1}} ,{Face::Left, {24, 6}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
electronic_wall_sec(6.0f, 6.0f, 7.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
n(1.5f, 0.9f, 0.01f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
table()
{
	setTex();

	electronic_wall_base.setPosition(glm::vec3((electronic_wall_base.getWidth() / 2),(electronic_wall_base.getHeight() / 2),(electronic_wall_base.getDepth() / 2)));
	electronic_wall_sec.setPosition(glm::vec3(-20 + (electronic_wall_sec.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_sec.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_sec.getDepth() / 2) + 0.001));

	//electronic_wall_base.setPosition(glm::vec3(-30 + (electronic_wall_base.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_base.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_base.getDepth() / 2) + 0.001));
	//electronic_wall_sec.setPosition(glm::vec3(-20 + (electronic_wall_sec.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_sec.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_sec.getDepth() / 2) + 0.001));
}

void ElectronicRoom::drawOpaque() {
	//Postions 
	
	//Draw
	electronic_wall_base.drawOpaque();
	electronic_wall_sec.drawOpaque();
	n.setPosition(glm::vec3(x+(n.getWidth()/2)+3, y+ (n.getHeight()/2),1+ z+(n.getDepth()/2)));
	n.drawOpaque();
	glm::vec3 mm=glm::vec3((n.getWidth() / 2),(n.getHeight() / 2),(n.getDepth() / 2));
	table.setParentModel(getModel());
	table.setPosition(glm::vec3(5, 1, 4 ));
	table.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	table.drawOpaque();
}

void ElectronicRoom::drawTransparent() {
	
}


void ElectronicRoom::onImguiRender() {
}

void ElectronicRoom::setTex()
 {
	electronic_wall_base.setFaceTexture(Face::Down, "assets/textures/electronic/t5.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Up, "assets/textures/electronic/t3.jpg", 1, 1);
	electronic_wall_base.setFaceTexture(Face::Left, "assets/textures/electronic/t4.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Right, "assets/textures/electronic/t2.jpg", 1 );
	electronic_wall_base.setFaceTexture(Face::Back, "assets/textures/electronic/t4.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Front, "assets/textures/electronic/t4.jpg", 0, 1,1);

	electronic_wall_sec.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	electronic_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);

	n.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png",1, 0, 0);
	n.setFaceTexture(Face::Up, "assets/textures/electronic/tv_1_3.png", 0, 0);
	n.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png", 0, 0);
	n.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png", 0, 0);
	n.setFaceTexture(Face::Back, "assets/textures/electronic/tv_1_2.png", 0, 0);
	n.setFaceTexture(Face::Front, "assets/textures/electronic/tv_1_1.png", 0, 0);
}						