#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>

class CaffeRoom : public Parent
{
	public:
		CaffeRoom();
		void draw() override;
		void onImguiRender() override;
		void setTex();
	private:
		Box caffe_wall_base;
};

