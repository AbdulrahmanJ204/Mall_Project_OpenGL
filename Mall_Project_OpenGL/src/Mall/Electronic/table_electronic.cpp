#include "table_electronic.h"

TableElectronic::TableElectronic():Object(),
plan(2.4f,0.05f,1.6f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
hwafe(0.8f,0.8f,0.05f,300,"assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
rgle(0.05f,0.05f,1.0f,300,"assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
mobile(ModelObject("assets/mobile-obj/mobile.obj", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"))
{
	mobile=(ModelObject("assets/mobile-obj/mobile.obj", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"));
	plan.setFaceTexture(Face::Up, "assets/textures/electronic/t1.jpg");
	plan.setFaceTexture(Face::Down, "assets/textures/electronic/t1.jpg");
	plan.setFaceTexture(Face::Left, "assets/textures/electronic/t1.jpg");
	plan.setFaceTexture(Face::Right, "assets/textures/electronic/t1.jpg");
	plan.setFaceTexture(Face::Back, "assets/textures/electronic/t2.jpg");
	plan.setFaceTexture(Face::Front, "assets/textures/electronic/t2.jpg");
	hwafe.setBottomTexture("assets/textures/electronic/t1.jpg");
	hwafe.setTopTexture("assets/textures/electronic/t1.jpg");
	hwafe.setSideTexture("assets/textures/electronic/t2.jpg");
	rgle.setBottomTexture("assets/textures/electronic/t1.jpg");
	rgle.setTopTexture("assets/textures/electronic/t1.jpg");
	rgle.setSideTexture("assets/textures/electronic/t2.jpg");

	glm::vec3 mobilseScale=glm::vec3(3.0f, 0.0f, 1.0f);
	mobile.setScale(mobilseScale);
}

void TableElectronic::drawOpaque()
{
	plan.setParentModel(getModel());
	rgle.setParentModel(getModel());
	hwafe.setParentModel(getModel());
	plan.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	plan.drawOpaque();
	mobile.setPosition(glm::vec3(0.0f, 1.0f, 0.0f));
	
	//mobile.draw();
	rgle.setPosition(glm::vec3(-1.0f, -0.5f, 0.0f));
	rgle.drawOpaque();
	rgle.setPosition(glm::vec3(+1.0f, -0.5f, 0.0f));
	rgle.drawOpaque();
	hwafe.setPosition(glm::vec3(1.2f, -0.0001f, 0.0f));
	hwafe.drawOpaque();
	hwafe.setPosition(glm::vec3(-1.2f, -0.0001f, 0.0f));
	hwafe.drawOpaque();
}

void TableElectronic::drawTransparent()
{
}

void TableElectronic::onImguiRender()
{
	ImGui::SliderFloat3("TableElectronic Position ", &m_Position.x, -200.0f, 200.0f);
}
