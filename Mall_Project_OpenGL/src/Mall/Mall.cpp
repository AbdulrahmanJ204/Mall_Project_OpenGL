#include "Mall.h"

Mall::Mall():
cl(30.0f , 100.0f ,100 , "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag")
{
	//ch.setParentModel(getModel());
}

void Mall::draw()
{
	//ch.draw();
	cl.draw();
}
