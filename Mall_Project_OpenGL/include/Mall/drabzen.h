#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include "Box.h"
#include "Cylinder.h"
class Drabzen : public Object
{
public:

	Drabzen(float width);
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
private:
	Box blor;
	Cylinder amod;
};

