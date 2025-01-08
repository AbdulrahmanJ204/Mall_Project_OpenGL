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
}
void Mall::draw()
{
	setRotation(m_RotationAngle, m_RotationAxis);
	std::cout << m_RotationAngle << std::endl;
	chair.setParentModel(getModel());
	//cup.draw();
	//chair.setPosition(glm::vec3(0.0f, 400.0f, -800.0f));
	chair.draw();
	//cylinder.draw();
}


// #include "Mall.h"

// Mall::Mall():
// skybox(15000.0f, 15000.0f, 15000.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
// mall_front(60.9f,20.1f, 60.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {50, 50}}, }),
// plan_mall(63.0f, 1.5f, 63.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {50, 50}},{Face::Down, {25, 25}},{Face::Right, {50, 2}},{Face::Left, {50, 2}},{Face::Back, {50, 2}}, { Face::Front, {50, 2} } }),
// floor_1(20.0f, 1.0f, 59.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {50, 50}},{Face::Down, {25, 25}},{Face::Right, {50, 2}},{Face::Left, {50, 2}},{Face::Back, {50, 2}}, { Face::Front, {50, 2} } }),
// mall_back(60.0f, 20.0f, 60.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {50, 50}},{Face::Left, {50, 50}},{Face::Back, {50, 50}},{Face::Front, {50, 50}} ,{Face::Up, {20, 20}} }),
// adadaLeft(16.0f, 19.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {20, 20}},{Face::Left, {20, 20}},{Face::Back, {20, 20}},{Face::Front, {20, 20}} ,{Face::Up, {20, 20}} }),
// adadaRight(8.0f, 19.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {20, 20}},{Face::Left, {20, 20}},{Face::Back, {20, 20}},{Face::Front, {20, 20}} ,{Face::Up, {20, 20}} }),
// adadaMiddile(2.0f, 2.0f, 100.0f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
// plan(500.0f,0.001f, 500.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", {{Face::Up, {100, 100}},}),
// electronicRoom(),
// resturantRoom(),
// supermarketRoom(),
// caffeRoom(),
// libraryRoom(),
// iteBack(1.0f, 18.0f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
// iteFront(80.0f, 15.0f, 40.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
// {
// 	skybox.setParentModel(getModel());
// 	plan.setParentModel(getModel());
// 	mall_front.setParentModel(getModel());
// 	mall_back.setParentModel(getModel());
// 	plan_mall.setParentModel(getModel());
// 	floor_1.setParentModel(getModel());
// 	setTex();
// }

// void Mall::draw()
// {
// 	iteFront.setRotation(m_RotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
// 	iteBack.setRotation(m_RotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
// 	skybox.draw();
// 	mall_front.setPosition(glm::vec3(0.0f, +mall_front.getHeight() / 2 + plan_mall.getHeight()+0.01, 0.0f));
// 	mall_back.setPosition(glm::vec3(0.0f, +mall_back.getHeight() / 2 + plan_mall.getHeight() + 0.01 +0.001, 0.0f));
// 	adadaLeft.setPosition(glm::vec3(0.0f -22, +adadaLeft.getHeight() / 2 + plan_mall.getHeight() + 0.01 + 0.001, 0.0f));
// 	adadaRight.setPosition(glm::vec3(0.0f +14 +adadaRight.getWidth() / 2, +adadaRight.getHeight() / 2 + plan_mall.getHeight() + 0.01 + 0.001, 0.0f));
// 	plan_mall.setPosition(glm::vec3(0.0f, +plan_mall.getHeight() / 2 +0.001, 0.0f));
	
// 	plan.setPosition(glm::vec3(0.0f, -0.01f, 0.0f));
// 	iteBack.setPosition(glm::vec3(-70.0f, 1.01f+ iteFront.getHeight() / 2, 25.0f));
// 	iteFront.setPosition(glm::vec3(-100.0f,1.01f+iteFront.getHeight()/2, 0.0f));
// 	iteFront.draw();
// 	iteBack.draw();

// 	mall_front.draw();
// 	mall_back.draw();
// 	plan_mall.draw();
// 	adadaLeft.draw();
// 	adadaMiddile.draw();
// 	adadaRight.draw();
// 	plan.draw();

// 	floor_1.setPosition(glm::vec3(0.0f - 20, 10 + (floor_1.getHeight() / 2), 0.0f));
// 	floor_1.draw();
	
// 	floor_1.setPosition(glm::vec3(0.0f + 20, 10 +floor_1.getHeight() / 2 , 0.0f));
// 	floor_1.draw();
// 	//
// 	electronicRoom.draw();
// 	//resturantRoom.draw();
// 	//supermarketRoom.draw();
// 	//caffeRoom.draw();
// 	//libraryRoom.draw();
// 	//
	
// }
// void Mall::onImguiRender() {
// 	ImGui::SliderFloat("ITE Rotation ", &m_RotationAngle, 0.0f, 360.0f);
// }
// void Mall::setTex()
// {
// 	skybox.setFaceTexture(Face::Up, "assets/textures/skybox/Daylight Box_Top.png",0,0);
// 	skybox.setFaceTexture(Face::Down, "assets/textures/skybox/Daylight Box_Bottom.bmp", 0, 0);
// 	skybox.setFaceTexture(Face::Left, "assets/textures/skybox/Daylight Box_Left.bmp", 0, 0);
// 	skybox.setFaceTexture(Face::Right, "assets/textures/skybox/Daylight Box_Right.png", 0, 0);
// 	skybox.setFaceTexture(Face::Back, "assets/textures/skybox/Daylight Box_Front.bmp", 0, 0);
// 	skybox.setFaceTexture(Face::Front, "assets/textures/skybox/Daylight Box_Back.png", 0, 0);

