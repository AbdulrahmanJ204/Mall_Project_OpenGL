#pragma once
#include "core.h"
#include "Cube.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
class Application {
public:


	Application();
	~Application();

	void run();
	void onCursorPositionEvent(double x, double y);
	void processDiscreteInput(int32_t key, int32_t scancode, int32_t action, int32_t mode);
	void processContinuousInput();

	Window& getWindow() { return window; };

	static Application& instance() { return *instancePtr; };

	static Application* instancePtr;
private:
	
	Window window;
	Scene scene;
	myImGuiManager myImGui;
	float deltaTime, lastFrame;

	void LoadImGui();
	void SetupBasics();
	void Clear();
	void UpdateDeltaTime();

	float getRandom();
};