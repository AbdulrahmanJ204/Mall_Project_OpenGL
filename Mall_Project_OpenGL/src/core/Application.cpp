#include"Application.h"
#include "Window.h"
Application* Application::instancePtr = nullptr;

Application::Application() :
	deltaTime(0.0f), lastFrame(0.0f),
	window("Mall", Window::getWidth(), Window::getHeight()),
	myImGui(Window::getWidth(), Window::getHeight())
{
	spdlog::info("Starting Application");
	instancePtr = this;
}

Application::~Application()
{

	instancePtr = nullptr;
}

void Application::run() {


	SetupBasics();
	while (!window.shouldClose()) {

		Clear();
		UpdateDeltaTime();
		processContinuousInput();
		scene.draw();
		glfwPollEvents();
		//LoadImGui();
		window.swapBuffers();
	}

}

void Application::SetupBasics()
{
	GLCall(glEnable(GL_DEPTH_TEST));
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void Application::Clear()
{
	GLCall(glClearColor(0.1f, 0.1f, 0.1f, 1.0f));
	GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void Application::UpdateDeltaTime()
{
	float currentFrame = static_cast<float>(glfwGetTime());
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;
}

void Application::LoadImGui()
{

	glfwMakeContextCurrent(glfwGetCurrentContext());
	myImGui.BeginFrame();
	//ImGui::SliderFloat("Cube Rotation ", &scene.getRotation(), 0.0f, 360.0f);
	myImGui.EndFrame();
}

void Application::processContinuousInput()
{
	scene.processContinuousInput(deltaTime);
}

void Application::processDiscreteInput(int32_t key, int32_t scancode, int32_t action, int32_t mode) {

	scene.processDiscreteInput(key, scancode, action, mode, deltaTime);
}

void Application::onCursorPositionEvent(double xposIn, double yposIn) {
	scene.onCursorPositionEvent(xposIn, yposIn);
}

float Application::getRandom()
{
	return (float)(rand() % 100) / 100;
}
