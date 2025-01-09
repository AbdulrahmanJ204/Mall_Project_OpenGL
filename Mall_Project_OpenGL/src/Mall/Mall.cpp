#include "Mall.h"
#include <Scene.h>

Mall::Mall() :Object(),
//cup(30.0f, 20.0f, 30.0f, 5.0f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),

skybox(
	{
		"assets/textures/skybox1/right.jpg",
		"assets/textures/skybox1/left.jpg",
		"assets/textures/skybox1/top.jpg",
		"assets/textures/skybox1/bottom.jpg",
		"assets/textures/skybox1/front.jpg",
		"assets/textures/skybox1/back.jpg"
	}),
	mall(500.0f, 500.0f, 500.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
//model("assets/objects/soda_vending_machine/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag");
{
	//model = ModelObject("assets/objects/backpack/backpack.obj", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag");
	//ch.setParentModel(getModel());
	//cup.setInnerTexture("assets/textures/brickwall.jpg");
	//cup.setOuterTexture("assets/textures/container2.png");
	//cup.setRimTexture("assets/textures/container.jpg");
	//cup.setParentModel(getModel());
	//cylinder.setBottomTexture("assets/textures/brickwall.jpg");
	//cylinder.setSideTexture("assets/textures/container2.png");
	//cylinder.setTopTexture("assets/textures/container.jpg");
	//cylinder.setParentModel(getModel());
	//cylinder.setPosition(glm::vec3(100.0f, 100.0f, 100.0f));
	//model.setPosition(glm::vec3(100.0f, -100.0f, 100.0f));

	mall.setFaceTexture(Face::Up,	 "assets/textures/container.jpg");
	mall.setFaceTexture(Face::Down,  "assets/textures/container.jpg");
	mall.setFaceTexture(Face::Left,  "assets/textures/container.jpg");
	mall.setFaceTexture(Face::Right, "assets/textures/container.jpg");
	mall.setFaceTexture(Face::Back,  "assets/textures/container.jpg");
	mall.setFaceTexture(Face::Front, "assets/textures/container.jpg");
	//cylinder.setRotation(150.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	//chair.setParentModel(getModel());
	
}

void Mall::onImguiRender() {
	ImGui::SliderFloat("Mall Rotation ", &m_RotationAngle, 0.0f, 360.0f);
	ImGui::SliderFloat3("Mall Position ", &m_Position.x, -200.0f, 200.0f);
	resturant.onImguiRender();
	//model.onImguiRender();
	//cylinder.onImguiRender();
}
void Mall::drawOpaque()
{
	glm::mat4 p = Scene::getProjection(), v = Scene::getView();
	skybox.draw(v , p);
	updateModelMatrix();
	mall.setParentModel(getModel());
	mall.drawOpaque();
	resturant.setParentModel(getModel());
	resturant.drawOpaque();
	//setRotation(m_RotationAngle, m_RotationAxis);
	//std::cout << m_RotationAngle << std::endl;
	//cup.draw();
	//chair.setPosition(glm::vec3(0.0f, 400.0f, -800.0f));
	//model.setScale(glm::vec3(-1.0f, -1.0f, -1.0f));
	//model.draw();
	//cylinder.setParentModel(getModel());
	//cylinder.drawOpaque();
}

void Mall::drawTransparent()
{
	mall.drawTransparent();
	resturant.drawTransparent();
}
