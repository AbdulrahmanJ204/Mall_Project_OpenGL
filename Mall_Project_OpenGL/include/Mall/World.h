#pragma once
#include "Object.h"
#include "Cylinder.h"
#include "Chair.h"
#include "Box.h"
#include <Mall/Electronic/electronic_room.h>
#include <Mall/world_plan.h>
#include <Mall/drabzen.h>
#include <Mall/Supermarket/supermarket.h>
#include <Mall/Resturant/RestaurantRoom.h>
#include <Mall/Library/LibraryRoom.h>
#include <Mall/caffeElsaffah/CaffeeRoom.h>
#include <MovingDoor.h>
#include <Mall/Car/Wheel.h>

class World : public Object
{
public:
	World();
	void setTex();
	// Inherited via Object
	void drawOpaque() override;
	void drawSkyBox();
	void getTransparent() override;
	void onImguiRender() override;
	Skybox skybox;
	Wheel wheel;

};

