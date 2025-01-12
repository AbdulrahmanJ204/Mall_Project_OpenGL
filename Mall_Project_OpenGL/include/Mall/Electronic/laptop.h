#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include <Mall/Electronic/table_electronic.h>
#include "Box.h"
#include "Cylinder.h"
class Laptop : public Object
{
public:
	Laptop(int type = 1);
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	int type;
	Box laptop_back,laptop_front;
};

