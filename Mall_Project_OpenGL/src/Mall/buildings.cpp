#include "buildings.h"
#include "table_electronic.h"

Buildings::Buildings() :Object(),
build1(40.0f, 40.1f, 40.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
build2(30.0f, 50.1f, 30.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
build3(30.0f, 30.1f, 30.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{

	build1.setFaceTexture(Face::Up, "assets/textures/mall/b4.jpg");
	build1.setFaceTexture(Face::Down, "assets/textures/mall/b4.jpg");
	build1.setFaceTexture(Face::Left, "assets/textures/mall/b4.jpg");
	build1.setFaceTexture(Face::Right, "assets/textures/mall/b4.jpg");
	build1.setFaceTexture(Face::Back, "assets/textures/mall/b4.jpg");
	build1.setFaceTexture(Face::Front, "assets/textures/mall/b4.jpg");

	build2.setFaceTexture(Face::Up, "assets/textures/mall/b1.jpg");
	build2.setFaceTexture(Face::Down, "assets/textures/mall/b1.jpg");
	build2.setFaceTexture(Face::Left, "assets/textures/mall/b1.jpg");
	build2.setFaceTexture(Face::Right, "assets/textures/mall/b1.jpg");
	build2.setFaceTexture(Face::Back, "assets/textures/mall/b1.jpg");
	build2.setFaceTexture(Face::Front, "assets/textures/mall/b1.jpg");

	build3.setFaceTexture(Face::Up, "assets/textures/mall/b3.jpg");
	build3.setFaceTexture(Face::Down, "assets/textures/mall/b3.jpg");
	build3.setFaceTexture(Face::Left, "assets/textures/mall/b3.jpg");
	build3.setFaceTexture(Face::Right, "assets/textures/mall/b3.jpg");
	build3.setFaceTexture(Face::Back, "assets/textures/mall/b3.jpg");
	build3.setFaceTexture(Face::Front, "assets/textures/mall/b3.jpg");

}

void Buildings::drawOpaque()
{
	build1.setParentModel(getModel());
	build2.setParentModel(getModel());
	build3.setParentModel(getModel());

	build1.setPosition(glm::vec3( - build1.getWidth() / 2, 0.02f + build1.getHeight() / 2, 0.0f + build1.getDepth()));
	build1.drawOpaque();
	build2.setPosition(glm::vec3( - build2.getWidth() / 2, 0.02f + build2.getHeight() / 2, 12.0f + build1.getDepth() + build2.getDepth()));
	build2.drawOpaque();
	build3.setPosition(glm::vec3( - build3.getWidth() / 2, 0.02f + build3.getHeight() / 2, 18.0f + build1.getDepth() + build2.getDepth() + build3.getDepth()));
	build3.drawOpaque();
}

void Buildings::getTransparent()
{
}

void Buildings::onImguiRender()
{
	ImGui::SliderFloat3("Buildings Position ", &m_Position.x, -200.0f, 200.0f);
}
