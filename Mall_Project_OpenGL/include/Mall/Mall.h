#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Cup.h"
#include "ResturantRoom.h"
#include "Box.h"
#include "ModelObject.h"
class Mall : public Object
{
public:
	Mall();
	// Inherited via Object
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
private:

	//Cup cup;
	//Cylinder cylinder;
	//Chair chair;
	Texture defaultTex;
	ModelObject model;
	Box mall;
	Skybox skybox;
	ResturantRoom resturant;
	//chair ch;
};

