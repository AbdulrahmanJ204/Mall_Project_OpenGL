#pragma once
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <ModelObject.h>
class RestaurantWindow : public Object
{
public:
	RestaurantWindow();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	float getWindowWidth();
private:
	void setTex(Box& box, string textPath);
	void setTexTransparet(Box& box, string textPath);


	float windowPillerHeight = 2.5f;
	float windowPillerWidth = 0.08f;
	float windowPillerDepth = 0.04f;

	float windowGlassHeight= windowPillerHeight;
	float windowGlassWidth= windowPillerWidth/2;
	float windowGlassDepth = windowPillerHeight - (windowPillerDepth * 2) - 0.01f;

	float windowSillHeight = windowPillerDepth;
	float windowSillWidth = windowPillerWidth + 0.40f;
	float windowSillDepth = windowPillerHeight;

	float wallUnderWindowHeight= 2.0f;
	float wallUnderWindowWidth= windowSillWidth - 0.16f;
	float wallUnderWindowDepth= windowPillerHeight;
	
	float wallAboveWindowHeight=0.5f;
	float wallAboveWindowWidth= wallUnderWindowWidth;
	float wallAboveWindowDepth = windowPillerHeight;

	float leftWallHeight = windowPillerHeight + (windowSillHeight * 2)+wallUnderWindowHeight+wallAboveWindowHeight;
	float leftWallWidth= wallUnderWindowWidth;
	float leftWallDepth = 1.0f;

	float rightWallHeight = windowPillerHeight + (windowSillHeight * 2) + wallUnderWindowHeight + wallAboveWindowHeight;
	float rightWallWidth = wallUnderWindowWidth;
	float rightWallDepth = 1.0f;

	//Box leftWall, backWall, bigRoomFrontWall,smallRoomFrontWall, bigRoomRightWall, smallRoomRightWall,bigRoomFloor,smallRoomFloor,bigRoomRoof,smallRoomRoof;
	//ModelObject model;
	//int xtranslation = 0;
	//float anglr;
	Box windowPiller;
	Box windowGlass,windowSill;
	Box wallUnderWindow, wallAboveWindow;
	Box leftWall, rightWall;

	struct Modification {
		glm::vec3 translate = glm::vec3(0.0f, 0.0f, 0.0f);  // First vec3
		glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);  // Second vec3
		glm::vec3 rotate = glm::vec3(1.0f, 0.0f, 0.0f);  // third vec3
		float rotateDegree = 0.0f;
	};

	Modification modifcation[6];
};

