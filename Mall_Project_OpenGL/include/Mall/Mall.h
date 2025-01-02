#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <cup.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
	void draw() override;
	void setTex();
private:

	//Cup cl;
	//chair ch;
	Box skybox;
	Box plan;
	Box mall;
};

