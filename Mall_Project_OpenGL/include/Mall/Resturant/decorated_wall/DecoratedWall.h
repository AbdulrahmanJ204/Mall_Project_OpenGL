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
	float frontWallWidth = 0.01;
	float frontWallHeight = 5.08;
	float frontWallDepth = 52;


	float leftWallWidth = 29;
	float leftWallHeight = 5.08;
	float leftWallDepth = 0.01;

	float bigFloorWidth = 20;
	float bigFloorHeight= 0.01;
	float bigFloorDepth = 52;

	float smallFloorWidth = 9;
	float smallFloorHeight= 0.01;
	float smallFloorDepth = 13.5;

	float upperWallWidth=0.6;
	float upperWallHeight=1;
	float upperWallDepth= 52;

	float woodWallWidth= 0.1;
	float woodWallHeight= 1;
	float woodWallDepth = 52;

	float leftUpperWallWidth = 29;
	float leftUpperWallHeight = 1;
	float leftUpperWallDepth = 0.6;

	float leftWoodWallWidth = 29;
	float leftWoodWallHeight = 1;
	float leftWoodWallDepth = 0.1;

	float shingleWidth = 0.1;
	float shingleHeight = 2;
	float shingleDepth = 1;

	float shelfWidth = 0.3;
	float shelfHeight = 0.1;
	float shelfDepth = 1.0;

	Box frontWall, leftWall,bigFloor,smallFloor, bigRoof, smallRoof, shingle, shelf, upperWall , leftUpperWall, woodWall, leftWoodWall,  separateorWall, separatorWall2;
};

