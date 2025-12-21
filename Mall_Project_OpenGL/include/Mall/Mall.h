#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Box.h"
#include <Mall/Electronic/electronic_room.h>
#include <Mall/world_plan.h>
#include <Mall/drabzen.h>
#include <Mall/Supermarket/supermarket.h>
#include <Mall/Resturant/RestaurantRoom.h>
#include <Mall/Library/LibraryRoom.h>
#include <Mall/caffeElsaffah/CaffeeRoom.h>
#include <MovingDoor.h>

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
	//RestaurantRoom resturant;
	Box mall_front, mall_back,mall_wall1, mall_wall2, mall_wall3;
	Box adadaLeft, adadaRight, floor_1,mmr, mmrCenter;
	Cylinder adadaMiddile;
	WorldPlan worldplan;
	ElectronicRoom electronicRoom;
	SupermarketRoom supermarketRoom;
	LibraryRoom libraryRoom;
	CaffeeRoom caffeeRoom;
	//RestaurantRoom restaurant;

	ModelObject bahra, escalator;
	MovingDoor doorMall;
	//chair ch;
	Drabzen dr1, dr2, dr3, dr4;
	Drabzen dr5, dr6, dr7, dr8;
	Box market1;
	Box darag1;
	Box mosaad1, mosaad2;

};

