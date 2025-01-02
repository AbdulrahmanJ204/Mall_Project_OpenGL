#include "Mall.h"

Mall::Mall():
skybox(15000.0f, 15000.0f, 15000.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
mall(300.0f,100.0f, 200.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
plan(500.0f,0.001f, 500.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
	skybox.setParentModel(getModel());
	plan.setParentModel(getModel());
	mall.setParentModel(getModel());
}

void Mall::draw()
{
	//ch.draw();
	skybox.draw();
	mall.setPosition(glm::vec3(30.0f, +mall.getHeight() / 2 , -130.0f));
	plan.setPosition(glm::vec3(0.0f, -0.01f, 0.0f));
	mall.draw();
	plan.draw();
}
void Mall::setTex()
{
	skybox.setFaceTexture(Face::Up, "assets/textures/skybox/Daylight Box_Top.png");
	skybox.setFaceTexture(Face::Down, "assets/textures/skybox/Daylight Box_Bottom.bmp");
	skybox.setFaceTexture(Face::Left, "assets/textures/skybox/Daylight Box_Left.bmp");
	skybox.setFaceTexture(Face::Right, "assets/textures/skybox/Daylight Box_Right.png");
	skybox.setFaceTexture(Face::Back, "assets/textures/skybox/Daylight Box_Back.png");
	skybox.setFaceTexture(Face::Front, "assets/textures/skybox/Daylight Box_Front.bmp");

	mall.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg");
	mall.setFaceTexture(Face::Down, "assets/textures/plan/p6.jpg");
	mall.setFaceTexture(Face::Left, "assets/textures/mall_left.jpg");
	mall.setFaceTexture(Face::Right, "assets/textures/plan/mall_left.jpg");
	mall.setFaceTexture(Face::Back, "assets/textures/mall.png");
	mall.setFaceTexture(Face::Front, "assets/textures/mall.png");

	plan.setFaceTexture(Face::Up, "assets/textures/plan/p5.png");
	plan.setFaceTexture(Face::Down, "assets/textures/plan/p2.jpg");
	plan.setFaceTexture(Face::Left, "assets/textures/plan/p2.jpg");
	plan.setFaceTexture(Face::Right, "assets/textures/plan/p2.jpg");
	plan.setFaceTexture(Face::Back, "assets/textures/plan/p2.jpg");
	plan.setFaceTexture(Face::Front, "assets/textures/plan/p2.jpg");
}