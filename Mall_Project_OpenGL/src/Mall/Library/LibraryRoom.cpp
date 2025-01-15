#include "Library/libraryRoom.h"  

LibraryRoom::LibraryRoom() :
	Object(),
	model("assets/objects/plant4/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	chair("assets/objects/chair2/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag") 
	 

{
	model.setPosition(glm::vec3(-13.0f, -5.0f, 14.0f));
	chair.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	//sofa.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

}

void LibraryRoom::drawOpaque()
{
	floor.setParentModel(getModel());
	floor.drawOpaque();
	shelf.setParentModel(getModel());
	shelf.drawOpaque();
	/*book.setParentModel(getModel());
	book.drawOpaque();*/
	shelf.setPosition(glm::vec3(0.0f, 6.0f, 14.5f));
	shelf.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	wall.setParentModel(getModel());
	wall.drawOpaque();
	//model.setParentModel(getModel());
	chair.setParentModel(getModel());
	/*table.setParentModel(getModel());
	table.drawOpaque();*/
	signboard.setParentModel(getModel());
	signboard.drawOpaque();
	//model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));//for plant 1
	//model.setScale(glm::vec3(0.5f, 0.5f, 0.5f));//for plant 1
	 rectable.drawOpaque();
	/*model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f))//for plant 2;
	model.setScale(glm::vec3(-5.0f, -5.0f, -5.0f));// for plant 2*/

	//model.setPosition(glm::vec3(0.0f, 9.9f, 14.0f));//plant 3
	//model.setScale(glm::vec3(-0.2f, -0.2f, -0.2f));// plant 3 
	//model.draw();
	//chair.setScale(glm::vec3(0.2f, 0.2f, 0.2f));
	//chair.draw();

	//model.setParentModel(getModel());
	//model.setScale(glm::vec3(-3.5f, -3.5f, -3.5f));
	//model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	//model.draw();
}

void LibraryRoom::onImguiRender() {
	//model.onImguiRender();
	//chair.onImguiRender();
	model.onImguiRender();
}
