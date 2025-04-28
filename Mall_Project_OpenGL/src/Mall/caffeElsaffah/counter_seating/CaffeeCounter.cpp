#include "caffeElsaffah\Counter_seating\CaffeeCounter.h"

CaffeeCounter::CaffeeCounter() :Object(),
 firstBase(12, 0.5f, 2, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
secondBase(2.0f, 0.5f, 12, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
thirdBase(5.5, 0.5f, 2, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
firstBlock(10, 1.4, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
secondBlock(1,1.4, 11, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
thirdBlock(6.5, 1.4, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
firstRaff(12,0.1,2, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
secondRaff(2, 0.1, 15, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
thirdRaff(6, 0.1, 2, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
firstRoof(10, 3, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
secondRoof(1, 3, 11, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
thirdRoof(6.5, 3, 1, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
aboveCounter(15, 0.2, 14, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
caffeeMachine("assetfree_tos/obj/generic_soda_dispenser_gltf/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag")

{
	setTex();
}

void CaffeeCounter::drawOpaque()
{
	
	firstBase.setParentModel(getModel());
	firstBase.setPosition(glm::vec3(6, 0.4, 12.5));
	firstBase.drawOpaque();
	secondBase.setParentModel(getModel());
	secondBase.setPosition(glm::vec3(11,0.4,19.5));
	secondBase.drawOpaque();
	thirdBase.setParentModel(getModel());
	thirdBase.setPosition(glm::vec3(7.25f,0.4f,24.5f));
	thirdBase.drawOpaque();
	firstBlock.setParentModel(getModel());
	firstBlock.setPosition(glm::vec3(5, 1.4f, 13));
	firstBlock.drawOpaque();
	secondBlock.setParentModel(getModel());
	secondBlock.setPosition(glm::vec3(10.5, 1.4f, 18));
	secondBlock.drawOpaque();
	thirdBlock.setParentModel(getModel());
	thirdBlock.setPosition(glm::vec3(7.75, 1.4f, 24));
	thirdBlock.drawOpaque();
	firstRaff.setParentModel(getModel());
	firstRaff.setPosition(glm::vec3(6, 2.15f, 12));
	firstRaff.drawOpaque();
	secondRaff.setParentModel(getModel());
	secondRaff.setPosition(glm::vec3(11.5, 2.15f, 18.5));
	secondRaff.drawOpaque();
	thirdRaff.setParentModel(getModel());
	thirdRaff.setPosition(glm::vec3(7.5, 2.15f, 25));
	thirdRaff.drawOpaque();
	firstRoof.setParentModel(getModel());
	firstRoof.setPosition(glm::vec3(5, 7.4f, 13));
	firstRoof.drawOpaque();
	secondRoof.setParentModel(getModel());
	secondRoof.setPosition(glm::vec3(10.4, 7.4f, 18));
	secondRoof.drawOpaque();
	firstRoof.setParentModel(getModel());
	firstRoof.setPosition(glm::vec3(5, 7.4f, 23));
	firstRoof.drawOpaque();
	aboveCounter.setParentModel(getModel());
	aboveCounter.setPosition(glm::vec3(7.5, 9, 18));
	aboveCounter.drawOpaque();
	caffeeMachine.setParentModel(getModel());
	caffeeMachine.setPosition(m_Position);
	caffeeMachine.drawOpaque();

}

void CaffeeCounter::getTransparent()
{
}

void CaffeeCounter::onImguiRender()
{
	ImGui::SliderFloat3("CaffeeCounter Position ", &m_Position.x, -200.0f, 200.0f);

}

void CaffeeCounter::setTex()
{
	firstBase.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	firstBase.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	firstBase.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	firstBase.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	firstBase.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	firstBase.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	secondBase.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	secondBase.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	secondBase.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	secondBase.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	secondBase.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	secondBase.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	thirdBase.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	thirdBase.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	thirdBase.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	thirdBase.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	thirdBase.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	thirdBase.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	firstBlock.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstBlock.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstBlock.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstBlock.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstBlock.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstBlock.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_194-1K/counter.png");

	secondBlock.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondBlock.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondBlock.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondBlock.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondBlock.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondBlock.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_194-1K/counter.png");

	thirdBlock.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_194-1K/counter.png");
	thirdBlock.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_194-1K/counter.png");
	thirdBlock.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_194-1K/counter.png");
	thirdBlock.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_194-1K/counter.png");
	thirdBlock.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_194-1K/counter.png");
	thirdBlock.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_194-1K/counter.png");


	firstRaff.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	firstRaff.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	firstRaff.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	firstRaff.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	firstRaff.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	firstRaff.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	secondRaff.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	secondRaff.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	secondRaff.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	secondRaff.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	secondRaff.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	secondRaff.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	thirdRaff.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	thirdRaff.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	thirdRaff.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	thirdRaff.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	thirdRaff.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	thirdRaff.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

	firstRoof.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstRoof.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstRoof.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstRoof.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstRoof.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_194-1K/counter.png");
	firstRoof.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_194-1K/counter.png");

	secondRoof.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondRoof.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondRoof.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondRoof.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondRoof.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_194-1K/counter.png");
	secondRoof.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_194-1K/counter.png");


	aboveCounter.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	aboveCounter.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	aboveCounter.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	aboveCounter.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	aboveCounter.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	aboveCounter.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");

}

