#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>

class SupermarketRoom : public Parent
{
	public:
		SupermarketRoom();
		void draw() override;
		void onImguiRender() override;
		void setTex();
	private:
		float x, y, z;
		Box supermarket_wall_base, supermarket_wall_sec, supermarket_wall_thi;
		Box n;
};

