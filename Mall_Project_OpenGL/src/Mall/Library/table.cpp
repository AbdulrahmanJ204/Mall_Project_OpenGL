#include "Library/table.h" 


Table::Table() :
	Object(), table(3.0f, 3.0f, 2.0f, 100, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", glm::vec3(0.0f, 0.0f, 0.0f)),
	table_plant("assets/objects/table_plant/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag")
{
	setTex();
}

void Table::drawOpaque()
{
	table.setParentModel(getModel());
	table.drawOpaque();

	table_plant.setParentModel(getModel());
	table_plant.setPosition(glm::vec3(0.0f, 1.0f, 0.0f));
	table_plant.setRotation(270.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	table_plant.draw();

}

void Table::setTex()
{
	std::string texturePath = "assets/textures/Library/table.jpg";

	table.setTopTexture(texturePath);
	table.setBottomTexture(texturePath);
	table.setSideTexture(texturePath);

}
void Table::onImguiRender() {
	table_plant.onImguiRender();
}