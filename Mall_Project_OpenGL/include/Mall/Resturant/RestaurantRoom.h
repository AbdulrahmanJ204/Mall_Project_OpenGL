#pragma once
#include <window/ResturantWindow.h>
#include <decorated_wall/DecoratedWall.h>

class RestaurantRoom : public Object
{
public:
	RestaurantRoom();
	void drawOpaque() override;
	void getTransparent() override;
	void onImguiRender() override;
	//void setTex(Box& box, string textPath);
private:
	RestaurantWindow window;
	DecoratedWall decoratedWall;
	float windowWidth;
};

