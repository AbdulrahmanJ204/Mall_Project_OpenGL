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
	void setTex();
	// Inherited via Object
	void drawOpaque() override;
	void drawSkyBox();
	void getTransparent() override;
	void onImguiRender() override;
private:
	ModelObject model;
	Box mall;
	Skybox skybox;
	ResturantRoom resturant;
};

