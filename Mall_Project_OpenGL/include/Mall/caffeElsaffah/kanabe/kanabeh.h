#pragma once
#include "Object.h"
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
class Kanabeh : public Object
{
public:
	Kanabeh();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box snnada;
	Box seat;

};


