#pragma once
#include "Object.h"
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <ModelObject.h>
class CaffeeCounter : public Object
{
public:
	CaffeeCounter();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box firstBase;
	Box secondBase;
	Box thirdBase;
	Box firstBlock;
	Box secondBlock;
	Box thirdBlock;
	Box firstRaff;
	Box secondRaff;
	Box thirdRaff;
	Box firstRoof;
	Box secondRoof;
	Box thirdRoof;
	Box aboveCounter;
	ModelObject caffeeMachine; 

};

