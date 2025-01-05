#pragma once
#include "Parent.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include <ResturantRoom.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
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
	//chair ch;
};

