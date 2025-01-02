#include "Mall.h"

Mall::Mall():
cl(30.0f , 20.0f ,20.0f , 15.0f	, 50.0f ,100 , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	//ch.setParentModel(getModel());
	cl.setBottomTexture("assets/textures/brickwall.jpg");
	cl.setSideTexture("assets/textures/container2.png");
	cl.setTopTexture("assets/textures/container.jpg");
	cl.setParentModel(getModel());
}

void Mall::draw()
{
	//ch.draw();
	cl.draw();
}
