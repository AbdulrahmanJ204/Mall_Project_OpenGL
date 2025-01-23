#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include "Box.h"
#include "Cylinder.h"
class TableElectronic : public Object
{
public:
	TableElectronic();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
private:
	Box plan;
	Cylinder hwafe,rgle;
};

