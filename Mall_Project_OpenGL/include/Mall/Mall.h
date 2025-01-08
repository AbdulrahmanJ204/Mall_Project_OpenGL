#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include "ResturantRoom.h"
#include "Box.h"
#include <Mall/Electronic/table_electronic.h>
class Mall : public Object
{
public:
	Mall();
	// Inherited via Object
	void drawOpaque() override;
	void drawTransparent() override;
	void onImguiRender() override;
private:

	//Cup cup;
	//Cylinder cylinder;
	//Chair chair;
	//ModelObject model;
	Box mall;
	Skybox skybox;
	ResturantRoom resturant;
	TableElectronic table;
	//chair ch;
};

