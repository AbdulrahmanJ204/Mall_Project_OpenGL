#pragma once
#include "Object.h"
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
class Tables : public Object
{
public:
	Tables();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box trs;
	Cylinder footTable;
	Box trs2;
};




