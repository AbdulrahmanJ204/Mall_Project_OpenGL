#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include "Box.h"
#include "Cylinder.h"
#include <Mall/buildings.h>
class WorldPlan : public Object
{
public:
	WorldPlan();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
private:
	Box plan1;
	Box plan2, plan3, plan4;
	Cylinder plan5;
	ModelObject bahra;

	Box street1, street2;
	Box mall;
	Box ite1;
	Buildings buildings;
};

