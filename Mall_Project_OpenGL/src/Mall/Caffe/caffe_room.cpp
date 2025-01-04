#include "caffe_room.h"

CaffeRoom::CaffeRoom() :
	caffe_wall_base(10.0f, 8.484f, 24.94f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {10, 24}},{Face::Down, {10, 24}},{Face::Right, {24, 8}} ,{Face::Left, {24, 8}},{Face::Front, {10, 8}},{Face::Back, {10, 8}} })
{

}

void CaffeRoom::draw() {
	//Postions 
	caffe_wall_base.setPosition(glm::vec3(+20 +(caffe_wall_base.getWidth() / 2) + 0.1, 10.75 + (caffe_wall_base.getHeight() / 2) + 0.015, 5.0f + (caffe_wall_base.getDepth() / 2) + 0.001));
	//Draw
	caffe_wall_base.draw();
}

void CaffeRoom::onImguiRender() {
}

void CaffeRoom::setTex()
{
	caffe_wall_base.setFaceTexture(Face::Down, "assets/textures/defaultTex.jpg", 0, 0);
	caffe_wall_base.setFaceTexture(Face::Up, "assets/textures/defaultTex.jpg", 1, 1);
	caffe_wall_base.setFaceTexture(Face::Left, "assets/textures/defaultTex.jpg", 0, 0);
	caffe_wall_base.setFaceTexture(Face::Right, "assets/textures/defaultTex.jpg", 0, 0);
	caffe_wall_base.setFaceTexture(Face::Back, "assets/textures/defaultTex.jpg", 0, 0);
	caffe_wall_base.setFaceTexture(Face::Front, "assets/textures/defaultTex.jpg", 0, 0);
}