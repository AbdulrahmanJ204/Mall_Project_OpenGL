#include "electronic_room.h"

ElectronicRoom::ElectronicRoom():
electronic_wall_base(20.0f, 12.0f, 50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {2, 4}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
electronic_wall_sec(12.0f, 12.0f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
wall_front1(0.1f, 12.0f, 35.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
arma1(22.0f, 4.0f, 35.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
arma2(34.0f, 4.0001f, 17.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
raf(20.0f, 0.5f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
table(),
laptop(1),
washing_machine("assets/obj/cash_register/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
tableC1(0.8f, 0.8f, 0.05f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
tableC2(0.05f, 0.05f, 1.0f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{

	tvs.push_back(TV(1));
	setTex();
	

	electronic_wall_base.setPosition(glm::vec3((electronic_wall_base.getWidth() / 2),(electronic_wall_base.getHeight() / 2),(electronic_wall_base.getDepth() / 2)));
	electronic_wall_sec.setPosition(glm::vec3(20+(electronic_wall_sec.getWidth() / 2),(electronic_wall_sec.getHeight() / 2), (electronic_wall_sec.getDepth() / 2)));
	wall_front1.setPosition(glm::vec3(20+(wall_front1.getWidth() / 2),(wall_front1.getHeight() / 2), 15+(wall_front1.getDepth() / 2)));
	arma1.setPosition(glm::vec3((arma1.getWidth() / 2),12.01+(arma1.getHeight() / 2), 15+(arma1.getDepth() / 2)));
	arma2.setPosition(glm::vec3((arma2.getWidth() / 2),12.01+(arma2.getHeight() / 2),(arma2.getDepth() / 2)));

	//electronic_wall_base.setPosition(glm::vec3(-30 + (electronic_wall_base.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_base.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_base.getDepth() / 2) + 0.001));
	//electronic_wall_sec.setPosition(glm::vec3(-20 + (electronic_wall_sec.getWidth() / 2) + 0.1, 1.5f + (electronic_wall_sec.getHeight() / 2) + 0.015, 5.0f + (electronic_wall_sec.getDepth() / 2) + 0.001));
}

void ElectronicRoom::drawOpaque() {
	//Postions 
	
	//Draw
	electronic_wall_base.setParentModel(getModel());
	electronic_wall_sec.setParentModel(getModel());
	wall_front1.setParentModel(getModel());
	table.setParentModel(getModel());
	tvs[0].setParentModel(getModel());
	arma1.setParentModel(getModel());
	arma2.setParentModel(getModel());
	raf.setParentModel(getModel());

	electronic_wall_base.drawOpaque();
	washing_machine.setRotation(90, glm::vec3(1.0f, 0.0f, 0.0f));
	washing_machine.drawOpaque();

	
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
	arma1.drawOpaque();
	arma2.drawOpaque();

	raf.setPosition(glm::vec3(0.0f, 0.01f, 0.0f));
	raf.drawOpaque();
}

void ElectronicRoom::getTransparent() {
	tvs[0].setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tvs[0].setPosition(glm::vec3(7.9f, 2.95f, 12.3f));
	tvs[0].getTransparent();
	wall_front1.getTransparent();
	electronic_wall_sec.getTransparent();
}


void ElectronicRoom::onImguiRender() {
	ImGui::SliderFloat3("TableElectronic Position ", &m_Position.x, -100.0f, 100.0f);
}

void ElectronicRoom::setTex()
 {
	electronic_wall_base.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_7.png", 0, 1);
	electronic_wall_base.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_6.png", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Right, "assets/textures/electronic/t2.jpg", 1 );
	electronic_wall_base.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_7.png", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Front, "assets/textures/electronic/elecroom1_7.png", 0, 1,1);

	electronic_wall_sec.setFaceTexture(Face::Down, "assets/textures/electronic/t2.jpg", 1, 0);
	electronic_wall_sec.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	electronic_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0);
	electronic_wall_sec.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_3.png", 1);
	electronic_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg",1);
	electronic_wall_sec.setFaceTexture(Face::Front, "assets/textures/electronic/elecroom1_3.png", 1);

	wall_front1.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	wall_front1.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 0, 1);
	wall_front1.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0);
	wall_front1.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_1.png", 1);
	wall_front1.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg",0);
	wall_front1.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0);

	arma1.setFaceTexture(Face::Down, "assets/textures/electronic/elecroom1_4.png", 0);
	arma1.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_4.png", 0);
	arma1.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_4.png", 0);
	arma1.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_2.png", 0);
	arma1.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_4.png", 0);
	arma1.setFaceTexture(Face::Front, "assets/textures/electronic/elecroom1_4.png", 0);

	arma2.setFaceTexture(Face::Down, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_2.png", 0);
	arma2.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Front, "assets/textures/electronic/elecroom1_4.png", 0);
}						