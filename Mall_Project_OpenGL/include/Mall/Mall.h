#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
	void draw() override;
private:
	Cylinder cl;
};

