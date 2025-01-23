#include "RestaurantRoom.h"

RestaurantRoom::RestaurantRoom() : Object(),
window(), decoratedWall()
{
	windowWidth = window.getWindowWidth();
	setScale(glm::vec3(1.0f, 3.0f, 1.0f));

}

void RestaurantRoom::drawOpaque()
{
	/*for (int i = 0; i < floor(35 / windowWidth); i++)
	{
		window.setParentModel(getModel());
		window.setPosition(glm::vec3(0.0f, 0.0f, windowWidth*i));
		window.setRotation(0, glm::vec3(0.0f, 1.0f, 0.0f));
		window.drawOpaque();
	}
	for (int i = 0; i < floor(10 / windowWidth); i++)
	{
		window.setPosition(glm::vec3(1.16f + (windowWidth * i), 0.0f, (windowWidth * (floor(35 / windowWidth)-1)) + (windowWidth / 2) + 1.08));
		window.setRotation(90, glm::vec3(0.0f, 1.0f, 0.0f));
		window.drawOpaque();
	}

	for (int i = floor(35 / windowWidth); i < floor(35 / windowWidth) + floor(15 / windowWidth); i++)
	{
		window.setRotation(0, glm::vec3(0.0f, 1.0f, 0.0f));
		window.setPosition(glm::vec3(windowWidth * floor(10 / windowWidth), 0.0f, (windowWidth * i)));
		window.drawOpaque();
	}*/
	decoratedWall.setParentModel(getModel());
	decoratedWall.drawOpaque();
}

void RestaurantRoom::getTransparent()
{
	window.getTransparent();
}

void RestaurantRoom::onImguiRender()
{
	decoratedWall.onImguiRender();
}

//void RestaurantRoom::setTex(Box& box, string textPath)
//{
//}
