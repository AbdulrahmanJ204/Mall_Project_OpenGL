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
	 
		for (int c = 0; c < 8; c++)
		{
			for (int i = 1; i <= 10; i++) {
				book.setPosition(glm::vec3(0.8f, 2.7f , -6.0f + (inc * i) + (c * x)));
				book.drawOpaque();
			}
		}
 

}

void Book::setTex()
{ 
	std::vector<std::string> textures = {
	   "assets/textures/Library/books/book.jpg",
	   "assets/textures/Library/books/book2.jpg",
	   "assets/textures/Library/books/book3.jpg",
	   "assets/textures/Library/books/book4.jpg",
	   "assets/textures/Library/books/book5.jpg"
	};
	 
	int randomIndex = rand() % textures.size();  
	std::string selectedTexture = textures[randomIndex];
	 
	book.setFaceTexture(Face::Up, selectedTexture);
	book.setFaceTexture(Face::Down, selectedTexture);
	book.setFaceTexture(Face::Left, selectedTexture);
	book.setFaceTexture(Face::Right, selectedTexture);
	book.setFaceTexture(Face::Back, selectedTexture);
	book.setFaceTexture(Face::Front, selectedTexture);

}
