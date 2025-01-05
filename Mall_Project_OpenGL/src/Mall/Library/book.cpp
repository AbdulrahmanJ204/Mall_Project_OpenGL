#include "Library/book.h" 

Book::Book() :
    Parent(), book(0.05f, 0.5f, 0.5f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
}

Book::~Book() {

}
void Book::draw()
{

    float inc = 0.1;

    for (int i = 1; i <= 10; i++) {
        book.setPosition(glm::vec3(2.0f + (inc * i), 0.0f, 0.0f)); 
        book.draw();
    }

}

void Book::setTex( )
{
    const std::vector<std::string> textures = {
      "assets/textures/book1.jpg",
      "assets/textures/book2.jpg",
      "assets/textures/book3.jpg"
    };

    std::string texturePath = textures[1];

    book.setFaceTexture(Face::Up, texturePath);
    book.setFaceTexture(Face::Down, texturePath);
    book.setFaceTexture(Face::Left, texturePath);
    book.setFaceTexture(Face::Right, texturePath);
    book.setFaceTexture(Face::Back, texturePath);
    book.setFaceTexture(Face::Front, texturePath);

}
