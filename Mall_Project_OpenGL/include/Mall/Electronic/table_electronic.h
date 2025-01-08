#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Box.h"
#include <Scene/Model/ModelObject.h>

class TableElectronic : public Object
{
public:
	TableElectronic();
	void drawOpaque() override;
	void drawTransparent() override;
	void onImguiRender() override;
private:
	Box plan;
	Cylinder hwafe,rgle;
	ModelObject mobile;
};

