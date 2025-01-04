#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>

class LibraryRoom : public Parent
{
	public:
		LibraryRoom();
		void draw() override;
		void onImguiRender() override;
		void setTex();
	private:
		Box library_wall_base;
};

