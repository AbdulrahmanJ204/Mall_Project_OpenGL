#include "Library/book2.h" 

Book2::Book2() :
	Object(), book(0.05f, 1.0f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	 
}

void Book2::drawOpaque()
{
	book.setParentModel(getModel());
	float inc = 0.12;
	book.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	float x = 2.0f;

	for (int c = 0; c < 5; c++)
	{
		for (int i = 1; i <= 10; i++) {
			book.setPosition(glm::vec3(0.8f, 2.7f, -6.0f + (inc * i) + (c * x)));
			book.drawOpaque();
		}
	} 

}

void Book2::setTex(const std::string& path)
{ 
	book.setFaceTexture(Face::Up, path);
	book.setFaceTexture(Face::Down, path);
	book.setFaceTexture(Face::Left, path);
	book.setFaceTexture(Face::Right, path);
	book.setFaceTexture(Face::Back, path);
	book.setFaceTexture(Face::Front, path);

}
