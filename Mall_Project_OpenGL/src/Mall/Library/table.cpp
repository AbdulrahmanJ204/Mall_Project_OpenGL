#include "Library/table.h" 
 

Table::Table() :
	Object(), table(2.5f, 2.5f, 0.1f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", glm::vec3(0.0f, 0.0f, 0.0f))
{
	setTex();
}

void Table::drawOpaque()
{
	table.setParentModel(getModel()); 
	table.drawOpaque(); 
}

void Table::setTex()
{
	std::string texturePath = "assets/textures/wood.jpg";

	table.setTopTexture(texturePath);
	table.setBottomTexture(texturePath);
	table.setSideTexture(texturePath);

}
