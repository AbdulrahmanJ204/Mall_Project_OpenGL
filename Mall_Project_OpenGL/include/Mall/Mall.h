#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include "ResturantRoom.h"
#include "Box.h"
#include <Mall/Electronic/electronic_room.h>

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

	Box mall;
	Skybox skybox;
	ResturantRoom resturant;
	
	//chair ch;
	Box plan;
	Box mall_front, mall_back,plan_mall;
	Box adadaLeft, adadaRight,floor_1;
	Cylinder adadaMiddile;

	Box iteBack, iteFront;
	/*ElectronicRoom electronicRoom;
	ResturantRoom resturantRoom;
	SupermarketRoom supermarketRoom;
	CaffeRoom caffeRoom;*/
};

