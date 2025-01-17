#include "Library/booklab.h" 

Booklab::Booklab() :
    Object(),
    wall(0.08f, 15.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Right,{3,2}} }),
    raf(1.08f, 0.08f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
    column(1.08f, 0.08f, 15.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
    wall.setParentModel(getModel());
    raf.setParentModel(getModel());
    column.setParentModel(getModel());
}
void Booklab::drawOpaque() {

    wall.setParentModel(getModel());
    wall.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    wall.drawOpaque();

    float inc = 2.0f;
    raf.setParentModel(getModel());
    raf.setRotation(180.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    for (int i = 1; i <= 11; i++) {
        raf.setPosition(glm::vec3(0.0f - raf.getWidth() / 2, -9.0f + (1.5f * i), 0.0f));
        raf.drawOpaque();
    }
    column.setParentModel(getModel());
    column.setRotation(90, glm::vec3(1.0f, 0.0f, 0.0f));
    for (int i = 1; i <= 6; i++) {
        column.setPosition(glm::vec3(0.0f - column.getWidth() / 2, -0.0f, -7.0f + (inc * i)));
        column.drawOpaque();
    }

}

void Booklab::setTex()
{
    wall.setFaceTexture(Face::Down, "assets/textures/Library/wood.jpg");
    wall.setFaceTexture(Face::Up, "assets/textures/Library/wood.jpg");
    wall.setFaceTexture(Face::Left, "assets/textures/Library/wood.jpg");
    wall.setFaceTexture(Face::Right, "assets/textures/Library/wood.jpg");
    wall.setFaceTexture(Face::Back, "assets/textures/Library/wood.jpg");
    wall.setFaceTexture(Face::Front, "assets/textures/Library/wood.jpg");

    raf.setFaceTexture(Face::Up, "assets/textures/Library/wood2.jpg");
    raf.setFaceTexture(Face::Down, "assets/textures/Library/wood2.jpg");
    raf.setFaceTexture(Face::Left, "assets/textures/Library/wood2.jpg");
    raf.setFaceTexture(Face::Right, "assets/textures/Library/wood2.jpg");
    raf.setFaceTexture(Face::Back, "assets/textures/Library/wood2.jpg");
    raf.setFaceTexture(Face::Front, "assets/textures/Library/wood2.jpg");

    column.setFaceTexture(Face::Up, "assets/textures/Library/wood2.jpg");
    column.setFaceTexture(Face::Down, "assets/textures/Library/wood2.jpg");
    column.setFaceTexture(Face::Left, "assets/textures/Library/wood2.jpg");
    column.setFaceTexture(Face::Right, "assets/textures/Library/wood2.jpg");
    column.setFaceTexture(Face::Back, "assets/textures/Library/wood2.jpg");
    column.setFaceTexture(Face::Front, "assets/textures/Library/wood2.jpg");

}