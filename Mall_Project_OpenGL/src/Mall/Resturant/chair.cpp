#include "chair.h"

chair::chair() : 
    Parent(),
    rjl(20.0f , 60.0f , 20.0f , "assets/shaders/vertexSh.vert" , "assets/shaders/fragSh.frag"),
    seat(80.0f , 20.0f , 80.0f , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
    rjl.setParentModel(model);
    seat.setParentModel(model);
}

void chair::draw() {
        glm::vec3 positions[4] = {
        glm::vec3(30.0f , - seat.getHeight()/2 - rjl.getHeight() /2 , 30.0f),
        glm::vec3(30.0f , -seat.getHeight()/2 - rjl.getHeight() /2, -30.0f),
        glm::vec3(-30.0f , -seat.getHeight()/2- rjl.getHeight() /2 , 30.0f),
        glm::vec3(-30.0f , -seat.getHeight()/2- rjl.getHeight() /2 , -30.0f)
    };
    for (int i = 0; i < 4; i++) {
    rjl.setPosition(positions[i]);
    rjl.draw(m_View, m_Projection);

    }
    seat.setPosition(glm::vec3(0.0f , 0.0f , 0.0f));
    seat.draw(m_View, m_Projection);
}

void chair::setTex()
{
    rjl.setFaceTexture(Face::Up , "assets/textures/container.jpg");
    rjl.setFaceTexture(Face::Down , "assets/textures/container.jpg");
    rjl.setFaceTexture(Face::Left , "assets/textures/container.jpg");
    rjl.setFaceTexture(Face::Right , "assets/textures/container.jpg");
    rjl.setFaceTexture(Face::Back , "assets/textures/container.jpg");
    rjl.setFaceTexture(Face::Front , "assets/textures/container.jpg");


    seat.setFaceTexture(Face::Up , "assets/textures/oh.png");
    seat.setFaceTexture(Face::Down, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Left, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Right, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Back, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Front, "assets/textures/oh.png");
}