// 	mall_front.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 0);
// 	mall_front.setFaceTexture(Face::Down, "assets/textures/plan/p6.jpg", 0, 0);
// 	mall_front.setFaceTexture(Face::Left, "assets/textures/mall_left.jpg", 0, 0);
// 	mall_front.setFaceTexture(Face::Right, "assets/textures/mall_right.jpg", 0, 0);
// 	mall_front.setFaceTexture(Face::Back, "assets/textures/mall_back.jpg", 0, 0);
// 	mall_front.setFaceTexture(Face::Front, "assets/textures/mall_front.jpg", 0, 0);

// 	plan_mall.setFaceTexture(Face::Up, "assets/textures/plan/p9.jpg", 0, 0);
// 	plan_mall.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
// 	plan_mall.setFaceTexture(Face::Left, "assets/textures/plan/p2.jpg", 1, 1);
// 	plan_mall.setFaceTexture(Face::Right, "assets/textures/plan/p2.jpg", 1, 1);
// 	plan_mall.setFaceTexture(Face::Back, "assets/textures/plan/p2.jpg", 1, 1);
// 	plan_mall.setFaceTexture(Face::Front, "assets/textures/plan/p2.jpg", 1, 1);

// 	mall_back.setFaceTexture(Face::Up, "assets/textures/plan/p11.jpg", 1, 1);
// 	mall_back.setFaceTexture(Face::Down, "assets/textures/plan/p10.jpg", 0, 0);
// 	mall_back.setFaceTexture(Face::Left, "assets/textures/plan/p8.jpg", 0, 0);
// 	mall_back.setFaceTexture(Face::Right, "assets/textures/plan/p8.jpg", 0, 0);
// 	mall_back.setFaceTexture(Face::Back, "assets/textures/plan/p8.jpg", 0, 0);
// 	mall_back.setFaceTexture(Face::Front, "assets/textures/plan/p8.jpg", 0, 0);

// 	plan.setFaceTexture(Face::Up, "assets/textures/plan/p5.png", 1, 1);
// 	plan.setFaceTexture(Face::Down, "assets/textures/plan/p2.jpg", 0, 0);
// 	plan.setFaceTexture(Face::Left, "assets/textures/plan/p2.jpg",0,0);
// 	plan.setFaceTexture(Face::Right, "assets/textures/plan/p2.jpg", 0, 0);
// 	plan.setFaceTexture(Face::Back, "assets/textures/plan/p2.jpg", 0, 0);
// 	plan.setFaceTexture(Face::Front, "assets/textures/plan/p2.jpg", 0, 0);

// 	adadaLeft.setFaceTexture(Face::Up, "assets/textures/plan/p9.jpg", 1, 1);
// 	adadaLeft.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaLeft.setFaceTexture(Face::Left, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaLeft.setFaceTexture(Face::Right, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaLeft.setFaceTexture(Face::Back, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaLeft.setFaceTexture(Face::Front, "assets/textures/plan/p9.jpg", 0, 0);

// 	adadaRight.setFaceTexture(Face::Up, "assets/textures/plan/p9.jpg", 1, 1);
// 	adadaRight.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaRight.setFaceTexture(Face::Left, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaRight.setFaceTexture(Face::Right, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaRight.setFaceTexture(Face::Back, "assets/textures/plan/p9.jpg", 0, 0);
// 	adadaRight.setFaceTexture(Face::Front, "assets/textures/plan/p9.jpg", 0, 0);

// 	adadaMiddile.setSideTexture("assets/textures/plan/p9.jpg");
// 	adadaMiddile.setBottomTexture("assets/textures/plan/p9.jpg");
// 	adadaMiddile.setTopTexture("assets/textures/plan/p9.jpg");
// 	floor_1.setFaceTexture(Face::Up, "assets/textures/plan/p10.jpg", 0, 0);
// 	floor_1.setFaceTexture(Face::Down, "assets/textures/plan/p11.jpg", 0, 0);
// 	floor_1.setFaceTexture(Face::Left, "assets/textures/plan/p11.jpg", 1, 1);
// 	floor_1.setFaceTexture(Face::Right, "assets/textures/plan/p11.jpg", 1, 1);
// 	floor_1.setFaceTexture(Face::Back, "assets/textures/plan/p2.jpg", 1, 1);
// 	floor_1.setFaceTexture(Face::Front, "assets/textures/plan/p2.jpg", 1, 1);

// 	iteFront.setFaceTexture(Face::Back, "assets/textures/ite/ite_back.png", 0, 0);
// 	iteFront.setFaceTexture(Face::Front, "assets/textures/ite/ite_front.png", 0, 0);
// 	iteFront.setFaceTexture(Face::Left, "assets/textures/ite/ite_left.png", 1, 1);
// 	iteFront.setFaceTexture(Face::Right, "assets/textures/ite/ite_left.png", 1, 1);

// 	iteBack.setFaceTexture(Face::Back, "assets/textures/ite/ite_title.png", 0, 0);
// 	iteBack.setFaceTexture(Face::Front, "assets/textures/ite/ite_title2.png", 0, 0);
// 	iteBack.setFaceTexture(Face::Left, "assets/textures/ite/ite_title.png", 1, 1);
// 	iteBack.setFaceTexture(Face::Right, "assets/textures/ite/ite_title2.png", 1, 1);
// }