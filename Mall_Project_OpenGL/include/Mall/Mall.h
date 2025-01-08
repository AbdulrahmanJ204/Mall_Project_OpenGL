#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include "ResturantRoom.h"
#include "Box.h"
#include <Mall/Electronic/electronic_room.h>
#include <Mall/Resturant/resturant_room.h>
#include <Mall/Supermarket/supermarket_room.h>
#include <Mall/Caffe/caffe_room.h>
#include <Mall/Library/library_room.h>
class Mall : public Object
{
public:
	Mall();
	// Inherited via Object
	void drawOpaque() override;
	void drawTransparent() override;
	void onImguiRender() override;
	void setTex();
private:

	Cup cup;
	Cylinder cylinder;
	Chair chair;
	//chair ch;
	Box skybox;
	Box plan;
	Box mall_front, mall_back,plan_mall;
	Box adadaLeft, adadaRight,floor_1;
	Cylinder adadaMiddile;

	ElectronicRoom electronicRoom;
	ResturantRoom resturantRoom;
	SupermarketRoom supermarketRoom;
	CaffeRoom caffeRoom;
};

