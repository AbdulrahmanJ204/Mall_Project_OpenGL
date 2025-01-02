#include "Mall.h"

Mall::Mall():Parent(),
cup(30.0f, 20.0f, 30.0f, 5.0f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
cylinder(30.0f , 20.0f , 100.0f , 300 , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
chair()
{
	//ch.setParentModel(getModel());
	cup.setInnerTexture("assets/textures/brickwall.jpg");
	cup.setOuterTexture("assets/textures/container2.png");
	cup.setRimTexture("assets/textures/container.jpg");
	cup.setParentModel(getModel());
	cylinder.setBottomTexture("assets/textures/brickwall.jpg");
	cylinder.setSideTexture("assets/textures/container2.png");
	cylinder.setTopTexture("assets/textures/container.jpg");
	cylinder.setParentModel(getModel());
	cylinder.setRotation(150.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	chair.setParentModel(getModel());
	
}

void Mall::draw()
{
	setRotation(m_RotationAngle, m_RotationAxis);
	std::cout << m_RotationAngle << std::endl;
	chair.setParentModel(getModel());
	//cup.draw();
	//chair.setPosition(glm::vec3(0.0f, 400.0f, -800.0f));
	chair.draw();
	//cylinder.draw();
}
