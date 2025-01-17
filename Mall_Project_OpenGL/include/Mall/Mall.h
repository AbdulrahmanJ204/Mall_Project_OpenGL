#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include "ResturantRoom.h"
#include "Box.h"
#include <Mall/Electronic/electronic_room.h>
#include <Mall/world_plan.h>
#include <Mall/drabzen.h>
#include <Mall/Supermarket/supermarket.h>

class Mall : public Object
{
public:
	Mall();
	void setTex();
	// Inherited via Object
	void drawOpaque() override;
	void drawSkyBox();
	void getTransparent() override;
	void onImguiRender() override;
private:
//	Box mall;
	Skybox skybox;
	//ResturantRoom resturant;
	Box mall_front, mall_back,mall_wall;
	Box adadaLeft, adadaRight, floor_1,mmr, mmrCenter;
	Cylinder adadaMiddile;
	WorldPlan worldplan;
	ElectronicRoom electronicRoom;
	SupermarketRoom supermarketRoom;
	ModelObject escalator;
	//chair ch;
	Drabzen dr1, dr2, dr3, dr4;
	Drabzen dr5, dr6, dr7, dr8;
	Box market1;

};

