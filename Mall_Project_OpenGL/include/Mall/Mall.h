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
	void setTex();
private:
	Box skybox;
	Box plan;
	Box mall;
	Cup cup;
	Cylinder cylinder;
	Chair chair;
};

