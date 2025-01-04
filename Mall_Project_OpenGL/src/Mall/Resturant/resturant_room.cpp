#include "resturant_room.h"

ResturantRoom::ResturantRoom() :
	resturant_wall_base(10.0f, 8.484f, 25.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {10, 24}},{Face::Down, {10, 24}},{Face::Right, {24, 8}} ,{Face::Left, {24, 8}},{Face::Front, {10, 8}},{Face::Back, {10, 8}} }),
	resturant_wall_sec(6.0f, 8.484f, 7.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
	n(1.0f, 1.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
{
	x = -30.0001f;
	y = 1.5001f;
	z = -30.0001f;
	//Postions 
	resturant_wall_base.setPosition(glm::vec3(-30 + (resturant_wall_base.getWidth() / 2) + 0.1, 1.5f + (resturant_wall_base.getHeight() / 2) + 0.015, -30.0f + (resturant_wall_base.getDepth() / 2) + 0.001));
	resturant_wall_sec.setPosition(glm::vec3(-20 + (resturant_wall_sec.getWidth() / 2) + 0.1, 1.5f + (resturant_wall_sec.getHeight() / 2) + 0.015, -12.0f + (resturant_wall_sec.getDepth() / 2) + 0.001));

	n.setPosition(glm::vec3(x + (n.getWidth() / 2), y + (n.getHeight() / 2), z + (n.getDepth() / 2)));
	setTex();
}

void ResturantRoom::draw() {
	
	//Draw
	resturant_wall_base.draw();
	resturant_wall_sec.draw();

	n.draw();
}

void ResturantRoom::onImguiRender() {
}

void ResturantRoom::setTex()
{
	resturant_wall_base.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_base.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	resturant_wall_base.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_base.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_base.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_base.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);

	resturant_wall_sec.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_sec.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	resturant_wall_sec.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_sec.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_sec.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	resturant_wall_sec.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);
}