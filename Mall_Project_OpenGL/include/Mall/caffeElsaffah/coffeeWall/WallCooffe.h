#pragma once
#include "Object.h"
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
class WallCooffe : public Object
{
public:
	WallCooffe();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Cylinder sykh;
	Box underSykh;
	
};
