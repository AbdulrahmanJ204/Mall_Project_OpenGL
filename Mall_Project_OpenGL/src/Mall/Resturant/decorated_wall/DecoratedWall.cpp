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
woodWall(woodWallWidth, woodWallHeight, woodWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left,{22,1}},{Face::Right,{22,1}} }),

leftUpperWall(leftUpperWallWidth, leftUpperWallHeight, leftUpperWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
leftWoodWall(leftWoodWallWidth, leftWoodWallHeight, leftWoodWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Front,{14,1}},{Face::Back,{14,1}} }),
shingle(shingleWidth, shingleHeight, shingleDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
shelf(shelfWidth, shelfHeight, shelfDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
chair("assets/textures/resturant/models/chairs/backless_chair/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag"),
table("assets/textures/resturant/models/chairs/high_table/source/Unity2Skfb/Unity2Skfb.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag")
{
	setTex(frontWall, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(leftWall, "assets/textures/resturant/stones/stone8/stone.png");

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


	frontWall.setPosition(glm::vec3(-20, -0.76, (frontWallDepth / 2) - 7-1.16));
	leftWall.setPosition(glm::vec3(-20+leftWallWidth/2, -0.76,45-1.16));
	upperWall.setPosition(glm::vec3(-20 + (upperWallWidth / 2), 1.8f - (upperWallHeight / 2), (upperWallDepth / 2) - 7 - 1.16));
	woodWall.setPosition(glm::vec3(-20 + (upperWallWidth ) + (woodWallWidth/2), 1.8f - (woodWallHeight / 2), (woodWallDepth / 2) - 7 - 1.16));

	leftUpperWall.setPosition(glm::vec3(-20 + leftWallWidth / 2, 1.8f - (leftUpperWallHeight / 2), 45 - 1.16 - (leftUpperWallDepth / 2)));
	leftWoodWall.setPosition(glm::vec3(-20 + leftWallWidth / 2, 1.8f - (leftWoodWallHeight /2), 45 - 1.16 - leftUpperWallDepth - (leftWoodWallDepth/2)));

	bigFloor.setPosition(glm::vec3(-10, -3.29, (bigFloorDepth / 2) - 7 - 1.16));
	smallFloor.setPosition(glm::vec3(smallFloorWidth / 2, -3.29, (smallFloorDepth / 2) + 31.5 - 1));
	bigRoof.setPosition(glm::vec3(-10, 1.8f, (bigFloorDepth / 2) - 7 - 1.16));
	smallRoof.setPosition(glm::vec3(smallFloorWidth / 2, 1.8f, (smallFloorDepth / 2) + 31.5 - 1));

	//chair.setPosition(glm::vec3(-20 + (upperWallWidth / 2), -2 , 0));
	//table.setPosition(glm::vec3(-20 + (upperWallWidth / 2), -2, 0));

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

	float distance = -6;
	for (int i = 0; i < 8; i++)
	{
		if (i % 2) {
			distance += 5;
		}
		else {
			distance += 6;
		}

		shelf.setParentModel(getModel());
		shelf.setPosition(glm::vec3(-20 +  shingleWidth + (shelfWidth/2), -0.75 + (shingleHeight/2) - 0.25 , 1.25 + distance));
		shelf.drawOpaque();

		table.setParentModel(getModel());
		table.setPosition(glm::vec3(-19.048, -3.290, 1.240+ distance));
		table.setScale(2.049);
		table.drawOpaque();

		chair.setParentModel(getModel());
		chair.setPosition(glm::vec3(-19.5, -3.290, 0.4 + distance));
		chair.setScale(0.04);
		chair.drawOpaque();

		chair.setParentModel(getModel());
		chair.setPosition(glm::vec3(-19.5, -3.290, 3 + distance));
		chair.setScale(0.04);
		chair.drawOpaque();

		chair.setParentModel(getModel());
		chair.setPosition(glm::vec3(-17.852, -3.290, 0.4 + distance));
		chair.setScale(0.04);
		chair.drawOpaque();

		chair.setParentModel(getModel());
		chair.setPosition(glm::vec3(-17.852, -3.290, 3 + distance));
		chair.setScale(0.04);
		chair.drawOpaque();


		shingle.setParentModel(getModel());
		shingle.setPosition(glm::vec3(-20 + (shingleWidth / 2), -0.75, 1.25 + distance));
		shingle.drawOpaque();

		table.setParentModel(getModel());
		table.setPosition(glm::vec3(-17.4, -3.290, 1.240 + distance));
		table.setScale(2.049);
		table.drawOpaque();


	}


}

void DecoratedWall::getTransparent()
{
}

void DecoratedWall::onImguiRender()
{
	ImGui::SliderFloat3("table x position", &m_Position.x, -100.0f, 100.0f);
	ImGui::SliderFloat3("table y position", &m_Position.y, -100.0f, 100.0f);
	ImGui::SliderFloat3("table z position", &m_Position.z, -100.0f, 100.0f);
	//chair.onImguiRender();
	table.onImguiRender();



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
