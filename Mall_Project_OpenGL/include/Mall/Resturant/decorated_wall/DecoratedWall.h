#pragma once
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <ModelObject.h>

class DecoratedWall : public Object
{
public:
	DecoratedWall();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex(Box& box, string textPath);

private:
	void drawTables(float distance , float widthTrans);
	void fillFoods();
	float frontWallWidth = 0.01f;
	float frontWallHeight = 5.08f;
	float frontWallDepth = 52.0f;


	float leftWallWidth = 29.0f;
	float leftWallHeight = 5.08f;
	float leftWallDepth = 0.01f;

	float bigFloorWidth = 20.0f;
	float bigFloorHeight= 0.01f;
	float bigFloorDepth = 52.0f;

	float smallFloorWidth = 9.0f;
	float smallFloorHeight= 0.01f;
	float smallFloorDepth = 13.5f;

	float upperWallWidth=0.6f;
	float upperWallHeight=1.0f;
	float upperWallDepth= 52.0f;

	float woodWallWidth= 0.1f;
	float woodWallHeight= 1.0f;
	float woodWallDepth = 52.0f;

	float leftUpperWallWidth = 29.0f;
	float leftUpperWallHeight = 1.0f;
	float leftUpperWallDepth = 0.6f;

	float leftWoodWallWidth = 29.0f;
	float leftWoodWallHeight = 1.0f;
	float leftWoodWallDepth = 0.1f;

	float shingleWidth = 0.1f;
	float shingleHeight = 2.0f;
	float shingleDepth = 1.0f;

	float shelfWidth = 0.3f;
	float shelfHeight = 0.1f;
	float shelfDepth = 1.0f;

	float rightWallFarHeight = 5.08f;
	float rightWallFarWidth = 20.0f;
	float rightWallFarDepth = 3.0f;

	float separateorWallHeight = 5.08f;
	float separateorWallWidth = 2.0f;
	float separateorWallDepth = 0.6f;

	float separateorWall2Height = 1.08f;
	float separateorWall2Width = 1.0f;
	float separateorWall2Depth = 0.6f;

	float separatorShingleHeight = 0.1f;
	float separatorShingleWidth = 1.0f;
	float separatorShingleDepth = 0.6f;

	float primaryPillerHeight = 0.15f;
	float primaryPillerWidth = 0.15f;
	float primaryPillerDepth = 40.5;

	float secondoryPillerHeight = 0.15f;
	float secondoryPillerWidth = 1.642f;
	float secondoryPillerDepth = 0.15f;

	std::vector<float> foodsHeight = { -1.75f, -1.75f, -1.60f, -1.75f, -1.72f ,-1.73f , -1.73f, -1.75f,-1.75f };
	std::vector<float> foodsRotate = { -90.0f, 0.0f, -90.0f, 0.0f, -90.0f,-90.0f,-90.0f,-90.0f,-90.0f };
	std::vector<float> foodsScale= { 1.0f, 0.015f, 1.0f, 0.07f, 0.012f,0.002f,0.04f,1.773f,3.753f };


	Box frontWall, leftWall,bigFloor,smallFloor, bigRoof, smallRoof, shingle, shelf, upperWall , leftUpperWall, woodWall, leftWoodWall,  separateorWall, separatorWall2 , separatorShingle;
	Box rightWallFar;
	Box primaryPiller ,secondoryPiller;

	Box tableTexture;

	ModelObject chair , table , plant1 , sofa , pot , tropicalPlant , ivy1, ivy2, ivy3 , coverPlant, creepyPlant;


	vector<ModelObject> foods;
};

