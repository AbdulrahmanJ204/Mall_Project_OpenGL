#include "caffeElsaffah\coffeTable\\Tables.h"

Tables::Tables():Object(),
trs(1.8f, 0.07f, 5.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
footTable(0.2f, 0.2f, 2.5f,300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
trs2(1.8f, 0.07f, 5.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Tables::drawOpaque()
{
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(24, 2.42f, 2.5));
	/*trs.setPosition(glm::vec3(24, 2.42f, 15));*/
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(24, 1.15f, 2.5));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(15.15, 2.42f, 2.5));
	trs.drawOpaque();
	footTable.setPosition(glm::vec3(15.15, 1.15f, 2.5));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(5.5, 2.42f, 2.5));
	trs.drawOpaque();
	footTable.setPosition(glm::vec3(5.5, 1.15f, 2.5));
	footTable.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(24, 1.15f, 47));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(24, 2.42f, 47));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(15.15, 1.15f, 47));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(15.15, 2.42f, 47));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(5.5, 1.15f, 47));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(5.5, 2.42f, 47));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(19.7, 1.15f, 32));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(19.7, 2.42f, 32));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(19.7, 1.15f, 37.1));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(19.7, 2.42f, 37.1));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(10, 1.15f, 32));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(10, 2.42f, 32));
	trs.drawOpaque();
	footTable.setParentModel(getModel());
	footTable.setPosition(glm::vec3(10, 1.15f, 37.1));
	footTable.drawOpaque();
	trs.setParentModel(getModel());
	trs.setPosition(glm::vec3(10, 2.42f, 37.1));
	trs.drawOpaque();

	

}

void Tables::getTransparent()
{
}

void Tables::onImguiRender()
{
	//ImGui::SliderFloat3("table Position ", &m_Position.x, -200.0f, 200.0f);
}

void Tables::setTex()
{
	trs.setFaceTexture(Face::Down, "assets/textures/electronic/t5.jpg");
	trs.setFaceTexture(Face::Up, "assets/textures/electronic/t5.jpg");
	trs.setFaceTexture(Face::Left, "assets/textures/electronic/t5.jpg");
	trs.setFaceTexture(Face::Right, "assets/textures/electronic/t5.jpg");
	trs.setFaceTexture(Face::Back, "assets/textures/electronic/t5.jpg");
	trs.setFaceTexture(Face::Front, "assets/textures/electronic/t5.jpg");

	footTable.setBottomTexture("assets/textures/brickwall.jpg");
	footTable.setSideTexture("assets/textures/container2.png");
	footTable.setTopTexture("assets/textures/container.jpg");

	trs2.setFaceTexture(Face::Down, "assets/textures/electronic/t9.jpg");
	trs2.setFaceTexture(Face::Up, "assets/textures/electronic/t9.jpg");
	trs2.setFaceTexture(Face::Left, "assets/textures/electronic/t9.jpg");
	trs2.setFaceTexture(Face::Right, "assets/textures/electronic/t9.jpg");
	trs2.setFaceTexture(Face::Back, "assets/textures/electronic/t9.jpg");
	trs2.setFaceTexture(Face::Front, "assets/textures/electronic/t9.jpg");
}



