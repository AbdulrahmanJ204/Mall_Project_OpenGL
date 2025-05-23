#include "Library/signboard.h" 

Signboard::Signboard() :
    Object(),
    board(15.0f, 8.5f, 0.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" ),
    board2(0.2f, 7.5f, 7.2f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
    board.setParentModel(getModel()); 
    board2.setParentModel(getModel()); 
}
void Signboard::drawOpaque() {
    board.setParentModel(getModel());
    board2.setParentModel(getModel());

    board.setPosition(glm::vec3(0.0f, 10.0f, -14.5f));
    board.drawOpaque();

    board2.setPosition(glm::vec3(24.0f, 5.0f, 0.0f));
    board2.drawOpaque();
}

void Signboard::setTex()
{
    board.setFaceTexture(Face::Down, "assets/textures/Library/wood.jpg");
    board.setFaceTexture(Face::Up, "assets/textures/Library/wood.jpg");
    board.setFaceTexture(Face::Left, "assets/textures/Library/wood.jpg");
    board.setFaceTexture(Face::Right, "assets/textures/Library/wood.jpg");
    board.setFaceTexture(Face::Back, "assets/textures/Library/signboard.jpg");
    board.setFaceTexture(Face::Front, "assets/textures/Library/signboard.jpg");
 
    board2.setFaceTexture(Face::Down, "assets/textures/Library/signboard2.jpg");
    board2.setFaceTexture(Face::Up, "assets/textures/Library/signboard2.jpg");
    board2.setFaceTexture(Face::Left, "assets/textures/Library/signboard2.jpg");
    board2.setFaceTexture(Face::Right, "assets/textures/Library/signboard2.jpg");
    board2.setFaceTexture(Face::Back, "assets/textures/Library/signboard2.jpg");
    board2.setFaceTexture(Face::Front, "assets/textures/Library/signboard2.jpg");
}