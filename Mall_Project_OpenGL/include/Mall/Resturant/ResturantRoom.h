#pragma once
#include "Object.h"
#include "Box.h"
#include "Cylinder.h"
#include <Chair.h>
class ResturantRoom : public Object
{
public:
	ResturantRoom();
	// Inherited via Object
	void drawOpaque() override;

	void drawTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box room;
	Chair chair;
	Cylinder cylinder;
};

