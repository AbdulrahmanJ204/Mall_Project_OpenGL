#include "supermarket_room.h"

SupermarketRoom::SupermarketRoom() :
	supermarket_wall_base(8.0f, 8.484f, 60.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {10, 60}},{Face::Down, {10, 60}},{Face::Right, {60, 8}} ,{Face::Left, {60, 8}},{Face::Front, {10, 8}},{Face::Back, {10, 8}} }),
	supermarket_wall_sec(6.0f, 8.484f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
	supermarket_wall_thi(6.0f, 8.484f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
	n(1.0f, 1.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
{
	x = 22.0001;
	y = 1.5001f;
	z = -30.0001f;
	//Postions 
	supermarket_wall_base.setPosition(glm::vec3(22 + (supermarket_wall_base.getWidth() /2) + 0.001, 1.5f + (supermarket_wall_base.getHeight() / 2) + 0.015, -30.0f + (supermarket_wall_base.getDepth() / 2) + 0.001));
	supermarket_wall_sec.setPosition(glm::vec3(16+ (supermarket_wall_sec.getWidth() / 2) - 0.001, 1.5f + (supermarket_wall_sec.getHeight() / 2) + 0.015, -30.0f + (supermarket_wall_sec.getDepth() / 2) + 0.001));
	supermarket_wall_thi.setPosition(glm::vec3(16+ (supermarket_wall_sec.getWidth() / 2) + 0.001, 1.5f + (supermarket_wall_sec.getHeight() / 2) + 0.015, 15 + (supermarket_wall_sec.getDepth() / 2) + 0.001));
	
	n.setPosition(glm::vec3(x + (n.getWidth() / 2), y + (n.getHeight() / 2), z + (n.getDepth() / 2)));
	setTex();
	
}

void SupermarketRoom::draw() {
	
	//Draw
	supermarket_wall_base.draw();
	supermarket_wall_sec.draw();
	supermarket_wall_thi.draw();
	
	
	n.draw();
}

void SupermarketRoom::onImguiRender() {
}

void SupermarketRoom::setTex()
{
	supermarket_wall_base.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_base.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	supermarket_wall_base.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_base.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_base.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_base.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);

	supermarket_wall_sec.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_sec.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	supermarket_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_sec.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_sec.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);

	supermarket_wall_thi.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_thi.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	supermarket_wall_thi.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_thi.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_thi.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	supermarket_wall_thi.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);
}