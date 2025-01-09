#include "Chair.h"

Chair::Chair() : 
    seat(80.0f , 20.0f , 80.0f , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
    rjls.resize(4);
    for (int i = 0; i < 4; i++)
    {
        rjls[i] = Box(20.0f, 60.0f, 20.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{3,2}} });
    }
    setTex();
}

void Chair::drawOpaque() {
    // !Note: Postoins should not be like this.
    glm::vec3 positions[4] = {
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2, -30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , -30.0f)
    };
    updateModelMatrix();
    for (int i = 0; i < 4; i++)
    rjls[i].setParentModel(getModel());
    seat.setParentModel(getModel());

    for (int i = 0; i < 4; i++) {
    rjls[i].setPosition(positions[i]);
    rjls[i].drawOpaque();

    }
    seat.setPosition(glm::vec3(0.0f , 0.0f , 0.0f));
    seat.drawOpaque();
}

void Chair::getTransparent()
{
    seat.setParentModel(getModel());
    // !Note: Postoins should not be like this.
    glm::vec3 positions[4] = {
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2, -30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , -30.0f)
    };
    
    for (int i = 0; i < 4; i++) {
        rjls[i].setParentModel(getModel());
        rjls[i].setPosition(positions[i]);
        rjls[i].getTransparent();
    }
    seat.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
    seat.getTransparent();
}

void Chair::onImguiRender()
{
    ImGui::SliderFloat3("Chair Position", &m_Position.x, -100, 100);
    //rjl.onImguiRender("RJL ");
    //seat.onImguiRender("Seat ");
}

void Chair::setTex()
{

    for (int i = 0; i < 4; i++)
    {

    rjls[i].setFaceTexture(Face::Up , "assets/textures/awesomeface.png", true);
    rjls[i].setFaceTexture(Face::Down , "assets/textures/awesomeface.png", true);
    rjls[i].setFaceTexture(Face::Left , "assets/textures/awesomeface.png", true);
    rjls[i].setFaceTexture(Face::Right , "assets/textures/arrows.png",false , false , true);
    rjls[i].setFaceTexture(Face::Back ,  "assets/textures/awesomeface.png", true, true, true);
    rjls[i].setFaceTexture(Face::Front , "assets/textures/awesomeface.png",true, true , true);
    }


    seat.setFaceTexture(Face::Up , "assets/textures/oh.png");
    seat.setFaceTexture(Face::Down, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Left, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Right, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Back, "assets/textures/oh.png");
    seat.setFaceTexture(Face::Front, "assets/textures/oh.png");
}
