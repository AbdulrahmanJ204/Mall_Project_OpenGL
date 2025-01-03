#include "Mall.h"

Mall::Mall():
skybox(15000.0f, 15000.0f, 15000.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
mall(12.0f,4.0f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
plan(500.0f,0.001f, 500.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag",100,100),
cup(30.0f, 20.0f, 30.0f, 5.0f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
cylinder(30.0f , 20.0f , 100.0f , 300 , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
chair()
{
	skybox.setParentModel(getModel());
	plan.setParentModel(getModel());
	mall.setParentModel(getModel());
	setTex();
}

void Mall::draw()
{
	skybox.draw();
	mall.setPosition(glm::vec3(30.0f, +mall.getHeight() / 2 , -30.0f));
	plan.setPosition(glm::vec3(0.0f, -0.01f, 0.0f));
	mall.setRotation(m_RotationAngle, glm::vec3(1.0f, 1.0f, 0.0f));
	mall.draw();
	plan.draw();
}
void Mall::onImguiRender() {
	ImGui::SliderFloat("Mall Rotation ", &m_RotationAngle, 0.0f, 360.0f);
}
void Mall::setTex()
{
	skybox.setFaceTexture(Face::Up, "assets/textures/skybox/Daylight Box_Top.png",0,0);
	skybox.setFaceTexture(Face::Down, "assets/textures/skybox/Daylight Box_Bottom.bmp", 0, 0);
	skybox.setFaceTexture(Face::Left, "assets/textures/skybox/Daylight Box_Left.bmp", 0, 0);
	skybox.setFaceTexture(Face::Right, "assets/textures/skybox/Daylight Box_Right.png", 0, 0);
	skybox.setFaceTexture(Face::Back, "assets/textures/skybox/Daylight Box_Front.bmp", 0, 0);
	skybox.setFaceTexture(Face::Front, "assets/textures/skybox/Daylight Box_Back.png", 0, 0);

	mall.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 0);
	mall.setFaceTexture(Face::Down, "assets/textures/plan/p6.jpg", 0, 0);
	mall.setFaceTexture(Face::Left, "assets/textures/mall_left.jpg", 0, 0);
	mall.setFaceTexture(Face::Right, "assets/textures/mall_right.jpg", 0, 0);
	mall.setFaceTexture(Face::Back, "assets/textures/mall_back.jpg", 0, 0);
	mall.setFaceTexture(Face::Front, "assets/textures/mall_front.jpg", 0, 0);

	plan.setFaceTexture(Face::Up, "assets/textures/plan/p2.jpg", 1, 1);
	plan.setFaceTexture(Face::Down, "assets/textures/plan/p2.jpg", 0, 0);
	plan.setFaceTexture(Face::Left, "assets/textures/plan/p2.jpg",0,0);
	plan.setFaceTexture(Face::Right, "assets/textures/plan/p2.jpg", 0, 0);
	plan.setFaceTexture(Face::Back, "assets/textures/plan/p2.jpg", 0, 0);
	plan.setFaceTexture(Face::Front, "assets/textures/plan/p2.jpg", 0, 0);
}