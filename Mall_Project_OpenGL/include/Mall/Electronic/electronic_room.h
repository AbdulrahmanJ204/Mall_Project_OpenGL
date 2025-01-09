#pragma once
#include "Object.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>
#include <Scene/Model/ModelObject.h>
#include <Mall/Electronic/table_electronic.h>

class ElectronicRoom : public Object
{
	public:
		ElectronicRoom();
		void drawOpaque() override;
		void drawTransparent() override;
		void onImguiRender() override;
		void setTex();
	private:
		float x, y, z;
		Box electronic_wall_base, electronic_wall_sec;
		Box n;
		TableElectronic table;
		
};

