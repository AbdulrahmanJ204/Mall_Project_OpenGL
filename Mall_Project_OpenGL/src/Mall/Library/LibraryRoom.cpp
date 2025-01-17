#include "Library/libraryRoom.h"  

LibraryRoom::LibraryRoom() :
	Object(),

	model("assets/objects/plant4/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	door_plant("assets/objects/plant4/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	top_plant("assets/objects/plant3/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	chair("assets/objects/chair/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag"),
	arm_chair("assets/objects/arm_chair/scene.gltf",
		"assets/shaders/model_loading.vert",
		"assets/shaders/model_loading.frag")

{
	std::vector<std::string> textures = {
	"assets/textures/Library/books/book.jpg",
	"assets/textures/Library/books/book2.jpg",
	"assets/textures/Library/books/book3.jpg",
	"assets/textures/Library/books/book4.jpg",
	"assets/textures/Library/books/book5.jpg",   
	"assets/textures/Library/books/book6.jpg",
	"assets/textures/Library/books/book7.jpg",
	"assets/textures/Library/books/book8.jpg",
	"assets/textures/Library/books/book9.jpg",
	"assets/textures/Library/books/book10.jpg"
	};
	for (int i = 0; i < 10; i++) {
		book2[i].setParentModel(getModel());
		book2[i].setTex(textures[i]);
	}

}

void LibraryRoom::drawOpaque()
{
	model.setParentModel(getModel());
	chair.setParentModel(getModel());
	arm_chair.setParentModel(getModel());
	floor.setParentModel(getModel());
	shelf.setParentModel(getModel());
	wall.setParentModel(getModel());
	signboard.setParentModel(getModel());
	table.setParentModel(getModel());
	ceil.setParentModel(getModel());

	floor.drawOpaque();

	shelf.drawOpaque();

	for (int i = 0; i < 5; i++) {
		book[i].setParentModel(getModel());
		book[i].setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		book[i].setPosition(glm::vec3(0.0f, 6.0f + (-1.5f * i), 14.5f));
		book[i].drawOpaque();
	}

	shelf.setPosition(glm::vec3(0.0f, 6.0f, 14.5f));
	shelf.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	wall.drawOpaque();

	signboard.drawOpaque();

	//for plant 1
	//model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	//model.setScale(glm::vec3(0.5f, 0.5f, 0.5f)); 
	//model.setScale(glm::vec3(1.0f, 1.0f, 1.0f));

	//for plant 2
	/*model.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	model.setScale(glm::vec3(-10.0f, -10.0f, -10.0f)); */

	top_plant.setPosition(glm::vec3(0.0f, 9.9f, 14.0f));
	top_plant.setScale(glm::vec3(-0.2f, -0.2f, -0.2f));
	top_plant.drawOpaque();

	door_plant.setPosition(glm::vec3(-9.0f, -5.0f, 14.0f));
	door_plant.setScale(glm::vec3(-3.5f, -3.5f, -3.5f));
	door_plant.setRotation(90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	door_plant.drawOpaque();

	rectable.setPosition(glm::vec3(-15.0f, -3.5f, -8.0f));
	rectable.drawOpaque();

	chair.setScale(glm::vec3(0.7f, 0.7f, 0.7f));
	chair.setRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	chair.setPosition(glm::vec3(-13.0f, -4.5f, -6.0f));
	chair.drawOpaque();

	chair.setPosition(glm::vec3(-10.0f, -4.5f, -6.0f));
	chair.drawOpaque();

	chair.setPosition(glm::vec3(-7.0f, -4.5f, -6.0f));
	chair.drawOpaque();

	table.setPosition(glm::vec3(0.0f, -4.0f, 0.0f));
	table.drawOpaque();

	arm_chair.setScale(glm::vec3(0.04f, 0.04f, 0.04f));
	arm_chair.setPosition(glm::vec3(0.0f, -4.7f, -5.5f));
	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();

	arm_chair.setPosition(glm::vec3(6.0f, -4.7f, -1.5f));
	arm_chair.setRotation(270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();


	arm_chair.setPosition(glm::vec3(6.0f, -4.7f, 2.5f));
	arm_chair.setRotation(270.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();

	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	arm_chair.setPosition(glm::vec3(0.0f, -4.7f, 5.5f));
	arm_chair.setRotation(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();

	arm_chair.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));

	arm_chair.setPosition(glm::vec3(-6.0f, -4.7f, -1.5f));
	arm_chair.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();

	arm_chair.setPosition(glm::vec3(-6.0f, -4.7f, 2.5f));
	arm_chair.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	arm_chair.drawOpaque();

	ceil.drawOpaque();
	//sofa.setParentModel(getModel());
	//sofa.draw();  

	booklab.setParentModel(getModel());
	booklab.setPosition(glm::vec3(25.0f, 5.0f, -9.0f));
	booklab.drawOpaque();

	booklab.setPosition(glm::vec3(25.0f, 5.0f, 9.0f));
	booklab.drawOpaque();

	//for (int i = 0; i < 10; i++) { 
	//	book2[i].setPosition(glm::vec3(24.0f, 8.8f + (-1.5f * i), -7.8f));
	//	book2[i].drawOpaque();
	//}
	//for (int i = 0; i < 10; i++) {
	//	book2[i].setPosition(glm::vec3(24.0f, 8.8f + (-1.5f * i), 10.0f));
	//	book2[i].drawOpaque();
	//}
	clock.setParentModel(getModel());
	clock.setPosition(glm::vec3(-13.0f, 8.8f, -14.0f));
	clock.drawOpaque();
}

void LibraryRoom::onImguiRender() {

}