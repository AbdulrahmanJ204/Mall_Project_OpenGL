#include "electronic_room.h"

ElectronicRoom::ElectronicRoom():
electronic_wall_base(20.0f, 12.0f, 49.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {2, 4}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {1,1}},{Face::Back, {10, 6}} }),
electronic_wall_sec(12.0f, 12.0f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
wall_front1(0.1f, 12.0f, 35.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
arma1(22.0f, 6.0f, 35.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
arma2(34.0f, 6.0001f, 17.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
raf(18.0f, 0.1f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
stand1(0.1f,6.1f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
mobile(4.0f,0.01f, 3.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
tstand1(2.0f,2.0f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
tstand2(2.0f,2.0f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
table(),
laptop1(1),
laptop2(2),
washing_machine("assets/obj/cash_register/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
tableC1(0.8f, 0.8f, 0.05f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
tableC2(0.05f, 0.05f, 1.0f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{

	tvs.push_back(TV(1));
	tvs.push_back(TV(1));
	tvs.push_back(TV(1));
	tvs.push_back(TV(3));
	tvs.push_back(TV(3));
	tvs.push_back(TV(2));
	tvs.push_back(TV(2));
	tvs.push_back(TV(2));
	tvs.push_back(TV(2));
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
	updateModelMatrix();
	electronic_wall_base.setParentModel(getModel());
	electronic_wall_sec.setParentModel(getModel());
	wall_front1.setParentModel(getModel());
	table.setParentModel(getModel());
	tvs[0].setParentModel(getModel());
	tvs[1].setParentModel(getModel());
	tvs[2].setParentModel(getModel());
	tvs[3].setParentModel(getModel());
	tvs[4].setParentModel(getModel());
	tvs[5].setParentModel(getModel());
	tvs[6].setParentModel(getModel());
	tvs[7].setParentModel(getModel());
	tvs[8].setParentModel(getModel());
	arma1.setParentModel(getModel());
	arma2.setParentModel(getModel());
	raf.setParentModel(getModel());
	laptop1.setParentModel(getModel());
	laptop2.setParentModel(getModel());
	stand1.setParentModel(getModel());
	mobile.setParentModel(getModel());
	tstand1.setParentModel(getModel());
	tstand2.setParentModel(getModel());

	electronic_wall_base.drawOpaque();

	
	//tables
	table.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	table.setScale(2);
	table.setPosition(glm::vec3(7.6f, 2.01f, 22.45f));
	table.drawOpaque();
	table.setPosition(glm::vec3(15.0f, 2.01f, 22.45f));
	table.drawOpaque();
	table.setPosition(glm::vec3(7.6f, 2.01f, 12.45f));
	table.drawOpaque();
	table.setPosition(glm::vec3(15.0f, 2.01f, 12.45f));
	table.drawOpaque();

	mobile.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	mobile.setPosition(glm::vec3(7.6f, 2.2f, 22.45f));
	mobile.drawOpaque();

	mobile.setPosition(glm::vec3(15.0f, 2.2f, 22.45f));
	mobile.drawOpaque();


	laptop1.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	laptop1.setScale(1.5);
	laptop1.setPosition(glm::vec3(8.0,2.4,10.5));
	laptop1.drawOpaque();
	laptop1.setScale(1.5);
	laptop1.setPosition(glm::vec3(8.0,2.4,12.5));
	laptop1.drawOpaque();
	laptop1.setPosition(glm::vec3(8.0,2.4,14.5));
	laptop1.drawOpaque();
	laptop1.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	laptop1.setPosition(glm::vec3(14.5,2.4,14.5));
	laptop1.drawOpaque();
	laptop1.setPosition(glm::vec3(14.5,2.4,12.5));
	laptop1.drawOpaque();
	laptop1.setPosition(glm::vec3(14.5,2.4,10.5));
	laptop1.drawOpaque();
	
	laptop2.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	laptop2.setScale(1.5);
	laptop2.setPosition(glm::vec3(15.5,2.4,10.5));
	laptop2.drawOpaque();
	laptop2.setScale(1.5);
	laptop2.setPosition(glm::vec3(15.5,2.4,12.5));
	laptop2.drawOpaque();
	laptop2.setPosition(glm::vec3(15.5,2.4,14.5));
	laptop2.drawOpaque();
	laptop2.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	laptop2.setPosition(glm::vec3(7.0,2.4,14.5));
	laptop2.drawOpaque();
	laptop2.setPosition(glm::vec3(7.0,2.4,12.5));
	laptop2.drawOpaque();
	laptop2.setPosition(glm::vec3(7.0,2.4,10.5));
	laptop2.drawOpaque();

	arma1.drawOpaque();
	arma2.drawOpaque();

	raf.setPosition(glm::vec3(6.0f + raf.getWidth() / 2, 2.01f+ raf.getHeight() / 2, 0.0f+ raf.getDepth() / 2));
	raf.drawOpaque();
	raf.setPosition(glm::vec3(6.0f + raf.getWidth() / 2, 6.01f+ raf.getHeight() / 2, 0.0f+ raf.getDepth() / 2));
	raf.drawOpaque();

	stand1.setPosition(glm::vec3(30.0f , 2.01f+ stand1.getHeight() / 2, 1.5f+ stand1.getDepth() / 2));
	stand1.drawOpaque();
	tstand1.setPosition(glm::vec3(30.0f , 0.01f+ tstand1.getHeight() / 2, 1.5f+ stand1.getDepth() / 2));
	tstand1.drawOpaque();
}

void ElectronicRoom::getTransparent() {
	/*tvs[0].setRotation(90, glm::vec3(0.0f, 1.0f, raf.getDepth() / 2));*/
	tvs[0].setScale(1.5);
	tvs[0].setPosition(glm::vec3(9.0f, 3.3f, raf.getDepth() / 2));
	tvs[0].getTransparent();
	tvs[1].setScale(1.5);
	tvs[1].setPosition(glm::vec3(15.0f, 3.4f, raf.getDepth() / 2));
	tvs[1].getTransparent();
	tvs[2].setScale(1.5);
	tvs[2].setPosition(glm::vec3(21.0f, 3.4f, raf.getDepth() / 2));
	tvs[2].getTransparent();
	tvs[3].setScale(2);
	tvs[3].setPosition(glm::vec3(11.0f, 7.9f, raf.getDepth() / 2));
	tvs[3].getTransparent();
	tvs[4].setScale(2);
	tvs[4].setPosition(glm::vec3(19.0f, 7.9f, raf.getDepth() / 2));
	tvs[4].getTransparent();

	tvs[5].setScale(2);
	tvs[5].setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tvs[5].setPosition(glm::vec3(0.5f, 5.0f, 5));
	tvs[5].getTransparent();
	
	tvs[5].setScale(2);
	tvs[5].setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tvs[5].setPosition(glm::vec3(0.5f, 6.0f, 8));
	tvs[5].getTransparent();
	tvs[6].setScale(2);
	tvs[6].setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tvs[6].setPosition(glm::vec3(0.5f, 6.0f, 18));
	tvs[6].getTransparent();
	tvs[7].setScale(2);
	tvs[7].setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tvs[7].setPosition(glm::vec3(0.5f, 6.0f, 28));
	tvs[7].getTransparent();
	

	wall_front1.getTransparent();
	electronic_wall_sec.getTransparent();
}


void ElectronicRoom::onImguiRender() {
	ImGui::SliderFloat3("TableElectronic Position ", &m_Position.x, -100.0f, 100.0f);
	tvs[5].onImguiRender();
}

void ElectronicRoom::setTex()
 {
	electronic_wall_base.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_7.png", 0, 1);
	electronic_wall_base.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_6.png", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Right, "assets/textures/electronic/t2.jpg", 1 );
	electronic_wall_base.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_7.png", 0, 0);
	electronic_wall_base.setFaceTexture(Face::Front, "assets/textures/electronic/wall1.jpg", 0, 1,1);

	electronic_wall_sec.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 0, 0);
	electronic_wall_sec.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_4.png", 1, 1);
	electronic_wall_sec.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_7.png", 0);
	electronic_wall_sec.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_3.png", 1);
	electronic_wall_sec.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_7.png",1);
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
	arma2.setFaceTexture(Face::Right, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_4.png", 0);
	arma2.setFaceTexture(Face::Front, "assets/textures/electronic/elecroom1_4.png", 0);

	raf.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 0);
	raf.setFaceTexture(Face::Up, "assets/textures/electronic/t1.jpg", 0);
	raf.setFaceTexture(Face::Left, "assets/textures/electronic/t1.jpg", 0);
	raf.setFaceTexture(Face::Right, "assets/textures/electronic/t2.jpg", 0);
	raf.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 0);
	raf.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 0);

	stand1.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 0);
	stand1.setFaceTexture(Face::Up, "assets/textures/electronic/t1.jpg", 0);
	stand1.setFaceTexture(Face::Left, "assets/textures/electronic/stand.jpg", 0);
	stand1.setFaceTexture(Face::Right, "assets/textures/electronic/stand.jpg", 0);
	stand1.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 0);
	stand1.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 0);
	
	mobile.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg", 1);
	mobile.setFaceTexture(Face::Up, "assets/textures/electronic/mobile.png", 0);
	mobile.setFaceTexture(Face::Left, "assets/textures/electronic/stand.jpg", 1);
	mobile.setFaceTexture(Face::Right, "assets/textures/electronic/stand.jpg", 1);
	mobile.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 1);
	mobile.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 1);

	tstand1.setFaceTexture(Face::Down, "assets/textures/electronic/t3.jpg", 0);
	tstand1.setFaceTexture(Face::Up, "assets/textures/electronic/t3.jpg", 0);
	tstand1.setFaceTexture(Face::Left, "assets/textures/electronic/t3.jpg", 0);
	tstand1.setFaceTexture(Face::Right, "assets/textures/electronic/t3.jpg", 0);
	tstand1.setFaceTexture(Face::Back, "assets/textures/electronic/t3.jpg", 0);
	tstand1.setFaceTexture(Face::Front, "assets/textures/electronic/t3.jpg", 0);

	tstand2.setFaceTexture(Face::Down, "assets/textures/electronic/t3.jpg", 0);
	tstand2.setFaceTexture(Face::Up, "assets/textures/electronic/t3.jpg", 0);
	tstand2.setFaceTexture(Face::Left, "assets/textures/electronic/t1.jpg", 0);
	tstand2.setFaceTexture(Face::Right, "assets/textures/electronic/t2.jpg", 0);
	tstand2.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 0);
	tstand2.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 0);

}						