#pragma once
#include "core.h"
#include "Camera.h"
#include "Object.h"
#include "Mall.h"
#include "Window.h"
#include <set>
class Scene
{
public:
	Scene();
	~Scene();
	void draw();
	void drawTransparent();
	inline glm::vec3& getCameraPosition() { return camera.Position; }
	inline Camera& getCamera() { return camera; };

	void onCursorPositionEvent(double x, double y);
	void processDiscreteInput(int32_t key, int32_t scancode, int32_t action, int32_t mode, float deltaTime);
	void processContinuousInput(float& deltaTime);
	void onImguiRender();
	static Scene* instancePtr;
	static glm::mat4 s_Proj;
	static void updateProj() {
		s_Proj = glm::perspective(glm::radians(45.0f), (float)Window::getWidth() / Window::getHeight(), 0.1f, 1000.0f);
	}
	//static std::set <std::pair<Object*, std::tuple<float , float ,float>>> objectsSet;
	static std::vector<Object*> transparentObjects;
	static std::vector<glm::vec3> transparentPositions;
	static void addTransparent(Object* obj , glm::vec3& pos) {
		transparentObjects.emplace_back(obj);
		transparentPositions.emplace_back(pos);
		//objectsSet.insert(std::make_pair(obj, std::make_tuple(pos.x , pos.y , pos.z)));
	}
	static glm::mat4 getView() { return camera.GetViewMatrix(); };
	static glm::mat4 getProjection() { return s_Proj; };
	static Camera camera;
private:
	
	float lastX, lastY;
	bool firstMouse;
	Mall mall;
	bool m_GotTransparent = false;
	// Could be a skyBox also  here.
};

