#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include <Mall/Electronic/table_electronic.h>
#include "Box.h"
#include "Cylinder.h"
#include <Mall/Electronic/tv.h>
#include <Mall/Electronic/laptop.h>
class ElectronicRoom : public Object
{
	public:
		ElectronicRoom();
		void drawOpaque() override;
		void getTransparent() override;
		void onImguiRender() override;
		void setTex();
	private:
		Box electronic_wall_base, electronic_wall_sec,wall_front1,arma1, arma2;
		TableElectronic table;
		vector<TV> tvs;
		Laptop laptop1, laptop2;
		ModelObject washing_machine;
		Cylinder tableC1, tableC2;
		Box raf,stand1, mobile,tstand1, tstand2;
};

