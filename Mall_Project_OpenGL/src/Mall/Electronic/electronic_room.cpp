#include "electronic_room.h"

ElectronicRoom::ElectronicRoom():
electronic_wall_base(20.0f, 12.0f, 50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {10, 24}},{Face::Right, {1, 1}} ,{Face::Left, {24, 6}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
electronic_wall_sec(12.0f, 12.0f, 14.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
tv1(1),
table(),
laptop(1)
{
	setTex();

	electronic_wall_base.setPosition(glm::vec3((electronic_wall_base.getWidth() / 2),(electronic_wall_base.getHeight() / 2),(electronic_wall_base.getDepth() / 2)));
	electronic_wall_sec.setPosition(glm::vec3(20+(electronic_wall_sec.getWidth() / 2),(electronic_wall_sec.getHeight() / 2), (electronic_wall_sec.getDepth() / 2)));

	//electronic_wall_base.setPosition(glm::vec3(-30 + (electronic_wall_base.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_base.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_base.getDepth() / 2) + 0.001));
	//electronic_wall_sec.setPosition(glm::vec3(-20 + (electronic_wall_sec.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_sec.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_sec.getDepth() / 2) + 0.001));
}

void ElectronicRoom::drawOpaque() {
	//Postions 
	
	//Draw
	electronic_wall_base.setParentModel(getModel());
	electronic_wall_sec.setParentModel(getModel());
	table.setParentModel(getModel());
	tv1.setParentModel(getModel());

	electronic_wall_base.drawOpaque();
	electronic_wall_sec.drawOpaque();

	
	//tables
	table.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	table.setScale(2);
	table.setPosition(glm::vec3(7.6f, 2.01f, 35.14f));
	table.drawOpaque();
	table.setPosition(glm::vec3(15.0f, 2.01f, 35.14f));
	table.drawOpaque();
	table.setPosition(glm::vec3(7.6f, 2.01f, 12.45f));
	table.drawOpaque();
	table.setPosition(glm::vec3(15.0f, 2.01f, 12.45f));
	table.drawOpaque();
	laptop.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	laptop.setScale(1.5);
	laptop.setPosition(m_Position);
	laptop.drawOpaque();
}

void ElectronicRoom::getTransparent() {
	tv1.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tv1.setPosition(glm::vec3(7.9f, 2.95f, 12.3f));
	tv1.getTransparent();

	
}


void ElectronicRoom::onImguiRender() {
	ImGui::SliderFloat3("TableElectronic Position ", &m_Position.x, 0.0f, 50.0f);
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
	electronic_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 1);
	electronic_wall_sec.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 1);
	electronic_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg");
	electronic_wall_sec.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 1);

}						