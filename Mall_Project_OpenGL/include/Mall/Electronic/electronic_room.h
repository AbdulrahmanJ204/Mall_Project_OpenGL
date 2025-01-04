#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>

class ElectronicRoom : public Parent
{
	public:
		ElectronicRoom();
		void draw() override;
		void onImguiRender() override;
		void setTex();
	private:
		float x, y, z;
		Box electronic_wall_base, electronic_wall_sec;
		Box n;
};

