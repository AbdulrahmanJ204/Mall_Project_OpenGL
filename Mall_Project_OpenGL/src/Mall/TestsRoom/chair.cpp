#include "Chair.h"

Chair::Chair() : 
    light(glm::vec3(20.0f , 20.0f ,20.0f) , LightHelper::getLightColor("default") , 30.0f),
    seat(80.0f , 20.0f , 80.0f , "assets/shaders/vertex.vert", "assets/shaders/fragment.frag")
{
    rjls.resize(4);
    for (int i = 0; i < 4; i++)
    {
        rjls[i] = Box(20.0f, 60.0f, 20.0f, "assets/shaders/vertex.vert", "assets/shaders/fragment.frag", { {Face::Front,{3,2}} });
    }
    setTex();
    //setTargetPosition(glm::vec3(0.0f, 500.0f, 0.0f));
}

void Chair::drawOpaque() {
    // !Note: Postoins should not be like this.
    glm::vec3 positions[4] = {
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2, -30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , 30.0f),
    glm::vec3(-30.0f , -seat.getHeight() / 2 - rjls[0].getHeight() / 2 , -30.0f)
    };
    //update();
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
    ImGui::SliderFloat3("Chair Position", &m_Position.x, -500, 500);
    int i = 0;
    for (Box& x : rjls) x.onImguiRender("RJL " + std::to_string(i++));
    //rjl.onImguiRender("RJL ");
    seat.onImguiRender("Seat ");
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


    seat.setFaceTexture(Face::Up ,   "assets/textures/container.jpg");
    seat.setFaceTexture(Face::Down,  "assets/textures/container.jpg");
    seat.setFaceTexture(Face::Left,  "assets/textures/container.jpg");
    seat.setFaceTexture(Face::Right, "assets/textures/container.jpg");
    seat.setFaceTexture(Face::Back,  "assets/textures/container.jpg");
    seat.setFaceTexture(Face::Front, "assets/textures/container.jpg");
}
