#pragma once
#include "Object.h"
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <Mall/caffeElsaffah/coffeTable/Tables.h>
#include <Mall/caffeElsaffah/kanabe/kanabeh.h>
#include <Mall/caffeElsaffah/coffeeWall/WallCooffe.h>

class KanabePlusWall : public Object
{
public:
	KanabePlusWall();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Kanabeh k1;
	WallCooffe w1;
	Kanabeh k2;
	Tables table;
};

