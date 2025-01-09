#include "Library/floor.h"  

Floor::Floor() :
	Object(), floor(50.0f, 30.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Floor::drawOpaque()
{
	floor.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	floor.setPosition(glm::vec3(0.8f, -0.3f, 0.0f));
	floor.drawOpaque();
	 
}

void Floor::setTex()
{

	std::string texturePath = "assets/textures/floor.png";

	floor.setFaceTexture(Face::Up, texturePath);
	floor.setFaceTexture(Face::Down, texturePath);
	floor.setFaceTexture(Face::Left, texturePath);
	floor.setFaceTexture(Face::Right, texturePath);
	floor.setFaceTexture(Face::Back, texturePath);
	floor.setFaceTexture(Face::Front, texturePath);

}
