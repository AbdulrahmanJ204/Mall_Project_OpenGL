#include "CaffeeRoom.h"

CaffeeRoom::CaffeeRoom():Object(),
floor(30.0f,0.25f,50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
sakef(30.0f, 0.25f, 50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
firstSideWall(30.0f,16.0,0.25f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
secondSideWall(0.25f,16.0f,50.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
aboveTable(29.5f,0.25f,4.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
tv(5.0f, 3, 0.02f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, }),
model("assets/obj/wizard_cat_gltf/scene.gltf","assets/shaders/model_loading.vert","assets/shaders/model_loading.frag"),
front1(5, 16.0, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
front2(10, 4, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
front3(10, 8, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
front4(3, 12, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
front5(17, 16, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
front7(10, 8, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
lamp("assets/obj/tree_lamp_gltf/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chair("assets/obj/leather_high_bar_stool/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chairTable("assets/obj/chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chairTable2("assets/obj/chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chairTable3("assets/obj/chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chairTable4("assets/obj/chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
coffeeMachine("assets/obj/stylized_vintage_coffee_machine/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
candles("assets/obj/candle_holder/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
vending("assets/obj/noryangjin_vending_machine/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
banda("assets/obj/free_toon_panda_character_detective_gltf/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag")

//assets / obj / medieval_stool / scene.gltf is ok but not the best


{
	setTex();
	floor.setPosition(glm::vec3(15.0f,0.0f, 25.0f));
	
	secondSideWall.setPosition(glm::vec3(0.0f, 8.0f, 25.0f));
	
	

}

void CaffeeRoom::drawOpaque() {

	glm::vec3 positions[2] = {
	glm::vec3(15.0f , 8.0f , 50.0f),
	glm::vec3(15.0f , 8.0, 0.0), };
	


	for (int i = 0; i < 2; i++) {
		firstSideWall.setParentModel(getModel());
		firstSideWall.setPosition(positions[i]);
		firstSideWall.drawOpaque();
	}
	
	floor.setParentModel(getModel());
	floor.drawOpaque();
	sakef.setParentModel(getModel());
	sakef.setPosition(glm::vec3(15.0f, 16.0f, 25.0f));
	sakef.drawOpaque();
	secondSideWall.setParentModel(getModel());
	secondSideWall.drawOpaque();
	/*sideWall.setParentModel(getModel());
	sideWall.setRotation(90, glm::vec3(0.0f,0.0f,1.0f ));
	sideWall.drawOpaque();*/
	kanabe.setParentModel(getModel());
	kanabe.drawOpaque();
	tables.setParentModel(getModel());
	tables.drawOpaque();
	wall.setParentModel(getModel());
	wall.drawOpaque();
	aboveTable.setParentModel(getModel());
	aboveTable.setPosition(glm::vec3(15.0f, 8.1f, 2.6f));
	aboveTable.drawOpaque();
	aboveTable.setParentModel(getModel());
	aboveTable.setPosition(glm::vec3(15.0f, 8.1f, 47.4f));
	aboveTable.drawOpaque();
	counter.setParentModel(getModel());
	counter.drawOpaque();
	model.setParentModel(getModel());
	model.setRotation(.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	model.setScale(glm::vec3(0.03f));
	model.setPosition(glm::vec3(26, 0.2f, 14));
	model.drawOpaque();
	 tv.setParentModel(getModel());
	tv.setPosition(glm::vec3(0.2f, 9.0f, 34));
	tv.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	tv.drawOpaque();
	front1.setParentModel(getModel());
	front1.setPosition(glm::vec3(30.0f, 8.0f, 2.6f));
	front1.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front1.drawOpaque();
	front1.setParentModel(getModel());
	front1.setPosition(glm::vec3(30.0f, 8.0f, 47.4f));
	front1.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front1.drawOpaque();
	front2.setParentModel(getModel());
	front2.setPosition(glm::vec3(30 ,14, 10));
	front2.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front2.drawOpaque();
	front3.setParentModel(getModel());
	front3.setPosition(glm::vec3(30, 4, 10));
	front3.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	//front3.drawOpaque();
	front4.setParentModel(getModel());
	front4.setPosition(glm::vec3(30, 10, 16.5));
	front4.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front4.drawOpaque();
	front2.setPosition(glm::vec3(30, 14, 40));
	front2.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front2.drawOpaque();
	front7.setParentModel(getModel());
	front7.setPosition(glm::vec3(30, 4, 40));
	front7.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	//front7.drawOpaque();
	front5.setParentModel(getModel());
	front5.setPosition(glm::vec3(30, 8, 26.5));
	front5.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
	front5.drawOpaque();
	lamp.setParentModel(getModel());
	lamp.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	lamp.setScale(glm::vec3(0.5));
	lamp.setPosition(glm::vec3(1.4, 2.5, 12));
	lamp.drawOpaque();
	chair.setParentModel(getModel());
	chair.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chair.setScale(glm::vec3(0.8f));
	chair.setPosition(glm::vec3(6.0f, 0.1f, 10.0f));
	chair.drawOpaque();
	chair.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chair.setScale(glm::vec3(0.8f));
	chair.setPosition(glm::vec3(3.0f, 0.1f, 10.0f));
	chair.drawOpaque();
	chair.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chair.setScale(glm::vec3(0.8f));
	chair.setPosition(glm::vec3(9.0f, 0.1f, 10.0f));
	chair.drawOpaque();
	chair.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chair.setScale(glm::vec3(0.8f));
	chair.setPosition(glm::vec3(12.0f, 0.1f, 10.0f));
	chair.drawOpaque();
	chairTable.setParentModel(getModel());
	//chairTable.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chairTable.setScale(glm::vec3(0.8f));
	chairTable.setPosition(glm::vec3(20.5, 1.5f, 29.7f));
	chairTable.drawOpaque();
	chairTable.setParentModel(getModel());
	//chairTable.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	chairTable.setScale(glm::vec3(0.8f));
	chairTable.setPosition(glm::vec3(10.7, 1.5f, 29.7f));
	chairTable.drawOpaque();
	chairTable2.setParentModel(getModel());
	chairTable2.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable2.setScale(glm::vec3(0.8f));
	chairTable2.setPosition(glm::vec3(11.5, 1.5f, 33));
	chairTable2.drawOpaque();
	chairTable2.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable2.setScale(glm::vec3(0.8f));
	chairTable2.setPosition(glm::vec3(11.5, 1.5f, 38));
	chairTable2.drawOpaque();
	chairTable2.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable2.setScale(glm::vec3(0.8f));
	chairTable2.setPosition(glm::vec3(20.8, 1.5f, 33));
	chairTable2.drawOpaque();
	chairTable2.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable2.setScale(glm::vec3(0.8f));
	chairTable2.setPosition(glm::vec3(20.8, 1.5f, 38));
	chairTable2.drawOpaque();
	chairTable3.setParentModel(getModel());
	chairTable3.setRotation(-180, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable3.setScale(glm::vec3(0.8f));
	chairTable3.setPosition(glm::vec3(18.8, 1.5f, 39.5));
	chairTable3.drawOpaque();
	chairTable3.setRotation(-180, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable3.setScale(glm::vec3(0.8f));
	chairTable3.setPosition(glm::vec3(9.2, 1.5f, 39.5));
	chairTable3.drawOpaque();
	chairTable4.setParentModel(getModel());
	chairTable4.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable4.setScale(glm::vec3(0.8f));
	chairTable4.setPosition(glm::vec3(8.8, 1.5f, 31.5));
	chairTable4.drawOpaque();
	chairTable4.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable4.setScale(glm::vec3(0.8f));
	chairTable4.setPosition(glm::vec3(8.8, 1.5f, 36.6));
	chairTable4.drawOpaque();
	chairTable4.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable4.setScale(glm::vec3(0.8f));
	chairTable4.setPosition(glm::vec3(18.3, 1.5f, 31.5));
	chairTable4.drawOpaque();
	chairTable4.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	chairTable4.setScale(glm::vec3(0.8f));
	chairTable4.setPosition(glm::vec3(18.3, 1.5f, 36.6));
	chairTable4.drawOpaque();
	//coffee machine:
	coffeeMachine.setParentModel(getModel());
	coffeeMachine.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	coffeeMachine.setScale(glm::vec3(0.07f,0.05f,0.05f));
	coffeeMachine.setPosition(glm::vec3(7.5f, 2.2f, 25.0f));
	coffeeMachine.drawOpaque();
	//coffee machine:
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(24.0f, 3.05f, 2.5f));
	candles.drawOpaque();
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(15.25f, 3.05f, 2.5f));
	candles.drawOpaque();
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(5.5f, 3.05f, 2.5f));
	candles.drawOpaque();
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(24.0f, 3.05f, 47.0f));
	candles.drawOpaque();
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(15.25f, 3.05f, 47.0f));
	candles.drawOpaque();
	candles.setParentModel(getModel());
	candles.setRotation(90, glm::vec3(1.5f, 0.0f, 0.0f));
	candles.setScale(glm::vec3(0.005f));
	candles.setPosition(glm::vec3(5.5f, 3.05f, 47.0f));
	candles.drawOpaque();
	vending.setParentModel(getModel());
	//vending.setRotation(-270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	vending.setScale(glm::vec3(0.5f, 2.5f, 1.5f));
	vending.setPosition(glm::vec3(0.7f, 2.7f, 29.0f));
	vending.drawOpaque();
	banda.setParentModel(getModel());
	banda.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
	banda.setScale(glm::vec3(0.02f));
	banda.setPosition(glm::vec3(14.5f, 9.2f, 18.0f));
	banda.drawOpaque();
}






void CaffeeRoom::getTransparent()
{
}

void CaffeeRoom::onImguiRender()
{
	//tables.onImguiRender(	
	 ImGui::SliderFloat3("Mall Position ", &m_Position.x, -200.0f, 200.0f);
	 sakef.onImguiRender();
		
	
}

void CaffeeRoom::setTex()
{
	floor.setFaceTexture(Face::Down, "assets/textures/coffee/plaster_24-1K/floor2.png");
	floor.setFaceTexture(Face::Up, "assets/textures/coffee/plaster_24-1K/floor2.png");
	floor.setFaceTexture(Face::Left, "assets/textures/coffee/grey_ceramic_16-1K/floor.png");
	floor.setFaceTexture(Face::Right, "assets/textures/coffee/grey_ceramic_16-1K/floor.png");
	floor.setFaceTexture(Face::Back, "assets/textures/coffee/grey_ceramic_16-1K/floor.png");
	floor.setFaceTexture(Face::Front, "assets/textures/coffee/grey_ceramic_16-1K/floor.png");

	sakef.setFaceTexture(Face::Down, "assets/textures/electronic/t7.jpg");
	sakef.setFaceTexture(Face::Up, "assets/textures/electronic/t7.jpg");
	sakef.setFaceTexture(Face::Left, "assets/textures/electronic/t7.jpg");
	sakef.setFaceTexture(Face::Right, "assets/textures/electronic/t7.jpg");
	sakef.setFaceTexture(Face::Back, "assets/textures/electronic/t7.jpg");
	sakef.setFaceTexture(Face::Front, "aassets/textures/electronic/t7.jpg");

	firstSideWall.setFaceTexture(Face::Down, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	firstSideWall.setFaceTexture(Face::Up, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	firstSideWall.setFaceTexture(Face::Left, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	firstSideWall.setFaceTexture(Face::Right, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	firstSideWall.setFaceTexture(Face::Back, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	firstSideWall.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");

	secondSideWall.setFaceTexture(Face::Down, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	secondSideWall.setFaceTexture(Face::Up, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	secondSideWall.setFaceTexture(Face::Left, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	secondSideWall.setFaceTexture(Face::Right, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	secondSideWall.setFaceTexture(Face::Back, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	secondSideWall.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	
	aboveTable.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	aboveTable.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	aboveTable.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	aboveTable.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	aboveTable.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	aboveTable.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	tv.setFaceTexture(Face::Down, "assets/textures/coffee/tv.jpg");
	tv.setFaceTexture(Face::Up, "assets/textures/coffee/tv.jpg");
	tv.setFaceTexture(Face::Left, "assets/textures/coffee/tv.jpg");
	tv.setFaceTexture(Face::Right, "assets/textures/coffee/tv.jpg");
	tv.setFaceTexture(Face::Back, "assets/textures/coffee/tv.jpg");
	tv.setFaceTexture(Face::Front, "assets/textures/coffee/tv.jpg");

	front1.setFaceTexture(Face::Down, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front1.setFaceTexture(Face::Up, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front1.setFaceTexture(Face::Left, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front1.setFaceTexture(Face::Right, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front1.setFaceTexture(Face::Back, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front1.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");

	front2.setFaceTexture(Face::Down, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front2.setFaceTexture(Face::Up, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front2.setFaceTexture(Face::Left, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front2.setFaceTexture(Face::Right, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front2.setFaceTexture(Face::Back, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front2.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");

	front3.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	front3.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	front3.setFaceTexture(Face::Left, "assets/textures/electronic/t6jpg");
	front3.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	front3.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	front3.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	
	front4.setFaceTexture(Face::Down, "assets/textures/electronic/t7.jpg");
	front4.setFaceTexture(Face::Up, "assets/textures/electronic/t7.jpg");
	front4.setFaceTexture(Face::Left, "assets/textures/electronic/t7.jpg");
	front4.setFaceTexture(Face::Right, "assets/textures/electronic/t7.jpg");
	front4.setFaceTexture(Face::Back, "assets/textures/electronic/t7.jpg");
	front4.setFaceTexture(Face::Front, "assets/textures/coffee/onDoor.jpg");

	front5.setFaceTexture(Face::Down, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front5.setFaceTexture(Face::Up, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front5.setFaceTexture(Face::Left, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front5.setFaceTexture(Face::Right, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front5.setFaceTexture(Face::Back, "assets/textures/coffee/woodparquet_99-1K/wall.png");
	front5.setFaceTexture(Face::Front, "assets/textures/coffee/meow.jpg");

	front7.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	front7.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	front7.setFaceTexture(Face::Left, "assets/textures/electronic/t6jpg");
	front7.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	front7.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	front7.setFaceTexture(Face::Front, "assets/textures/coffee/woodparquet_99-1K/wall.png");
}
