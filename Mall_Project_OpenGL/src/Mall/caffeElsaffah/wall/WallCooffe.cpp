#include "caffeElsaffah/coffeeWall/WallCooffe.h"

WallCooffe::WallCooffe() :Object(),
sykh(0.05f,0.05f,8.0f,300, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
underSykh(0.1,3.2 ,5 , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void WallCooffe::drawOpaque()
{
	glm::vec3 positions[96] = {
	glm::vec3(19.7f , 4 ,0.2f ),
	glm::vec3(19.7f , 4 ,0.4f),
	glm::vec3(19.7f , 4 ,0.6f),
	glm::vec3(19.7f , 4 ,0.8f),
	glm::vec3(19.7f , 4 ,1.0f),
	glm::vec3(19.7f , 4 ,1.2f),
	glm::vec3(19.7f , 4 ,1.4f),
	glm::vec3(19.7f , 4 ,1.6f),
	glm::vec3(19.7f , 4 ,1.8f),
	glm::vec3(19.7f , 4 ,2.0f),
	glm::vec3(19.7f , 4 ,2.2f),
	glm::vec3(19.7f , 4 ,2.4f),
	glm::vec3(19.7f , 4 ,2.6f),
	glm::vec3(19.7f , 4 ,2.8f),
	glm::vec3(19.7f , 4 ,3.0f),
	glm::vec3(19.7f , 4 ,3.2f),
	glm::vec3(19.7f , 4 ,3.4f),
	glm::vec3(19.7f , 4 ,3.6f),
	glm::vec3(19.7f , 4 ,3.8f),
	glm::vec3(19.7f , 4 ,4.0f),
	glm::vec3(19.7f , 4 ,4.2f),
	glm::vec3(19.7f , 4 ,4.4f),
	glm::vec3(19.7f , 4 ,4.6f),
	glm::vec3(19.7f , 4 ,4.8f),
	glm::vec3(10 , 4 ,0.2f),
	glm::vec3(10 , 4 ,0.4f),
	glm::vec3(10 , 4 ,0.6f),
	glm::vec3(10 , 4 ,0.8f),
	glm::vec3(10 , 4 ,1.0f),
	glm::vec3(10 , 4 ,1.2f),
	glm::vec3(10 , 4 ,1.4f),
	glm::vec3(10 , 4 ,1.6f),
	glm::vec3(10 , 4 ,1.8f),
	glm::vec3(10 , 4 ,2.0f),
	glm::vec3(10 , 4 ,2.2f),
	glm::vec3(10 , 4 ,2.4f),
	glm::vec3(10 , 4 ,2.6f),
	glm::vec3(10 , 4 ,2.8f),
	glm::vec3(10 , 4 ,3.0f),
	glm::vec3(10 , 4 ,3.2f),
	glm::vec3(10 , 4 ,3.4f),
	glm::vec3(10 , 4 ,3.6f),
	glm::vec3(10 , 4 ,3.8f),
	glm::vec3(10 , 4 ,4.0f),
	glm::vec3(10 , 4 ,4.2f),
	glm::vec3(10 , 4 ,4.4f),
	glm::vec3(10 , 4 ,4.6f),
	glm::vec3(10 , 4 ,4.8f),
	glm::vec3(19.7f , 4 ,49.8),
	glm::vec3(19.7f , 4 ,49.6),
	glm::vec3(19.7f , 4 ,49.4),
	glm::vec3(19.7f , 4 ,49.2),
	glm::vec3(19.7f , 4 ,49.0),
	glm::vec3(19.7f , 4 ,48.8),
	glm::vec3(19.7f , 4 ,48.6),
	glm::vec3(19.7f , 4 ,48.4),
	glm::vec3(19.7f , 4 ,48.2),
	glm::vec3(19.7f , 4 ,48.0),
	glm::vec3(19.7f , 4 ,47.8),
	glm::vec3(19.7f , 4 ,47.6),
	glm::vec3(19.7f , 4 ,47.4),
	glm::vec3(19.7f , 4 ,47.2),
	glm::vec3(19.7f , 4 ,47.0),
	glm::vec3(19.7f , 4 ,46.8),
	glm::vec3(19.7f , 4 ,46.6),
	glm::vec3(19.7f , 4 ,46.4),
	glm::vec3(19.7f , 4 ,46.2),
	glm::vec3(19.7f , 4 ,46.0),
	glm::vec3(19.7f , 4 ,45.8),
	glm::vec3(19.7f , 4 ,45.6),
	glm::vec3(19.7f , 4 ,45.4),
	glm::vec3(19.7f , 4 ,45.2),
	glm::vec3(10 , 4 ,49.8),
	glm::vec3(10 , 4 ,49.6),
	glm::vec3(10 , 4 ,49.4),
	glm::vec3(10 , 4 ,49.2),
	glm::vec3(10 , 4 ,49.0),
	glm::vec3(10 , 4 ,48.8),
	glm::vec3(10 , 4 ,48.6),
	glm::vec3(10 , 4 ,48.4),
	glm::vec3(10 , 4 ,48.2),
	glm::vec3(10 , 4 ,48.0),
	glm::vec3(10 , 4 ,47.8),
	glm::vec3(10 , 4 ,47.6),
	glm::vec3(10 , 4 ,47.4),
	glm::vec3(10 , 4 ,47.2),
	glm::vec3(10 , 4 ,47.0),
	glm::vec3(10 , 4 ,46.8),
	glm::vec3(10 , 4 ,46.6),
	glm::vec3(10 , 4 ,46.4),
	glm::vec3(10 , 4 ,46.2),
	glm::vec3(10 , 4 ,46.0),
	glm::vec3(10 , 4 ,45.8),
	glm::vec3(10 , 4 ,45.6),
	glm::vec3(10 , 4 ,45.4),
	glm::vec3(10 , 4 ,45.2),

	};
	for (int i = 0; i < 96; i++) {
		sykh.setParentModel(getModel());
		sykh.setPosition(positions[i]);
		sykh.drawOpaque();
	}
	underSykh.setParentModel(getModel());
	underSykh.setPosition(glm::vec3(19.7, 1.7f, 2.5));
	underSykh.drawOpaque();
	underSykh.setParentModel(getModel());
	underSykh.setPosition(glm::vec3(10, 1.7f, 2.5));
	underSykh.drawOpaque();
	underSykh.setParentModel(getModel());
	underSykh.setPosition(glm::vec3(19.7, 1.7f, 47.35));
	underSykh.drawOpaque();
	underSykh.setParentModel(getModel());
	underSykh.setPosition(glm::vec3(10, 1.7f, 47.35));
	underSykh.drawOpaque();


	


}

void WallCooffe::getTransparent()
{
}

void WallCooffe::onImguiRender()
{
	ImGui::SliderFloat3("WallCooffe Position ", &m_Position.x, -200.0f, 200.0f);
}

void WallCooffe::setTex()
{
	sykh.setBottomTexture("assets/textures/brickWallCooffe.jpg");
	sykh.setSideTexture("assets/textures/container2.png");
	sykh.setTopTexture("assets/textures/container.jpg");

	underSykh.setFaceTexture(Face::Down, "assets/textures/electronic/t6.jpg");
	underSykh.setFaceTexture(Face::Up, "assets/textures/electronic/t6.jpg");
	underSykh.setFaceTexture(Face::Left, "assets/textures/electronic/t6.jpg");
	underSykh.setFaceTexture(Face::Right, "assets/textures/electronic/t6.jpg");
	underSykh.setFaceTexture(Face::Back, "assets/textures/electronic/t6.jpg");
	underSykh.setFaceTexture(Face::Front, "assets/textures/electronic/t6.jpg");


	
}
