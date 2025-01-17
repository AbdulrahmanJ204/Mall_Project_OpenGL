#include "Library/wall.h" 

Wall::Wall() :
	Object(), wall(35.0f, 20.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	wall2(50.0f, 20.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{2,1}} }),
	wall3(30.0f, 20.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
	logo(15.0f, 6.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")

{
	setTex();
}

void Wall::drawOpaque()
{
	wall.setParentModel(getModel());

	wall.setPosition(glm::vec3(8.3f, 4.9f, 15.0f));
	wall.drawOpaque();

	wall2.setPosition(glm::vec3(0.8f, 4.9f, -15.0f));
	wall2.drawOpaque();

	wall3.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	wall3.setPosition(glm::vec3(25.8f, 4.9f, 0.0f));
	wall3.drawOpaque();

	wall3.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	wall3.setPosition(glm::vec3(-24.2f, 4.9f, 0.0f));
	wall3.drawOpaque();

	logo.setParentModel(getModel());
	logo.setPosition(glm::vec3(-16.7f, 12.5f, 15.0f));
	logo.drawOpaque();
}

void Wall::setTex()
{

	std::string texturePath = "assets/textures/wall5.jpg";
	std::string texturePath2 = "assets/textures/wall3.jpg";
	std::string texturePath3 = "assets/textures/wall4.jpg";
	std::string texturePath4 = "assets/textures/logo.jpg";

	wall.setFaceTexture(Face::Up, texturePath);
	wall.setFaceTexture(Face::Down, texturePath);
	wall.setFaceTexture(Face::Left, texturePath);
	wall.setFaceTexture(Face::Right, texturePath);
	wall.setFaceTexture(Face::Back, texturePath);
	wall.setFaceTexture(Face::Front, texturePath);

	wall2.setFaceTexture(Face::Up, texturePath2);
	wall2.setFaceTexture(Face::Down, texturePath2);
	wall2.setFaceTexture(Face::Left, texturePath2);
	wall2.setFaceTexture(Face::Right, texturePath2);
	wall2.setFaceTexture(Face::Back, texturePath2);
	wall2.setFaceTexture(Face::Front, texturePath2);

	wall3.setFaceTexture(Face::Up, texturePath3);
	wall3.setFaceTexture(Face::Down, texturePath3);
	wall3.setFaceTexture(Face::Left, texturePath3);
	wall3.setFaceTexture(Face::Right, texturePath3);
	wall3.setFaceTexture(Face::Back, texturePath3);
	wall3.setFaceTexture(Face::Front, texturePath3);

	logo.setFaceTexture(Face::Up, texturePath4);
	logo.setFaceTexture(Face::Down, texturePath4);
	logo.setFaceTexture(Face::Left, texturePath4);
	logo.setFaceTexture(Face::Right, texturePath4);
	logo.setFaceTexture(Face::Back, texturePath4);
	logo.setFaceTexture(Face::Front, texturePath4);

}
