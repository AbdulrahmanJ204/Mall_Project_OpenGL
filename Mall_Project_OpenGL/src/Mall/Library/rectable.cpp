#include "Library/Rectable.h" 

Rectable::Rectable() :
    Object(),
    side(0.5f, 2.0f, 2.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    board(8.0f, 0.5f, 2.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    back(2.0f, 4.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
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
    board.setPosition(glm::vec3(4.0f, 1.0f, 0.0f));
    board.drawOpaque();
 
}

void Rectable::setTex()
{
    side.setFaceTexture(Face::Down, "assets/textures/wood.jpg");
    side.setFaceTexture(Face::Up, "assets/textures/wood.jpg");
    side.setFaceTexture(Face::Left, "assets/textures/wood.jpg");
    side.setFaceTexture(Face::Right, "assets/textures/wood.jpg");
    side.setFaceTexture(Face::Back, "assets/textures/wood.jpg");
    side.setFaceTexture(Face::Front, "assets/textures/wood.jpg"); 
    
    board.setFaceTexture(Face::Down, "assets/textures/wood.jpg");
    board.setFaceTexture(Face::Up, "assets/textures/wood.jpg");
    board.setFaceTexture(Face::Left, "assets/textures/wood.jpg");
    board.setFaceTexture(Face::Right, "assets/textures/wood.jpg");
    board.setFaceTexture(Face::Back, "assets/textures/wood.jpg");
    board.setFaceTexture(Face::Front, "assets/textures/wood.jpg");
 

}