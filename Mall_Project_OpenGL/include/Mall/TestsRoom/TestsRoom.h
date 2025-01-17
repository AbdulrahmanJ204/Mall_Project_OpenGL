#pragma once
#include "Object.h"
#include "ModelObject.h"
#include "LightBox.h"
#include "Cylinder.h"
#include "MovingDoor.h"
#include <Chair.h>
class TestsRoom : public Object
{
public:
	TestsRoom();
	// Inherited via Object
	void drawOpaque() override;
	void updateLights() ;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	//LightBox room;
	//LightBox temp;
	std::vector<PointLight> upperLights;
	//Chair chair;
	MovingDoor door;
	//ModelObject model;
	Cylinder cylinder;
};

