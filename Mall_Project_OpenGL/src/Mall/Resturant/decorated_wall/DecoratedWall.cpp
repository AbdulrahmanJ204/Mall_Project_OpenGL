#include "Resturant/decorated_wall/DecoratedWall.h"

DecoratedWall::DecoratedWall() : Object(),
// width, height, depth
frontWall(frontWallWidth, frontWallHeight, frontWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left,{30,2}},{Face::Right,{30,2}} }),
leftWall(leftWallWidth, leftWallHeight, leftWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{15,2}},{Face::Back,{15,2}} }),

bigFloor(bigFloorWidth, bigFloorHeight, bigFloorDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up,{4,11}},{Face::Down,{4,11}} }),
smallFloor(smallFloorWidth, smallFloorHeight, smallFloorDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up,{2,3}},{Face::Down,{2,3}} }),

bigRoof(bigFloorWidth, bigFloorHeight, bigFloorDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up,{4,11}},{Face::Down,{4,11}} }),
smallRoof(smallFloorWidth, smallFloorHeight, smallFloorDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up,{2,3}},{Face::Down,{2,3}} }),

upperWall(upperWallWidth, upperWallHeight, upperWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),

separateorWall(separateorWallWidth, separateorWallHeight, separateorWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" ,{ {Face::Front, { 1,2 }}, { Face::Back,{1,2} } }),
separatorWall2(separateorWall2Width, separateorWall2Height, separateorWall2Depth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
separatorShingle(separatorShingleWidth, separatorShingleHeight, separatorShingleDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),


primaryPiller(primaryPillerWidth, primaryPillerHeight, primaryPillerDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left, { 22,1 }}, { Face::Right,{22,1} } ,{Face::Down, { 22,1 }}, { Face::Up,{22,1} } }),
secondoryPiller(secondoryPillerWidth, secondoryPillerHeight, secondoryPillerDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),

woodWall(woodWallWidth, woodWallHeight, woodWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left,{22,1}},{Face::Right,{22,1}} }),


