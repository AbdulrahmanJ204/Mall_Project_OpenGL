#include "Chair.h"

Chair::Chair() : 
    Parent(),
    rjl(20.0f, 60.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{3,2}} }),
    seat(80.0f , 20.0f , 80.0f , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    setTex();
    rjl.setParentModel(getModel());
    seat.setParentModel(getModel());
}

void Chair::draw() {
    //rjl.setRotation(30.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        
rjl.setParentModel(getModel());
    seat.setParentModel(getModel());
        glm::vec3 positions[4] = {
        glm::vec3(30.0f , - seat.getHeight()/2 - rjl.getHeight() /2 , 30.0f),
        glm::vec3(30.0f , -seat.getHeight()/2 - rjl.getHeight() /2, -30.0f),
        glm::vec3(-30.0f , -seat.getHeight()/2- rjl.getHeight() /2 , 30.0f),
        glm::vec3(-30.0f , -seat.getHeight()/2- rjl.getHeight() /2 , -30.0f)
    };
    for (int i = 0; i < 4; i++) {
    rjl.setPosition(positions[i]);
    rjl.draw();

    }
    seat.setPosition(glm::vec3(0.0f , 0.0f , 0.0f));
    seat.draw();
}

void Chair::setTex()
{
    rjl.setFaceTexture(Face::Up ,    "assets/textures/arrows.png");
    rjl.setFaceTexture(Face::Down ,  "assets/textures/arrows.png");
    rjl.setFaceTexture(Face::Left ,  "assets/textures/arrows.png");
    rjl.setFaceTexture(Face::Right , "assets/textures/arrows.png",false , true);
    rjl.setFaceTexture(Face::Back ,  "assets/textures/arrows.png",true);
    rjl.setFaceTexture(Face::Front , "assets/textures/awesomeface.png", true , true);


    seat.setFaceTexture(Face::Up , "assets/textures/oh.png");
    seat.setFaceTexture(Face::Down, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Left, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Right, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Back, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Front, "assets/textures/oh.png");
}
