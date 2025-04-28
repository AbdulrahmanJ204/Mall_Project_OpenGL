#include "Library/counterL.h" 

Counter::Counter() :
	Object(), counter1(1.5f, 7.0f, 10.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	  counter2(1.5f, 7.0f, 6.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Counter::drawOpaque()
{
	counter1.setParentModel(getModel());
	//counter1.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	counter1.setPosition(glm::vec3(10.8f, -5.0f, 0.0f));
	counter1.drawOpaque();

	//counter2.setParentModel(getModel());
	//counter2.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 1.0f));
	//counter2.setPosition(glm::vec3(10.8f, -5.0f, 0.0f));
	//counter2.drawOpaque();

}

void Counter::setTex()
{
	std::string texturePath = "assets/textures/Library/ceil.png";

	counter1.setFaceTexture(Face::Up, texturePath);
	counter1.setFaceTexture(Face::Down, texturePath);
	counter1.setFaceTexture(Face::Left, texturePath);
	counter1.setFaceTexture(Face::Right, texturePath);
	counter1.setFaceTexture(Face::Back, texturePath);
	counter1.setFaceTexture(Face::Front, texturePath);

	counter2.setFaceTexture(Face::Up, texturePath);
	counter2.setFaceTexture(Face::Down, texturePath);
	counter2.setFaceTexture(Face::Left, texturePath);
	counter2.setFaceTexture(Face::Right, texturePath);
	counter2.setFaceTexture(Face::Back, texturePath);
	counter2.setFaceTexture(Face::Front, texturePath);

}