leftUpperWall(leftUpperWallWidth, leftUpperWallHeight, leftUpperWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
leftWoodWall(leftWoodWallWidth, leftWoodWallHeight, leftWoodWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{14,1}},{Face::Back,{14,1}} }),
shingle(shingleWidth, shingleHeight, shingleDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
shelf(shelfWidth, shelfHeight, shelfDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
rightWallFar(rightWallFarWidth, rightWallFarHeight, rightWallFarDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),



tableTexture(3.3f, 0.14f, 1.7f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"), 
pot("assets/textures/resturant/models/simple_aloe_pot_plant/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
chair("assets/textures/resturant/models/chairs/backless_chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
table("assets/textures/resturant/models/chairs/high_table/source/Unity2Skfb/Unity2Skfb.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
plant1("assets/textures/resturant/models/plant_fbx/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
tropicalPlant("assets/textures/resturant/models/tropical_plant_bush/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
ivy1("assets/textures/resturant/models/ivy1/model.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
ivy2("assets/textures/resturant/models/ivy2/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
ivy3("assets/textures/resturant/models/ivy3/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
coverPlant("assets/textures/resturant/models/cover_plant/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
creepyPlant("assets/textures/resturant/models/purple_creeper_plant/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
sofa("assets/textures/resturant/models/chairs/high_chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag")
{
	fillFoods();
	setTex(frontWall, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(leftWall, "assets/textures/resturant/stones/stone8/stone.png");

	setTex(separateorWall, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(separatorWall2, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(separatorShingle, "assets/textures/resturant/window/wood/wood10/wood.png");

	setTex(primaryPiller, "assets/textures/resturant/plasters/plaster2/plaster.png");
	setTex(secondoryPiller, "assets/textures/resturant/plasters/plaster2/plaster.png");


	setTex(bigFloor, "assets/textures/resturant/tiles/floor_tile/tile.jpg");
	setTex(smallFloor, "assets/textures/resturant/tiles/floor_tile/tile.jpg");

	setTex(smallRoof, "assets/textures/resturant/tiles/tile8/tile.png");
	setTex(bigRoof, "assets/textures/resturant/tiles/tile8/tile.png");

	setTex(upperWall, "assets/textures/resturant/plasters/plaster1/plaster.png");
	setTex(woodWall, "assets/textures/resturant/window/wood/wood10/wood.png");
	
	setTex(leftUpperWall, "assets/textures/resturant/plasters/plaster1/plaster.png");
	setTex(leftWoodWall, "assets/textures/resturant/window/wood/wood10/wood.png");

	setTex(shingle, "assets/textures/resturant/window/wood/wood18/wood.png");
	setTex(shelf, "assets/textures/resturant/window/wood/wood18/wood.png");

	setTex(tableTexture, "assets/textures/resturant/window/wood/wood7/wood.png");


	rightWallFar.setFaceTexture(Face::Up, "assets/textures/resturant/stones/stone8/stone.png");
	rightWallFar.setFaceTexture(Face::Down, "assets/textures/resturant/stones/stone8/stone.png");
	rightWallFar.setFaceTexture(Face::Back, "assets/textures/resturant/stones/stone8/stone.png");
	rightWallFar.setFaceTexture(Face::Front, "assets/textures/resturant/kitchen/kitchen.png");
	rightWallFar.setFaceTexture(Face::Left, "assets/textures/resturant/stones/stone8/stone.png");
	rightWallFar.setFaceTexture(Face::Right, "assets/textures/resturant/stones/stone8/stone.png");




	frontWall.setPosition(glm::vec3(-20.0f, -0.76f, (frontWallDepth / 2.0f) - 7.0f - 1.16f));
	leftWall.setPosition(glm::vec3(-20.0f+leftWallWidth/2.0f, -0.76f,45.0f-1.16f));
	upperWall.setPosition(glm::vec3(-20.0f + (upperWallWidth / 2.0f), 1.8f - (upperWallHeight / 2.0f), (upperWallDepth / 2.0f) - 7.0f - 1.16f));
	woodWall.setPosition(glm::vec3(-20.0f + (upperWallWidth ) + (woodWallWidth/2.0f), 1.8f - (woodWallHeight / 2.0f), (woodWallDepth / 2.0f) - 7.0f - 1.16f));

	leftUpperWall.setPosition(glm::vec3(-20.0f + leftWallWidth / 2.0f, 1.8f - (leftUpperWallHeight / 2.0f), 45.0f - 1.16f - (leftUpperWallDepth / 2.0f)));
	leftWoodWall.setPosition(glm::vec3(-20.0f + leftWallWidth / 2.0f, 1.8f - (leftWoodWallHeight /2.0f), 45.0f - 1.16f - leftUpperWallDepth - (leftWoodWallDepth/2.0f)));

	bigFloor.setPosition(glm::vec3(-10.0f, -3.29f, (bigFloorDepth / 2.0f) - 7.0f - 1.16f));
	smallFloor.setPosition(glm::vec3(smallFloorWidth / 2.0f, -3.29f, (smallFloorDepth / 2.0f) + 31.5f - 1.0f));
	bigRoof.setPosition(glm::vec3(-10.0f, 1.8f, (bigFloorDepth / 2.0f) - 7.0f - 1.16f));
	smallRoof.setPosition(glm::vec3(smallFloorWidth / 2.0f, 1.8f, (smallFloorDepth / 2.0f) + 31.5f - 1.0f));

	rightWallFar.setPosition(glm::vec3(-10.0f, -0.76f, -7.0f));


}

void DecoratedWall::drawOpaque()
{
	frontWall.setParentModel(getModel());
	frontWall.drawOpaque();

	leftWall.setParentModel(getModel());
	leftWall.drawOpaque();



	bigFloor.setParentModel(getModel());
	bigFloor.drawOpaque();


	smallFloor.setParentModel(getModel());
	smallFloor.drawOpaque();


	bigRoof.setParentModel(getModel());
	bigRoof.drawOpaque();


	smallRoof.setParentModel(getModel());
	smallRoof.drawOpaque();

	upperWall.setParentModel(getModel());
	upperWall.drawOpaque();


	woodWall.setParentModel(getModel());
	woodWall.drawOpaque();

	leftWoodWall.setParentModel(getModel());
	leftWoodWall.drawOpaque();

	leftUpperWall.setParentModel(getModel());
	leftUpperWall.drawOpaque();

	rightWallFar.setParentModel(getModel());
	rightWallFar.drawOpaque();

	primaryPiller.setParentModel(getModel());
	primaryPiller.setPosition(glm::vec3(-10.885f, 0.680f,19.661f));
	primaryPiller.drawOpaque();

	primaryPiller.setParentModel(getModel());
	primaryPiller.setPosition(glm::vec3(-10.885f + 1.642f, 0.680f, 19.661f));
	primaryPiller.drawOpaque();

	

	for (int i = 0; i < 19; i++)
	{

		coverPlant.setParentModel(getModel());
		tropicalPlant.setParentModel(getModel());

		if ((i % 2) == 0) {

			coverPlant.setPosition(glm::vec3(-9.1f - 1.642f - 0.5f, 0.19f , i * 2));
			tropicalPlant.setPosition(glm::vec3(-9.6f, 0.8f, 1 + i*2));
		}
		else {
			coverPlant.setPosition(glm::vec3(-9.1f , 0.19f, i * 2));
			tropicalPlant.setPosition(glm::vec3( - 9.6f - 1.642f, 0.8f, 1 + i*2));

		}

		coverPlant.setRotation(-90, glm::vec3(0.0f, 1.0f, 0.0f));
		coverPlant.drawOpaque();

		tropicalPlant.setScale(0.002);
		tropicalPlant.drawOpaque();
	}

	for (int i = 0; i < 38; i++)
	{
		secondoryPiller.setParentModel(getModel());
		secondoryPiller.setPosition(glm::vec3(-10.064f, 0.680f, 1 + i));
		secondoryPiller.drawOpaque();
	}

<<<<<<< HEAD
	for (int i = 0; i < 7; i++)
=======
	for (int i = 0; i < 4; i++)
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
	{
		separateorWall.setParentModel(getModel());
		separateorWall.setPosition(glm::vec3(-19.0f,-0.74, 9.300 + (i*11)));
		separateorWall.drawOpaque();

		separatorWall2.setParentModel(getModel());
		separatorWall2.setPosition(glm::vec3(-17.5f, -2.750f,9.3f + (i * 11)));
		separatorWall2.drawOpaque();

		separatorShingle.setParentModel(getModel());
		separatorShingle.setPosition(glm::vec3(-17.5f, -2.750f + (separateorWall2Height / 2) + (separatorShingleHeight / 2), 9.3f + (i * 11)));
		separatorShingle.drawOpaque();
	}

	float distance = -6.0f;
	for (int i = 0; i < 8; i++)
	{
		if (i % 2) {
			distance += 5;
		}
		else {
			distance += 6;
		}

		shelf.setParentModel(getModel());
		shelf.setPosition(glm::vec3(-20.0f + shingleWidth + (shelfWidth / 2.0f), -0.75f + (shingleHeight / 2.0f) - 0.25f, 1.25f + distance));
		shelf.drawOpaque();


		pot.setParentModel(getModel());
		pot.setPosition(glm::vec3(-19.728f, 0.06f , 1.25f + distance));
		pot.drawOpaque();
		pot.setScale(0.11f);

		shingle.setParentModel(getModel());
		shingle.setPosition(glm::vec3(-20.0f + (shingleWidth / 2.0f), -0.75f, 1.25f + distance));
		shingle.drawOpaque();

		tableTexture.setRotation(0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		drawTables(distance, 0.0f);
		drawTables(distance, 8.163f);

		//drawTables(distance, 16.327);
	}

	distance = -6.0f;
	for (int i = 0; i < 8; i++) {


<<<<<<< HEAD
		if (i % 2) {
=======
		/*if (i % 2) {
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
			distance += 5;
		}
		else {
			distance += 6;
		}

		int j = i * 4;

		j %= 9;

		foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-19.07f, foodsHeight[j], 0.8f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
		foods[j].drawOpaque();

		j++;
		j %= 9;

		foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-19.07f + 1.648f, foodsHeight[j], 0.8f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
		foods[j].drawOpaque();

		j++;
		j %= 9;
		foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-19.07f, foodsHeight[j], 0.8f + 0.9f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
		foods[j].drawOpaque();

		j++;
		j %= 9;
		foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-19.07f + 1.648f, foodsHeight[j], 0.8f + 0.9f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
<<<<<<< HEAD
		foods[j].drawOpaque();
=======
		foods[j].drawOpaque();*/
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4

	}

	for (int i = 0; i < 14; i++) {

		int j = i % 9;

		float	distance;
		if (i % 2) {
			distance = ((i / 2) * 4.5f) + 1.648;
		}
		else {
			distance = (i / 2) * 4.5f;
		}

<<<<<<< HEAD
		foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-1.6f, foodsHeight[j], 0.44f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
		foods[j].drawOpaque();
=======
		/*foods[j].setParentModel(getModel());
		foods[j].setPosition(glm::vec3(-1.6f, foodsHeight[j], 0.44f + distance));
		foods[j].setScale(foodsScale[j]);
		foods[j].setRotation(foodsRotate[j], glm::vec3(1.0f, 0.0f, 0.0f));
		foods[j].drawOpaque();*/
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
	}



	for (int i = 0; i < 7; i++)
	{
		tableTexture.setParentModel(getModel());
		tableTexture.setRotation(90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		tableTexture.setPosition(glm::vec3(-1.1f, -1.82f, 1.274f + (i * 4.5f)));
		tableTexture.drawOpaque();

		table.setParentModel(getModel());
		table.setScale(2.049f);
		table.setPosition(glm::vec3(-1.1f, -3.29f, 0.45f + (i * 4.5f)));
		table.drawOpaque();

		table.setParentModel(getModel());
		table.setScale(2.049f);
		table.setPosition(glm::vec3(-1.1f, -3.29f, 2.098f + (i * 4.5f)));
		table.drawOpaque();

		sofa.setParentModel(getModel());
		sofa.setRotation(-90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		sofa.setScale(0.706f);
		sofa.setPosition(glm::vec3(-2.7f, -2.041f, 0.5f + (i * 4.5f)));
		sofa.drawOpaque();

		sofa.setParentModel(getModel());
		sofa.setRotation(-90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		sofa.setScale(0.706f);
		sofa.setPosition(glm::vec3(-2.7f, -2.041f, 2.148f + (i * 4.5f)));
		sofa.drawOpaque();

	}
}

void DecoratedWall::getTransparent()
{
}

void DecoratedWall::drawTables(float distance, float widthTrans) {


	tableTexture.setParentModel(getModel());
	tableTexture.setPosition(glm::vec3(-18.22f+ widthTrans, -1.82f, 1.24f + distance));
	tableTexture.drawOpaque();

	table.setParentModel(getModel());
	table.setPosition(glm::vec3(-19.048f + widthTrans, -3.290f, 1.240f + distance));
	table.setScale(2.049f);
	table.drawOpaque();

	table.setParentModel(getModel());
	table.setPosition(glm::vec3(-17.4f + widthTrans, -3.290f, 1.240f + distance));
	table.setScale(2.049f);
	table.drawOpaque();

	chair.setParentModel(getModel());
	chair.setPosition(glm::vec3(-19.5f + widthTrans, -3.290f, 0.4f + distance));
	chair.setScale(0.04f);
	chair.drawOpaque();

	chair.setParentModel(getModel());
	chair.setPosition(glm::vec3(-19.5f + widthTrans, -3.290f, 3.0f + distance));
	chair.setScale(0.04f);
	chair.drawOpaque();

	chair.setParentModel(getModel());
	chair.setPosition(glm::vec3(-17.852f + widthTrans, -3.290f, 0.4f + distance));
	chair.setScale(0.04f);
	chair.drawOpaque();

	chair.setParentModel(getModel());
	chair.setPosition(glm::vec3(-17.852f + widthTrans, -3.290f, 3.0f + distance));
	chair.setScale(0.04f);
	chair.drawOpaque();	

	plant1.setParentModel(getModel());
	plant1.setPosition(glm::vec3(-18.33f + widthTrans, -1.79f, 1.2f + distance));
	plant1.setScale(0.07f);
	plant1.drawOpaque();
}

void DecoratedWall::onImguiRender()
{
	ImGui::SliderFloat3("table x position", &m_Position.x, -100.0f, 100.0f);
	ImGui::SliderFloat3("table y position", &m_Position.y, -100.0f, 100.0f);
	ImGui::SliderFloat3("table z position", &m_Position.z, -100.0f, 100.0f);
	creepyPlant.onImguiRender();
	//ImGui::SliderFloat3("chair x position", &m_Position.x, -100.0f, 100.0f);
	//ImGui::SliderFloat3("chair y position", &m_Position.y, -100.0f, 100.0f);
	//ImGui::SliderFloat3("chair z position", &m_Position.z, -100.0f, 100.0f);
}

void DecoratedWall::setTex(Box& box, string textPath)
{
	box.setFaceTexture(Face::Up, textPath);
	box.setFaceTexture(Face::Down, textPath);
	box.setFaceTexture(Face::Back, textPath);
	box.setFaceTexture(Face::Front, textPath);
	box.setFaceTexture(Face::Left, textPath);
	box.setFaceTexture(Face::Right, textPath);
}

void DecoratedWall::fillFoods()
{
	for (int i = 1; i <= 11; ++i) {
		foods.push_back( ModelObject(
			"assets/textures/resturant/models/foods/food" + std::to_string(i) + "/scene.gltf",
			"assets/shaders/model_loading.vert",
			"assets/shaders/model_loading.frag"
		));
	}
}
