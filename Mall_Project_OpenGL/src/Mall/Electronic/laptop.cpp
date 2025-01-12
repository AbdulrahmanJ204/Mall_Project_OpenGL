#include "laptop.h"

Laptop::Laptop(int type) :
	type(type),
	laptop_back(0.7f, 0.4f, 0.02f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
	laptop_front(0.7f, 0.4f, 0.01f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
{

	setTex();
}

void Laptop::drawOpaque() {

	//Postions 
\
	//Draw
	laptop_back.setRotation(90, glm::vec3(1.0f, 0.0f, 0.0f));
	laptop_back.setParentModel(getModel());
	laptop_back.setPosition(glm::vec3(0, -0.2, 0.22));
	laptop_back.drawOpaque();
	laptop_front.setRotation(-10, glm::vec3(1.0f, 0.0f, 0.0f));
	laptop_front.setParentModel(getModel());
	laptop_front.drawOpaque();

}

void Laptop::getTransparent() {
	laptop_back.setRotation(90, glm::vec3(1.0f, 0.0f, 0.0f));
	laptop_back.setParentModel(getModel());
	laptop_back.setPosition(glm::vec3(1,-0.252, 0));
	laptop_back.getTransparent();
	laptop_front.setRotation(-10, glm::vec3(1.0f, 0.0f, 0.0f));
	laptop_front.setParentModel(getModel());
	laptop_front.getTransparent();
}


void Laptop::onImguiRender() {
}

void Laptop::setTex()
{
	if (type == 1) {
		laptop_front.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png", 0);
		laptop_front.setFaceTexture(Face::Up, "assets/textures/electronic/tv_55_2.png",0);
		laptop_front.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png", 0);
		laptop_front.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png", 0);
		laptop_front.setFaceTexture(Face::Back, "assets/textures/electronic/laptop_1_3.png", 0);
		laptop_front.setFaceTexture(Face::Front, "assets/textures/electronic/laptop_1_2.png", 0);

		laptop_back.setFaceTexture(Face::Down, "assets/textures/electronic/laptop_1_5.png", 0);
		laptop_back.setFaceTexture(Face::Up, "assets/textures/electronic/laptop_1_4.png",0);
		laptop_back.setFaceTexture(Face::Left, "assets/textures/electronic/laptop_1_6.png", 0);
		laptop_back.setFaceTexture(Face::Right, "assets/textures/electronic/laptop_1_6.png", 0);
		laptop_back.setFaceTexture(Face::Back, "assets/textures/electronic/laptop_1_1.png", 0);
		laptop_back.setFaceTexture(Face::Front, "assets/textures/electronic/tv_55_2.png", 0);
	}
	else if (type == 2) {
		laptop_front.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_front.setFaceTexture(Face::Up, "assets/textures/electronic/tv_1_3.png");
		laptop_front.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_front.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_front.setFaceTexture(Face::Back, "assets/textures/electronic/tv_1_2.png", 1);
		laptop_front.setFaceTexture(Face::Front, "assets/textures/electronic/tv_1_1.png", 1);

		laptop_back.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_back.setFaceTexture(Face::Up, "assets/textures/electronic/tv_1_3.png");
		laptop_back.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_back.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png", 1);
		laptop_back.setFaceTexture(Face::Back, "assets/textures/electronic/tv_1_1.png", 1);
		laptop_back.setFaceTexture(Face::Front, "assets/textures/electronic/tv_1_2.png", 1);
	}

}