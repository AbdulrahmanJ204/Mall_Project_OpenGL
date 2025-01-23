#include "tv.h"

TV::TV(int type) :
	type(type),
	tv(3.0f, 1.8f, 0.02f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {1, 1}}, })
{
	
	setTex();
}

void TV::drawOpaque() {
	
	//Postions 
	
	//Draw

	
}

void TV::getTransparent() {
	tv.setParentModel(getModel());
	tv.getTransparent();
}


void TV::onImguiRender() {
	ImGui::SliderFloat3("TV Position ", &m_Position.x, -100.0f, 100.0f);
}

void TV::setTex()
{
	if (type == 1) {
		tv.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png", 1);
		tv.setFaceTexture(Face::Up, "assets/textures/electronic/tv_1_3.png");
		tv.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png",1);
		tv.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png",1);
		tv.setFaceTexture(Face::Back, "assets/textures/electronic/tv_1_2.png",1);
		tv.setFaceTexture(Face::Front, "assets/textures/electronic/tv_1_1.png",1);
	}else if (type == 2) {
		tv.setFaceTexture(Face::Down, "assets/textures/electronic/tv_55_2.png", 1);
		tv.setFaceTexture(Face::Up, "assets/textures/electronic/tv_55_2.png",1);
		tv.setFaceTexture(Face::Left, "assets/textures/electronic/tv_55_2.png",1);
		tv.setFaceTexture(Face::Right, "assets/textures/electronic/tv_55_2.png",1);
		tv.setFaceTexture(Face::Back, "assets/textures/electronic/tv_55_2.png",1);
		tv.setFaceTexture(Face::Front, "assets/textures/electronic/tv_43_1.png",1);
	}
	else if (type == 3) {
		tv.setFaceTexture(Face::Down, "assets/textures/electronic/tv_1_3.png", 1);
		tv.setFaceTexture(Face::Up, "assets/textures/electronic/tv_1_3.png");
		tv.setFaceTexture(Face::Left, "assets/textures/electronic/tv_1_3.png", 1);
		tv.setFaceTexture(Face::Right, "assets/textures/electronic/tv_1_3.png", 1);
		tv.setFaceTexture(Face::Back, "assets/textures/electronic/tv_1_2.png", 1);
		tv.setFaceTexture(Face::Front, "assets/textures/electronic/tv_2_1.png", 1);
	}
	
}