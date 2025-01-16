#include "Library/ceil.h" 

Ceil::Ceil() :
	Object(), ceil(50.0f, 30.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{10,10}} })
{
	setTex();
}

void Ceil::drawOpaque()
{
	ceil.setParentModel(getModel());
	ceil.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	ceil.setPosition(glm::vec3(0.8f,  15.0f, 0.0f));
	ceil.drawOpaque();
	 
}

void Ceil::setTex()
{ 
	std::string texturePath = "assets/textures/ceil.jpg";
 
	ceil.setFaceTexture(Face::Up, texturePath);
	ceil.setFaceTexture(Face::Down, texturePath);
	ceil.setFaceTexture(Face::Left, texturePath);
	ceil.setFaceTexture(Face::Right, texturePath);
	ceil.setFaceTexture(Face::Back, texturePath);
	ceil.setFaceTexture(Face::Front, texturePath);

}
