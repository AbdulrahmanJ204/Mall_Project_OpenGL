#pragma once
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <Chair.h>
#include <imGui/imgui_internal.h>
#include <ModelObject.h>
#include <Mall/caffeElsaffah/Counter_seating/CaffeeCounter.h>
#include <Mall/caffeElsaffah/kanabePlusTable/KanabePlusWall.h>
class CaffeeRoom: public Object
{
public:
	CaffeeRoom();
	// Inherited via Object
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
	
private:
	Box floor;
	Box firstSideWall;
	Box secondSideWall;
	Box sakef;
	Box aboveTable;
	Kanabeh kanabe;
	Tables tables;
	WallCooffe wall;
	CaffeeCounter counter;
	KanabePlusWall oneTable;
	Box tv;
	ModelObject model;
	ModelObject lamp;
	ModelObject chair;
	ModelObject chairTable;
	ModelObject chairTable2;
	ModelObject chairTable3;
	ModelObject chairTable4;
	ModelObject coffeeMachine;
	ModelObject candles;
	ModelObject vending;
	ModelObject banda;
	Box front1;
	Box front2;
	Box front3;
	Box front4;
	Box front5;
	Box front7;

	
	
};
