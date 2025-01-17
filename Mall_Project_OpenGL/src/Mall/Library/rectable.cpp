#include "Library/Rectable.h" 

Rectable::Rectable() :
    Object(),
    side(0.5f, 2.5f, 2.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    board(10.0f, 0.5f, 2.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    back(10.0f, 2.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    book(1.0f, 1.0f, 0.1f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
    side.setParentModel(getModel());
    board.setParentModel(getModel());
    back.setParentModel(getModel());
}
void Rectable::drawOpaque() {

    side.setParentModel(getModel());
    side.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    side.drawOpaque();
    board.setParentModel(getModel());
    board.setPosition(glm::vec3(5.25f, 1.0f, 0.0f));
    board.drawOpaque();

    back.setParentModel(getModel());
    back.setPosition(glm::vec3(5.25f, -0.25f, -1.0f));
    back.drawOpaque();
 
   
    side.setPosition(glm::vec3(10.5f, 0.0f, 0.0f));
    side.drawOpaque();

    book.setParentModel(getModel());
    book.setPosition(glm::vec3(2.2f, 1.3f, 0.0f));
    book.setRotation(90.0f,glm::vec3(1.0f, 0.0f, 0.0f));
    book.drawOpaque();
    book.setPosition(glm::vec3(5.2f, 1.3f, 0.0f));
    book.drawOpaque();
    book.setPosition(glm::vec3(8.2f, 1.3f, 0.0f));
    book.drawOpaque();
}

void Rectable::setTex()
{
    side.setFaceTexture(Face::Down, "assets/textures/rectable.jpg");
    side.setFaceTexture(Face::Up, "assets/textures/rectable.jpg");
    side.setFaceTexture(Face::Left, "assets/textures/rectable.jpg");
    side.setFaceTexture(Face::Right, "assets/textures/rectable.jpg");
    side.setFaceTexture(Face::Back, "assets/textures/rectable.jpg");
    side.setFaceTexture(Face::Front, "assets/textures/rectable.jpg");
    
    board.setFaceTexture(Face::Down, "assets/textures/rectable2.jpg");
    board.setFaceTexture(Face::Up, "assets/textures/rectable2.jpg");
    board.setFaceTexture(Face::Left, "assets/textures/rectable2.jpg");
    board.setFaceTexture(Face::Right, "assets/textures/rectable2.jpg");
    board.setFaceTexture(Face::Back, "assets/textures/rectable2.jpg");
    board.setFaceTexture(Face::Front, "assets/textures/rectable2.jpg");

    back.setFaceTexture(Face::Down, "assets/textures/rectable2.jpg");
    back.setFaceTexture(Face::Up, "assets/textures/rectable2.jpg");
    back.setFaceTexture(Face::Left, "assets/textures/rectable2.jpg");
    back.setFaceTexture(Face::Right, "assets/textures/rectable2.jpg");
    back.setFaceTexture(Face::Back, "assets/textures/rectable2.jpg");
    back.setFaceTexture(Face::Front, "assets/textures/rectable2.jpg");
 
    book.setFaceTexture(Face::Down, "assets/textures/book.jpg");
    book.setFaceTexture(Face::Up, "assets/textures/book.jpg");
    book.setFaceTexture(Face::Left, "assets/textures/book.jpg");
    book.setFaceTexture(Face::Right, "assets/textures/book.jpg");
    book.setFaceTexture(Face::Back, "assets/textures/book.jpg");
    book.setFaceTexture(Face::Front, "assets/textures/book.jpg");

}