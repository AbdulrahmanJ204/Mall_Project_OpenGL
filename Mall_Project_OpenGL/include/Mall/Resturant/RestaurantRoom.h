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
<<<<<<< HEAD
	//RestaurantWindow window;
=======
	RestaurantWindow window;
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
	DecoratedWall decoratedWall;
	float windowWidth;
};

