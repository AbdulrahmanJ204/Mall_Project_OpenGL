#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include "Box.h"
#include "Cylinder.h"
class Buildings : public Object
{
public:
	
	Buildings();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
private:
	Box build1, build2, build3;
};

