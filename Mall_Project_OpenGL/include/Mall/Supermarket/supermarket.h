#pragma once
#include "Object.h"
#include <Scene/Model/ModelObject.h>
#include <Mall/Electronic/table_electronic.h>
#include "Box.h"
#include "Cylinder.h"
#include <Mall/Electronic/tv.h>
#include <Mall/Electronic/laptop.h>
class SupermarketRoom : public Object
{
public:
	SupermarketRoom();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	void setTex();
private:
	Box wall_base, wall_sec,wall_front,wall_enter;
	Box arma;
	ModelObject registerCach,cart;
	vector<Box> rafs;
	vector<Box> brad;
};

