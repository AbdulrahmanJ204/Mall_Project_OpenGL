#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
	void draw() override;
	void onImguiRender() override;
private:

	Cup cl;
	//chair ch;
	Box skybox;
	Box plan;
	Box mall;
	Cup cup;
	Cylinder cylinder;
	Chair chair;
};

