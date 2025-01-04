#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>

class ResturantRoom : public Parent
{
	public:
		ResturantRoom();
		void draw() override;
		void onImguiRender() override;
		void setTex();
	private:
		float x, y, z;
		Box resturant_wall_base, resturant_wall_sec;
		Box n;
};

