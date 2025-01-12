#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include <Mall/Electronic/table_electronic.h>
#include "Box.h"
#include "Cylinder.h"
class TV : public Object
{
public:
	TV(int type =1);
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	int type;
	Box tv;
};

