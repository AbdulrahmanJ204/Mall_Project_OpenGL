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
    for (int i = 1; i <= 10; i++) {
        book.setPosition(glm::vec3(0.8f, -0.3f, 0.0f + (inc * i)));
        book.drawOpaque();
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
