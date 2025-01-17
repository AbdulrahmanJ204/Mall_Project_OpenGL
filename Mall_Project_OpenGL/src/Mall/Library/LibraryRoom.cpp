#include "Library/libraryRoom.h"  

LibraryRoom::LibraryRoom() :
	Object(),
	model("assets/objects/plant4/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	chair("assets/objects/chair/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	arm_chair("assets/objects/arm_chair/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag")

{
	model.setPosition(glm::vec3(-13.0f, -5.0f, 14.0f));

	//sofa.setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

}

void LibraryRoom::drawOpaque()
{
	model.setParentModel(getModel());
	chair.setParentModel(getModel());
	arm_chair.setParentModel(getModel());

	floor.setParentModel(getModel());
	floor.drawOpaque();

	shelf.setParentModel(getModel());
	shelf.drawOpaque();

  
	for (int i = 0; i < 5; i++) {  
		book[i].setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		book[i].setPosition(glm::vec3(0.0f, 6.0f + (-1.5f * i), 14.5f));
		book[i].drawOpaque(); 
	} 

	shelf.setPosition(glm::vec3(0.0f, 6.0f, 14.5f));
	shelf.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	wall.setParentModel(getModel());
	wall.drawOpaque();



	signboard.setParentModel(getModel());
	signboard.drawOpaque();

	//for plant 1
	//model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	//model.setScale(glm::vec3(0.5f, 0.5f, 0.5f)); 
	//model.setScale(glm::vec3(1.0f, 1.0f, 1.0f));

	//for plant 2
	/*model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	model.setScale(glm::vec3(-10.0f, -10.0f, -10.0f)); */

	//for plant 3
	/*model.setPosition(glm::vec3(0.0f, 9.9f, 14.0f));
	model.setScale(glm::vec3(-0.2f, -0.2f, -0.2f));*/

	//for plant 4
	model.setScale(glm::vec3(-3.5f, -3.5f, -3.5f));
	model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	model.draw();

	rectable.setPosition(glm::vec3(-15.0f, -3.5f, -8.0f));
	rectable.drawOpaque();

	chair.setScale(glm::vec3(0.7f, 0.7f, 0.7f));
	chair.setRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	chair.setPosition(glm::vec3(-13.0f, -4.5f, -6.0f));
	chair.draw();

	chair.setPosition(glm::vec3(-10.0f, -4.5f, -6.0f));
	chair.draw();

	chair.setPosition(glm::vec3(-7.0f, -4.5f, -6.0f));
	chair.draw();

	table.setParentModel(getModel());
	table.setPosition(glm::vec3(0.0f, -4.0f, 0.0f));
	table.drawOpaque();

	arm_chair.setScale(glm::vec3(0.04f, 0.04f, 0.04f));
	arm_chair.setPosition(glm::vec3(0.0f, -4.5f, -5.5f));
	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();

	arm_chair.setPosition(glm::vec3(6.0f, -4.5f, -1.5f));
	arm_chair.setRotation(270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();


	arm_chair.setPosition(glm::vec3(6.0f, -4.5f, 2.5f));
	arm_chair.setRotation(270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();

	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	arm_chair.setPosition(glm::vec3(0.0f, -4.5f, 5.5f));
	arm_chair.setRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();

	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	arm_chair.setPosition(glm::vec3(-6.0f, -4.5f, -1.5f));
	arm_chair.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();

	arm_chair.setPosition(glm::vec3(-6.0f, -4.5f, 2.5f));
	arm_chair.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.draw();

	ceil.setParentModel(getModel());
	ceil.drawOpaque();
	//sofa.setParentModel(getModel());
	//sofa.draw();
}

void LibraryRoom::onImguiRender() {
	model.onImguiRender();
	chair.onImguiRender();
	//sofa.onImguiRender();
}