#pragma once
#include "core.h"
#include "Camera.h"
#include "Object.h"
#include "Mall.h"
#include "Library/board.h" 
#include "Library/book.h" 

#include "Window.h"
class Scene
{
public:
	Scene();
	~Scene();
	void draw();
	inline glm::vec3& getCameraPosition() { return camera.Position; }
	inline Camera& getCamera() { return camera; };

	void onCursorPositionEvent(double x, double y);
	void processDiscreteInput(int32_t key, int32_t scancode, int32_t action, int32_t mode, float deltaTime);
	void processContinuousInput(float& deltaTime);
	void onImguiRender();
	static Scene* instancePtr;
	static glm::mat4 s_Proj;

	static glm::mat4 getView() { return camera.GetViewMatrix(); };
	static glm::mat4 getProjection() { return s_Proj; };
	static Camera camera;
private:
	
	float lastX, lastY;
	bool firstMouse;
	Mall mall;
	// Could be a skyBox also  here.
};

