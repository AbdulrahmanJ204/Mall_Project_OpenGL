#include "Mall.h"
#include <Scene.h>

Mall::Mall() :
	skybox(
		{
			"assets/textures/skybox1/right.jpg",
			"assets/textures/skybox1/left.jpg",
			"assets/textures/skybox1/top.jpg",
			"assets/textures/skybox1/bottom.jpg",
			"assets/textures/skybox1/front.jpg",
			"assets/textures/skybox1/back.jpg"
		}),
	electronicRoom(),
	supermarketRoom(),
	libraryRoom(),
	caffeeRoom(),
	//restaurant(),
	worldplan(),
	mall_front(120.5f, 40.5f, 120.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 5}}, }),
	mall_wall1(55.25f, 40.1f, 0.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 5}}, }),
	mall_wall2(55.25f, 40.1f, 0.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 5}}, }),
	mall_wall3(10.0f, 40.1f, 0.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 5}}, }),
	market1(1.0f, 20.0f, 50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
	floor_1(40.0f, 2.0f, 119.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {10, 25}},{Face::Down, {25, 25}},{Face::Right, {50, 2}},{Face::Left, {50, 2}},{Face::Back, {50, 2}}, { Face::Front, {50, 2} } }),
	mmr(40.0f, 2.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5,10}},{Face::Down, {25, 25}},{Face::Right, {50, 2}},{Face::Left, {50, 2}},{Face::Back, {50, 2}}, { Face::Front, {50, 2} } }),
	mmrCenter(40.0f, 2.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5,10}},{Face::Down, {25, 25}},{Face::Right, {50, 2}},{Face::Left, {50, 2}},{Face::Back, {50, 2}}, { Face::Front, {50, 2} } }),
	mall_back(120.0f, 40.0f, 120.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {50, 50}},{Face::Left, {50, 50}},{Face::Back, {50, 50}},{Face::Front, {50, 50}} ,{Face::Up, {20, 20}} }),
	adadaLeft(32.0f, 40.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {5, 10}},{Face::Left, {20, 20}},{Face::Back, {20, 20}},{Face::Front, {20, 20}} ,{Face::Up, {20, 20}} }),
	adadaRight(16.0f, 40.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {20, 20}},{Face::Left, {20, 20}},{Face::Back, {20, 20}},{Face::Front, {20, 20}} ,{Face::Up, {20, 20}} }),
	darag1(4.0f, 2.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Down, {25, 25}},{Face::Right, {20, 20}},{Face::Left, {20, 20}},{Face::Back, {20, 20}},{Face::Front, {20, 20}} ,{Face::Up, {20, 20}} }),
	mosaad1(0.1f, 8.0f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	mosaad2(0.1f, 8.0f, 12.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	adadaMiddile(2.0f, 2.0f, 40.0f, 300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	bahra("assets/obj/medieval_fountain/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
	escalator("assets/obj/escalator/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
	dr1(40.4f),
	dr2(35.4f),
	dr3(40.4f),
	dr4(35.4f),
	dr5(40.4f),
	dr6(35.4f),
	dr7(40.4f),
	dr8(35.4f),
	doorMall(glm::vec3(0.0f, 5.0f, 60.1f), 10.0f, 10.0f, 0.05f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag",
		"assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	libraryRoom.setPosition(glm::vec3(-44.0f, 23.0f + mmr.getHeight() + 0.001f, -34.152f));

	setTex();
	mall_wall1.setPosition(glm::vec3(0.0f- mall_wall1.getWidth()/2 - mall_wall3.getWidth() / 2, +mall_front.getHeight() / 2 + 0.1f, 60.1f));
	mall_wall2.setPosition(glm::vec3(mall_wall2.getWidth()/2 + mall_wall3.getWidth() / 2, +mall_front.getHeight() / 2 + 0.1f, 60.1f));
	mall_wall3.setPosition(glm::vec3(0.0f, +mall_wall3.getHeight() / 2 + 0.1f, 60.1f));
}


void Mall::onImguiRender() {
	//ImGui::SliderFloat("Mall Rotation ", &m_RotationAngle, 0.0f, 360.0f);
	//ImGui::SliderFloat3(" Position ", &m_Position.x, -200.0f, 200.0f);
	//electronicRoom.onImguiRender();
	libraryRoom.onImguiRender();
}
void Mall::drawOpaque()
{
	drawSkyBox();
	updateModelMatrix();
	mall_front.setParentModel(getModel());
	mall_back.setParentModel(getModel());
	adadaLeft.setParentModel(getModel());
	adadaRight.setParentModel(getModel());
	floor_1.setParentModel(getModel());
	mmr.setParentModel(getModel());
	mall_wall1.setParentModel(getModel());
	mall_wall2.setParentModel(getModel());
	bahra.setParentModel(getModel());
	libraryRoom.setParentModel(getModel());
	caffeeRoom.setParentModel(getModel());
	mosaad1.setParentModel(getModel());
	mosaad2.setParentModel(getModel());
	doorMall.setParentModel(getModel());
	doorMall.update();

	electronicRoom.setPosition(glm::vec3(-59.8f, 0.12f, 10.01f));
	electronicRoom.drawOpaque();
	
<<<<<<< HEAD
	//restaurant.setPosition(glm::vec3(-40.8, 10.0f, -54.8));
	//restaurant.drawOpaque();
=======
	restaurant.setPosition(glm::vec3(-35.8, 10.0f, -52.8));
	restaurant.drawOpaque();
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4

	supermarketRoom.setPosition(glm::vec3(43.98f, 0.12f, -59.99f));
	supermarketRoom.drawOpaque();
	libraryRoom.setRotation(+90, glm::vec3(0.0f, 1.0f, 0.0f));
	libraryRoom.drawOpaque();

	//
	caffeeRoom.setRotation(180, glm::vec3(0, 1, 0));
	//caffeeRoom.setPosition(glm::vec3(-59.8, 18 + mmr.getHeight() + 0.001, -59.99));
	caffeeRoom.setPosition(glm::vec3(+59.8, 18 + mmr.getHeight() + 0.001, -10));
	caffeeRoom.drawOpaque();



  worldplan.setPosition(glm::vec3(0,0,20));
  	worldplan.drawOpaque();

	mall_front.setPosition(glm::vec3(0.0f, +mall_front.getHeight() / 2+ 0.1f, 0.0f));

	
	mall_back.setPosition(glm::vec3(0.0f, +mall_back.getHeight() / 2  + 0.1f + 0.001f, 0.0f));
	mall_front.drawOpaque();
	mall_back.drawOpaque();
	mall_wall1.drawOpaque();
	mall_wall2.drawOpaque();
	adadaLeft.setPosition(glm::vec3(0.0f - 44.0f, +adadaLeft.getHeight() / 2  + 0.01 + 0.001, 0.0f));
	adadaRight.setPosition(glm::vec3(0.0f + 28.0f + adadaRight.getWidth() / 2, +adadaRight.getHeight() / 2  + 0.01 + 0.001, 0.0f));
	darag1.setPosition(glm::vec3(0.0f -56.0f+ darag1.getWidth() / 2, adadaLeft.getHeight() / 4 +darag1.getHeight() / 2  + 0.01f + 0.001f, 0.0f));
	adadaMiddile.setPosition(glm::vec3(0.0f, +20.0f, 0.0f));
	adadaLeft.drawOpaque();
	adadaMiddile.drawOpaque();
	adadaRight.drawOpaque();
	darag1.drawOpaque();

	mosaad1.setPosition(glm::vec3(27.9f , +mosaad1.getHeight() / 2 + 0.01 + 0.001, 0.0f));
	mosaad1.drawOpaque();
	mosaad2.setPosition(glm::vec3(27.9f , 18.0f + mmr.getHeight() + 0.001f + mosaad1.getHeight() / 2 + 0.01f + 0.001f, 0.0f));
	mosaad2.drawOpaque();

	floor_1.setPosition(glm::vec3(0.0f - 40, 18 + (floor_1.getHeight() / 2), 0.0f));
	floor_1.drawOpaque();

	floor_1.setPosition(glm::vec3(0.0f + 40, 18 + floor_1.getHeight() / 2, 0.0f));
	floor_1.drawOpaque();

	market1.setPosition(glm::vec3(-35.01f + market1.getWidth() / 2, 19 + (floor_1.getHeight() / 2)+ (market1.getHeight() / 2)+0.001, 10.01 + market1.getDepth() / 2));
	market1.drawOpaque();
	market1.setPosition(glm::vec3(+35.01f + market1.getWidth() / 2, 19 + (floor_1.getHeight() / 2)+ (market1.getHeight() / 2)+0.001, 10.01 + market1.getDepth() / 2));
	market1.drawOpaque();

	mmr.setPosition(glm::vec3(0.0f, 18 + mmr.getHeight() / 2, 0.0f+60- mmr.getDepth() / 2));
	mmr.drawOpaque();
	mmr.setPosition(glm::vec3(0.0f, 18 + mmr.getHeight() / 2, 0.0f-60+ mmr.getDepth() / 2));
	mmr.drawOpaque();
	mmrCenter.setPosition(glm::vec3(0.0f, 18 + mmrCenter.getHeight() / 2,0));
	mmrCenter.drawOpaque();


	dr1.setPosition(glm::vec3(-20.2f, 18.0f + mmr.getHeight() + 0.001f, 40.2));
	dr1.drawOpaque();
	dr2.setRotation(90, glm::vec3(0, 1, 0));
	dr2.setPosition(glm::vec3(+20.2f, 18.0f + mmr.getHeight() + 0.001f, 40.2));
	dr2.drawOpaque();
	dr3.setRotation(180, glm::vec3(0, 1, 0));
	dr3.setPosition(glm::vec3(20.2f, 18.0f + mmr.getHeight() + 0.001f, 4.8));
	dr3.drawOpaque();
	dr4.setRotation(-90, glm::vec3(0, 1, 0));
	dr4.setPosition(glm::vec3(-20.2f, 18.0f + mmr.getHeight() + 0.001f, 4.8));
	dr4.drawOpaque();
	
	dr5.setPosition(glm::vec3(-20.2f, 18.0f + mmr.getHeight() + 0.001f, -40.2));
	dr5.drawOpaque();
	dr6.setRotation(-90, glm::vec3(0, 1, 0));
	dr6.setPosition(glm::vec3(+20.2f, 18.0f + mmr.getHeight() + 0.001f, -40.2));
	dr6.drawOpaque();
	dr7.setRotation(180, glm::vec3(0.0f, 1.0f, 0.0f));
	dr7.setPosition(glm::vec3(20.2f, 18.0f + mmr.getHeight() + 0.001f, -4.8));
	dr7.drawOpaque();
	dr8.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	dr8.setPosition(glm::vec3(-20.2f, 18.0f + mmr.getHeight() + 0.001f, -4.8));
	dr8.drawOpaque();

	escalator.setRotation(-90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	escalator.setScale(0.075f);
	escalator.setPosition(glm::vec3(4.04f, -1.01f, 0.0f));
	escalator.drawOpaque();
	
	escalator.setPosition(glm::vec3(-9.0f, -1.01f, 0.0f));
	escalator.drawOpaque();
}

void Mall::drawSkyBox()
{
	glm::mat4 p = Scene::getProjection(), v = Scene::getView();
	skybox.draw(v, p);
}

void Mall::getTransparent()
{
	doorMall.setParentModel(getModel());
	dr1.getTransparent();
	dr2.getTransparent();
	dr3.getTransparent();
	dr4.getTransparent();
	dr5.getTransparent();
	dr6.getTransparent();
	dr7.getTransparent();
	dr8.getTransparent();
	doorMall.getTransparent();
	worldplan.getTransparent();
	electronicRoom.getTransparent();
<<<<<<< HEAD
	//restaurant.getTransparent();
=======
	restaurant.getTransparent();
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
	supermarketRoom.getTransparent();
	//libraryRoom.getTransparent();
	mall_wall3.getTransparent();
	caffeeRoom.getTransparent();
	

}


void Mall::setTex()
{
	doorTexture doTexR = {

		{Face::Up,    "assets/textures/doors/d1_3.png"},
		{Face::Down,  "assets/textures/doors/d1_3.png"},
		{Face::Left,  "assets/textures/doors/d1_3.png"},
		{Face::Right, "assets/textures/doors/d1_3.png"},
		{Face::Back,  "assets/textures/doors/d1_3.png"},
		{Face::Front, "assets/textures/doors/d1_3.png"},
	};
	doorTexture doTexL = {

		{Face::Up,    "assets/textures/doors/d1_2.png"},
		{Face::Down,  "assets/textures/doors/d1_2.png"},
		{Face::Left,  "assets/textures/doors/d1_2.png"},
		{Face::Right, "assets/textures/doors/d1_2.png"},
		{Face::Back,  "assets/textures/doors/d1_2.png"},
		{Face::Front, "assets/textures/doors/d1_2.png"},
	};
	doorMall.setLeftTexture(doTexL);
	doorMall.setRightTexture(doTexR);

	mall_front.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 1, 1);
	mall_front.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 1, 0);
	mall_front.setFaceTexture(Face::Left, "assets/textures/mall/mall_left.jpg", 0, 0);
	mall_front.setFaceTexture(Face::Right, "assets/textures/mall/mall_right.jpg", 0, 0);
	mall_front.setFaceTexture(Face::Back, "assets/textures/mall/mall_back.jpg", 0, 0);
	mall_front.setFaceTexture(Face::Front, "assets/textures/mall/mall_front.png", 1);

	mall_wall1.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 1, 1);
	mall_wall1.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
	mall_wall1.setFaceTexture(Face::Left, "assets/textures/mall/mall_left.jpg", 0, 0);
	mall_wall1.setFaceTexture(Face::Right, "assets/textures/mall/mall_right.jpg", 0, 0);
	mall_wall1.setFaceTexture(Face::Back, "assets/textures/mall/mall_back.jpg", 0, 0);
	mall_wall1.setFaceTexture(Face::Front, "assets/textures/mall/mall_front1.png", 0);


	mall_wall2.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 1, 1);
	mall_wall2.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
	mall_wall2.setFaceTexture(Face::Left, "assets/textures/mall/mall_left.jpg", 0, 0);
	mall_wall2.setFaceTexture(Face::Right, "assets/textures/mall/mall_right.jpg", 0, 0);
	mall_wall2.setFaceTexture(Face::Back, "assets/textures/mall/mall_back.jpg", 0, 0);
	mall_wall2.setFaceTexture(Face::Front, "assets/textures/mall/mall_front2.png", 0);


	mall_wall3.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 0, 1, 1);
	mall_wall3.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
	mall_wall3.setFaceTexture(Face::Left, "assets/textures/mall/mall_left.jpg", 0, 0);
	mall_wall3.setFaceTexture(Face::Right, "assets/textures/mall/mall_right.jpg", 0, 0);
	mall_wall3.setFaceTexture(Face::Back, "assets/textures/mall/mall_back.jpg", 0, 0);
	mall_wall3.setFaceTexture(Face::Front, "assets/textures/mall/mall_front3.png", 1);



	mall_back.setFaceTexture(Face::Up, "assets/textures/plan/p6.jpg", 1, 1, 1);
	mall_back.setFaceTexture(Face::Down, "assets/textures/plan/p16.jpg", 0, 0);
	mall_back.setFaceTexture(Face::Left, "assets/textures/plan/p8.jpg", 0, 0);
	mall_back.setFaceTexture(Face::Right, "assets/textures/plan/p8.jpg", 0, 0);
	mall_back.setFaceTexture(Face::Back, "assets/textures/plan/p8.jpg", 0, 0);
	mall_back.setFaceTexture(Face::Front, "assets/textures/plan/p8.jpg", 1);

	adadaLeft.setFaceTexture(Face::Up, "assets/textures/plan/p17.jpg", 0, 1,1);
	adadaLeft.setFaceTexture(Face::Down, "assets/textures/plan/p17.jpg", 0, 0);
	adadaLeft.setFaceTexture(Face::Left, "assets/textures/plan/p17.jpg", 0, 0);
	adadaLeft.setFaceTexture(Face::Right, "assets/textures/plan/p17.jpg", 0,1, 1);
	adadaLeft.setFaceTexture(Face::Back, "assets/textures/plan/p17.jpg", 0, 0);
	adadaLeft.setFaceTexture(Face::Front, "assets/textures/plan/p17.jpg", 0, 0);

	adadaRight.setFaceTexture(Face::Up, "assets/textures/plan/p9.jpg", 0, 1,1);
	adadaRight.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 0, 0);
	adadaRight.setFaceTexture(Face::Left, "assets/textures/plan/p9.jpg", 0, 0);
	adadaRight.setFaceTexture(Face::Right, "assets/textures/plan/p10.jpg", 0, 0);
	adadaRight.setFaceTexture(Face::Back, "assets/textures/plan/p9.jpg", 0, 0);
	adadaRight.setFaceTexture(Face::Front, "assets/textures/plan/p9.jpg", 0, 0);


	mosaad1.setFaceTexture(Face::Up, "assets/textures/mall/mossad1.png", 1, 1, 1);
	mosaad1.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad1.setFaceTexture(Face::Left, "assets/textures/mall/mossad1.png", 0, 0);
	mosaad1.setFaceTexture(Face::Right, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad1.setFaceTexture(Face::Back, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad1.setFaceTexture(Face::Front, "assets/textures/plan/p9.jpg", 1, 0);
	
	mosaad2.setFaceTexture(Face::Up, "assets/textures/mall/mossad2.png", 1, 1, 1);
	mosaad2.setFaceTexture(Face::Down, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad2.setFaceTexture(Face::Left, "assets/textures/mall/mossad2.png", 0, 0);
	mosaad2.setFaceTexture(Face::Right, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad2.setFaceTexture(Face::Back, "assets/textures/plan/p9.jpg", 1, 0);
	mosaad2.setFaceTexture(Face::Front, "assets/textures/plan/p9.jpg", 1, 0);


	adadaMiddile.setSideTexture("assets/textures/plan/p9.jpg");
	adadaMiddile.setBottomTexture("assets/textures/plan/p9.jpg");
	adadaMiddile.setTopTexture("assets/textures/plan/p9.jpg");

	floor_1.setFaceTexture(Face::Up, "assets/textures/plan/p10.jpg", 0, 0);
	floor_1.setFaceTexture(Face::Down, "assets/textures/plan/p11.jpg", 0, 0);
	floor_1.setFaceTexture(Face::Left, "assets/textures/plan/p11.jpg", 0,1, 1);
	floor_1.setFaceTexture(Face::Right, "assets/textures/plan/p11.jpg",0, 1, 1);
	floor_1.setFaceTexture(Face::Back, "assets/textures/plan/p11.jpg", 0,1, 1);
	floor_1.setFaceTexture(Face::Front, "assets/textures/plan/p11.jpg", 0,1, 1);

	mmr.setFaceTexture(Face::Up, "assets/textures/plan/p10.jpg", 0, 0);
	mmr.setFaceTexture(Face::Down, "assets/textures/plan/p11.jpg", 0, 0);
	mmr.setFaceTexture(Face::Left, "assets/textures/plan/p11.jpg", 0,1, 1);
	mmr.setFaceTexture(Face::Right, "assets/textures/plan/p11.jpg",0, 1, 1);
	mmr.setFaceTexture(Face::Back, "assets/textures/plan/p11.jpg", 0,1, 1);
	mmr.setFaceTexture(Face::Front, "assets/textures/plan/p11.jpg", 0,1, 1);

	mmrCenter.setFaceTexture(Face::Up, "assets/textures/plan/p10.jpg", 0, 0);
	mmrCenter.setFaceTexture(Face::Down, "assets/textures/plan/p11.jpg", 0, 0);
	mmrCenter.setFaceTexture(Face::Left, "assets/textures/plan/p11.jpg", 0,1, 1);
	mmrCenter.setFaceTexture(Face::Right, "assets/textures/plan/p11.jpg",0, 1, 1);
	mmrCenter.setFaceTexture(Face::Back, "assets/textures/plan/p11.jpg", 0,1, 1);
	mmrCenter.setFaceTexture(Face::Front, "assets/textures/plan/p11.jpg", 0,1, 1);

	market1.setFaceTexture(Face::Right, "assets/textures/mall/m1.jpg", 0, 0);
	market1.setFaceTexture(Face::Left, "assets/textures/mall/m2.jpg", 0, 0);


}
	// ? NOTES :
	// ! 1- Dont forget to use public when inheriting from Object class" class Class : public Object".
	// ! 2- Dont forget to setParentModel(getModel()) for all of the class children
	// ! 3- if the object have a transparent Texture , call obj.getTransparent in getTransparent Method
	// ! 4- dont forget to updateModelMatrix inside each draw call to see the result 
	// !	    when dealing with Imgui  (not Necessary if not using it i guess).
	// ! 5- Cylinder Class does not work with transparent texture for now ,maybe in the future.
	// 
	// ? How to draw:
	// ! declare the object in header file 
	// ! ModelObject model , Box box , Cylinder cylinder
	// ? For transparent objects :
	// ! there is an issue when drawing the same object in multiple places , like in chair class we created
	// 	 ! for now just do objects as the number of the positions  "Like in Chair class , check rjls vector".
	//  ? JUST FOR TRANSPARENT , Opaque work fine with it.
	// 
	// 
	// 
	// ? For Models : " The class could have some errors , it is not final"
	// !	in the constructor pass the model path , default vertex and fragment shader 
	// ! ModelObject inherits Object class , you can deal with all its methods (setPosition , rotation...)
	// ! To Draw the model , call drawOpaque , no Transparent for now ( maybe in the future)
	// ! NOTE : if the texture is not right , go to the texture and flip it vertically.
	// ? For Box :
	// 	   ! pass the width , height , depth , vertex and fragment shader
	// 	   ! dont forget to call getTrasnparent if it does have transparent faces.
	// ? For Cylinder :
	// 	   ! pass the upper and lower radius  , segmentCounts , vertex and fragment shaders
	// 	   ! the Segment count is the resolution of the circle , higher is smoother
	// 	   ! when using a small number like 4 or 5 , you got a regular shape with the segments you passed
	// 	   TODO Just try it yourself
	// ?Model Example:
		///className (parameters) :
		/// model("assets/objects/w_knife.mdl", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
		// !In Consturctor :
		///  "optoinal translations"
		// !in drawOpaque:
		/// model.setParentModel(getModel());
		/// model.setPoistion(...);
		/// .
		/// .
		/// model.drawOpaque();

	// ?NOTE : 
	// !you can see box and cylinder examples in ResturantRoom class.	


	// ?ImGui : 
	// ! soon...

