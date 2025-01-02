#pragma once
#include "core.h"
#include "Camera.h"
#include "Mall.h"

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



	static Scene* instancePtr;
private:
	
	Camera camera;
	float lastX, lastY;
	bool firstMouse;
	glm::mat4 m_Proj, m_View;
	Mall mall;
	// Could be a skyBox also  here.
};

