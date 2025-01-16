#include "Library/ceil.h" 

Ceil::Ceil() :
	Object(), ceil(40.0f, 20.0f, 1.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" ),
	sideCeil(5.0f, 30.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" ),
	sideCeil2(40.0f, 5.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Ceil::drawOpaque()
{
	ceil.setParentModel(getModel());
	ceil.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	ceil.setPosition(glm::vec3(0.8f,  15.0f, 0.0f));
	ceil.drawOpaque();
	
	sideCeil.setParentModel(getModel());
	sideCeil.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	sideCeil.setPosition(glm::vec3(23.3f, 15.0f, 0.0f));
	sideCeil.drawOpaque();
	sideCeil.setPosition(glm::vec3(-21.7f, 15.0f, 0.0f));
	sideCeil.drawOpaque();

	sideCeil2.setParentModel(getModel());
	sideCeil2.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	sideCeil2.setPosition(glm::vec3(0.8f, 15.0f, 12.5f));
	sideCeil2.drawOpaque();
	sideCeil2.setPosition(glm::vec3(0.8f, 15.0f, -12.5f));
	sideCeil2.drawOpaque();
}

void Ceil::setTex()
{ 
	std::string texturePath = "assets/textures/ceil.jpg";
	std::string texturePath2 = "assets/textures/black.png";
   
	ceil.setFaceTexture(Face::Up, texturePath);
	ceil.setFaceTexture(Face::Down, texturePath);
	ceil.setFaceTexture(Face::Left, texturePath);
	ceil.setFaceTexture(Face::Right, texturePath);
	ceil.setFaceTexture(Face::Back, texturePath);
	ceil.setFaceTexture(Face::Front, texturePath); 

	sideCeil.setFaceTexture(Face::Up, texturePath2);
	sideCeil.setFaceTexture(Face::Down, texturePath2);
	sideCeil.setFaceTexture(Face::Left, texturePath2);
	sideCeil.setFaceTexture(Face::Right, texturePath2);
	sideCeil.setFaceTexture(Face::Back, texturePath2);
	sideCeil.setFaceTexture(Face::Front, texturePath2);

	sideCeil2.setFaceTexture(Face::Up, texturePath2);
	sideCeil2.setFaceTexture(Face::Down, texturePath2);
	sideCeil2.setFaceTexture(Face::Left, texturePath2);
	sideCeil2.setFaceTexture(Face::Right, texturePath2);
	sideCeil2.setFaceTexture(Face::Back, texturePath2);
	sideCeil2.setFaceTexture(Face::Front, texturePath2);
}
