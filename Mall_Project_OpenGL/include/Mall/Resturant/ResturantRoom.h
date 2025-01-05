#pragma once
#include "Parent.h"
#include <Chair.h>
class ResturantRoom : public Parent
{
public:
	ResturantRoom();
	// Inherited via Parent
	void drawOpaque() override;

	void drawTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box room;
	Chair chair;
	Cylinder cylinder;
};

