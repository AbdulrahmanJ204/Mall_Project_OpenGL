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
	
	ElectronicRoom electronicRoom;
	//chair ch;
};

