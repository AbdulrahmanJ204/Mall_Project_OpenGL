#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>
#include <Mall/Electronic/electronic_room.h>
#include <Mall/Resturant/resturant_room.h>
#include <Mall/Supermarket/supermarket_room.h>
#include <Mall/Caffe/caffe_room.h>
#include <Mall/Library/library_room.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
	void draw() override;
	void onImguiRender() override;
	void setTex();
private:
	Box skybox;
	Box plan;
	Box mall_front, mall_back,plan_mall;
	Box adadaLeft, adadaRight,floor_1;
	Cylinder adadaMiddile;

	ElectronicRoom electronicRoom;
	ResturantRoom resturantRoom;
	SupermarketRoom supermarketRoom;
	CaffeRoom caffeRoom;
	LibraryRoom libraryRoom;

	Box iteFront, iteBack;
};

