#include "caffeElsaffah/kanabe/kanabeh.h"
Kanabeh::Kanabeh() :Object(),
seat(1.8f, 1.75f, 5.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
snnada(0.9f, 3.6f, 5.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}
void Kanabeh::drawOpaque()
{
	// first chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(26.5f, 1.0f, 2.5));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(21.5f, 1.0f, 2.5));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(27.85f, 1.8f, 2.5));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(20.35f, 1.8f, 2.5));
	snnada.drawOpaque();
	//second chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(17.65, 1.0f, 2.5));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(12, 1.0f, 2.5));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(19, 1.8f, 2.5));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(10.7, 1.8f, 2.5));
	snnada.drawOpaque();
	//third chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(8, 1.0f, 2.5));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(2.35f, 1.0f, 2.5));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(9.35f, 1.8f, 2.5));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(1.05f, 1.8f, 2.5));
	snnada.drawOpaque();
	//first chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(26.5f, 1.0f, 47.35));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(21.5f, 1.0f, 47.35));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(27.85, 1.8f, 47.35));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(20.35f, 1.8f, 47.35));
	snnada.drawOpaque();
	//second chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(17.65, 1.0f, 47.35));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(12, 1.0f, 47.35));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(19, 1.8f, 47.35));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(10.7, 1.8f, 47.35));
	snnada.drawOpaque();
	// third chair:
	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(8, 1.0f, 47.35));
	seat.drawOpaque();

	seat.setParentModel(getModel());
	seat.setPosition(glm::vec3(2.35f, 1.0f, 47.35));
	seat.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(9.35f, 1.8f, 47.35));
	snnada.drawOpaque();

	snnada.setParentModel(getModel());
	snnada.setPosition(glm::vec3(1.05f, 1.8f, 47.35));
	snnada.drawOpaque();
  
}

void Kanabeh::getTransparent()
{
	

}

void Kanabeh::onImguiRender()
{
	ImGui::SliderFloat3(" kanabeition ", &m_Position.x, -200.0f, 200.0f);
}
void Kanabeh::setTex() {
	seat.setFaceTexture(Face::Down, "assets/textures/coffee/fabric_199-1K/blue.png");
	seat.setFaceTexture(Face::Up, "assets/textures/coffee/fabric_199-1K/blue.png");
	seat.setFaceTexture(Face::Left, "assets/textures/coffee/fabric_199-1K/blue.png");
	seat.setFaceTexture(Face::Right, "assets/textures/coffee/fabric_199-1K/blue.png");
	seat.setFaceTexture(Face::Back, "assets/textures/coffee/fabric_199-1K/blue.png");
	seat.setFaceTexture(Face::Front, "assets/textures/coffee/fabric_199-1K/blue.png");

	snnada.setFaceTexture(Face::Down, "assets/textures/electronic/t4.jpg");
	snnada.setFaceTexture(Face::Up, "assets/textures/electronic/t4.jpg");
	snnada.setFaceTexture(Face::Left,"assets/textures/electronic/t4.jpg");
	snnada.setFaceTexture(Face::Right, "assets/textures/electronic/t4.jpg");
	snnada.setFaceTexture(Face::Back, "assets/textures/electronic/t4.jpg");
	snnada.setFaceTexture(Face::Front, "assets/textures/electronic/t4.jpg");
}


