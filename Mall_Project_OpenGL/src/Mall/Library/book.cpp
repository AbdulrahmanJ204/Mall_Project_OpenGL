#include "Library/book.h"  
Book::Book() :
	Object(), book(0.05f, 1.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	setTex();
}

void Book::drawOpaque()
{
	book.setParentModel(getModel());
	float inc = 0.12;
	book.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	float x = 1.5f;
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			for (int i = 1; i <= 10; i++) {
				book.setPosition(glm::vec3(0.8f, 2.7f + (-1.5f * r), -6.0f + (inc * i) + (c * x)));
				book.drawOpaque();
			}
		}
	}

}

void Book::setTex()
{

	std::string texturePath = "assets/textures/book.jpg";

	book.setFaceTexture(Face::Up, texturePath);
	book.setFaceTexture(Face::Down, texturePath);
	book.setFaceTexture(Face::Left, texturePath);
	book.setFaceTexture(Face::Right, texturePath);
	book.setFaceTexture(Face::Back, texturePath);
	book.setFaceTexture(Face::Front, texturePath);

}
