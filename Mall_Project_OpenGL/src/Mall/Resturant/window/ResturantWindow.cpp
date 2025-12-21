#include "Resturant/window/ResturantWindow.h"

RestaurantWindow::RestaurantWindow() : Object(),
// width, height, depth
windowPiller(windowPillerWidth, windowPillerHeight, windowPillerDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
windowGlass(windowGlassWidth, windowGlassHeight, windowGlassDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
windowSill(windowSillWidth, windowSillHeight, windowSillDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"),
wallUnderWindow(wallUnderWindowWidth, wallUnderWindowHeight, wallUnderWindowDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left, { 2,1 }}, { Face::Right ,{2,1} } }),
wallAboveWindow(wallAboveWindowWidth, wallAboveWindowHeight, wallAboveWindowDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left, {2,1}}, { Face::Right ,{2,1} } }),
rightWall(rightWallWidth, rightWallHeight, rightWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Left ,{1,3}},{Face::Right ,{1,3} } }),
leftWall(leftWallWidth, leftWallHeight, leftWallDepth, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag" ,{ {Face::Left, { 1,3 }}, { Face::Right ,{1,3} } })

{
	
	setTex(windowPiller, "assets/textures/resturant/window/window2/base.png");
	setTexTransparet(windowGlass, "assets/textures/resturant/window/glass/grey_glass.png");
	setTex(windowSill, "assets/textures/resturant/window/wood/wood3/wood.png");
	setTex(wallUnderWindow, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(wallAboveWindow, "assets/textures/resturant/stones/stone9/stone.png");
	setTex(leftWall, "assets/textures/resturant/stones/stone8/stone.png");
	setTex(rightWall, "assets/textures/resturant/stones/stone8/stone.png");
	
	modifcation[0] = { glm::vec3(0.0f,0.0f, (windowPiller.getDepth() / 2)) };
	modifcation[1] = { glm::vec3(0.0f,0.0f,windowPillerHeight - (windowPiller.getDepth() / 2)) };
	modifcation[2] = {glm::vec3(0.0f,0.0f,windowPillerHeight/2)};
	modifcation[3] = { glm::vec3(0.0f,0.0f,windowPillerHeight/2),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1,0,0),90 };
	modifcation[4] = { glm::vec3(0.0f,-(windowPillerHeight / 2) + (windowPillerDepth / 2),windowPillerHeight / 2),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1,0,0),90 };
	modifcation[5] = { glm::vec3(0.0f,(windowPillerHeight / 2 )- (windowPillerDepth / 2),windowPillerHeight / 2),glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1,0,0),90 };
	wallAboveWindow.setPosition(glm::vec3(0.0f, +(windowPillerHeight / 2) + (windowPillerDepth / 2)+(wallAboveWindowHeight /2) + (windowSillHeight/2), windowPillerHeight / 2));
	wallUnderWindow.setPosition(glm::vec3(0.0f, -(windowPillerHeight / 2) - (windowPillerDepth / 2) - (wallUnderWindowHeight / 2) - (windowSillHeight / 2), windowPillerHeight / 2));
	rightWall.setPosition(glm::vec3(0.0f, -((wallUnderWindowHeight - wallAboveWindowHeight) / 2), -(rightWallDepth / 2)));
	leftWall.setPosition(glm::vec3(0.0f, -((wallUnderWindowHeight - wallAboveWindowHeight) / 2),(windowPillerHeight)+(leftWallDepth/2)));
<<<<<<< HEAD

=======
	
>>>>>>> ecb8ae7b0bcd20c4e32f5f6ae0ba049f21c8a0f4
}

void RestaurantWindow::drawOpaque()
{


	for (int i = 0; i < 6; i++)
	{
		windowPiller.setParentModel(getModel());
		windowPiller.setRotation(modifcation[i].rotateDegree, modifcation[i].rotate);
		windowPiller.setPosition(modifcation[i].translate);
		windowPiller.setScale(modifcation[i].scale);
		windowPiller.drawOpaque();
	}
	windowGlass.setParentModel(getModel());
	windowGlass.setPosition(glm::vec3(0.0f, 0.0f, windowPillerHeight / 2));
	windowGlass.drawOpaque();

	

	windowSill.setParentModel(getModel());
	windowSill.setPosition(glm::vec3(0.0f, -(windowPillerHeight / 2) - (windowPillerDepth / 2), windowPillerHeight / 2));
	windowSill.drawOpaque();

	windowSill.setParentModel(getModel());
	windowSill.setPosition(glm::vec3(0.0f, (windowPillerHeight / 2) + (windowPillerDepth / 2), windowPillerHeight / 2));
	windowSill.drawOpaque();


	wallUnderWindow.setParentModel(getModel());
	wallUnderWindow.drawOpaque();


	wallAboveWindow.setParentModel(getModel());
	wallAboveWindow.drawOpaque();

	rightWall.setParentModel(getModel());
	rightWall.drawOpaque();


	leftWall.setParentModel(getModel());
	leftWall.drawOpaque();

}

void RestaurantWindow::getTransparent()
{
	windowGlass.setParentModel(getModel());
	windowGlass.setPosition(glm::vec3(0.0f, 0.0f, windowPillerHeight / 2));
	windowGlass.getTransparent();
}

void RestaurantWindow::onImguiRender()
{
	//ImGui::SliderFloat3("TableElectronic rotate ", &anglr, 0.0f, 360.0f);
}

float RestaurantWindow::getWindowWidth()
{
	return windowPillerHeight + rightWallDepth + leftWallDepth;
}

void RestaurantWindow::setTex(Box& box,string textPath)
{
	box.setFaceTexture(Face::Up, textPath);
	box.setFaceTexture(Face::Down, textPath);
	box.setFaceTexture(Face::Back, textPath);
	box.setFaceTexture(Face::Front, textPath);
	box.setFaceTexture(Face::Left, textPath);
	box.setFaceTexture(Face::Right, textPath);
}

void RestaurantWindow::setTexTransparet(Box& box, string textPath)
{
	box.setFaceTexture(Face::Up, textPath, true);
	box.setFaceTexture(Face::Down, textPath, true);
	box.setFaceTexture(Face::Back, textPath, true);
	box.setFaceTexture(Face::Front, textPath, true);
	box.setFaceTexture(Face::Left, textPath, true);
	box.setFaceTexture(Face::Right, textPath, true);
}
