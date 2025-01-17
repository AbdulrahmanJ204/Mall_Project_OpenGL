#include "TestsRoom.h"


TestsRoom::TestsRoom() :
	//room(50.0f, 20.0f, 30.0f, "assets/shaders/lightShader.vert", "assets/shaders/lightShader.frag"),
	cylinder(3.0f, 3.0f, 5.0f, 6, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	door(glm::vec3(50.0f), 10.0f, 10.0f, 0.05f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" , 
		"assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
	//model("assets/objects/ak47/scene.gltf","assets/shaders/model_loading.vert","assets/shaders/model_loading.frag" ),
	//temp(2.0f, 6.0f, 2.0f, "assets/shaders/lightShader.vert", "assets/shaders/lightShader.frag", { {Face::Front,{3,2}} })

{

	setTex();
	upperLights= {
		PointLight(glm::vec3(1.0f , 20.0f , 1.0f), LightHelper::getLightColor(Color::DEFAULT), 600.0f)
	};
}

void TestsRoom::updateLights() {
	//updateLightsPositions(upperLights);
	//temp.setFaceLight(Face::Up, upperLights);
}
void TestsRoom::drawOpaque()
{
	updateModelMatrix();
	//temp.setParentModel(getModel());
	cylinder.setParentModel(getModel());
	//room.setParentModel(getModel());
	door.setParentModel(getModel());
	door.update();
	door.drawOpaque();
	updateLights();
	//model.drawOpaque();
	//temp.drawOpaque();
	//cylinder.drawOpaque();
	//room.drawOpaque();
}

void TestsRoom::getTransparent()
{
	//room.getTransparent();
	door.getTransparent();
	cylinder.getTransparent();
	//temp.getTransparent();
}

void TestsRoom::onImguiRender()
{
	ImGui::SliderFloat3("Resturant", &m_Position.x, -200, 200);
	//room.onImguiRender("Resturnant Room");
	//temp.onImguiRender();
	cylinder.onImguiRender();
}

void TestsRoom::setTex()
{
	const std::string prefix = "assets/textures/bare-wood1-bl/bare-wood1_";
	doorTexture doTexR = {

		{Face::Up,    "assets/textures/d1_3.png"},
		{Face::Down,  "assets/textures/d1_3.png"},
		{Face::Left,  "assets/textures/d1_3.png"},
		{Face::Right, "assets/textures/d1_3.png"},
		{Face::Back,  "assets/textures/d1_3.png"},
		{Face::Front, "assets/textures/d1_3.png"},
	};
	doorTexture doTexL = {

		{Face::Up,    "assets/textures/d1_2.png"},
		{Face::Down,  "assets/textures/d1_2.png"},
		{Face::Left,  "assets/textures/d1_2.png"},
		{Face::Right, "assets/textures/d1_2.png"},
		{Face::Back,  "assets/textures/d1_2.png"},
		{Face::Front, "assets/textures/d1_2.png"},
	};
	door.setLeftTexture(doTexL);
	door.setRightTexture(doTexR);
	//textureMap upperFace = {
	//	{TextureType::ALBEDO , prefix + "albedo.png"} ,
	//	{TextureType::AO , prefix + "ao.png"} ,
	//	{TextureType::NORMAL , prefix + "normal-ogl.png"} ,
	//	{TextureType::ROUGHNESS ,prefix + "roughness.png"} ,
	//	{TextureType::METALIC ,prefix + "metallic.png"} ,
	//};

	//room.setFaceTexture(Face::Up, upperFace);
	//room.setFaceTexture(Face::Down, upperFace);
	//room.setFaceTexture(Face::Left, upperFace);
	//room.setFaceTexture(Face::Right, upperFace);
	//room.setFaceTexture(Face::Back, upperFace);
	//room.setFaceTexture(Face::Front, upperFace);

	//temp.setFaceTexture(Face::Up, upperFace);
	//temp.setFaceTexture(Face::Down, upperFace);
	//temp.setFaceTexture(Face::Left, upperFace);
	//temp.setFaceTexture(Face::Right, upperFace);
	//temp.setFaceTexture(Face::Back, upperFace);
	//temp.setFaceTexture(Face::Front, upperFace);

	cylinder.setBottomTexture("assets/textures/brickwall.jpg");
	cylinder.setSideTexture("assets/textures/container2.png");
	cylinder.setTopTexture("assets/textures/container.jpg");
}
