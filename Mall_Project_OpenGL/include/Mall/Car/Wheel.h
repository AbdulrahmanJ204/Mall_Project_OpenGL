#pragma once
#include "Object.h"
#include <objects/Cylinder.h>
class Wheel :
    public Object
{
public:
	Wheel();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Cylinder c;
};

