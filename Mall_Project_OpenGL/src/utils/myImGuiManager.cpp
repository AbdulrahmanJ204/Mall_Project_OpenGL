#include "myImGuiManager.h"
#include <imGui/imgui_impl_opengl3.h>
#include <string>


myImGuiManager::myImGuiManager()
{
}

myImGuiManager::myImGuiManager(int width, int height)
    : m_Width(width), m_Height(height)
{
    GLFWwindow* window = glfwGetCurrentContext();
    ImGui::CreateContext();
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGuiIO& io = ImGui::GetIO();
    ImFontConfig fontConfig;
    fontConfig.SizePixels = 18.0f;
    io.Fonts->AddFontDefault(&fontConfig);
    io.Fonts->Build();

    ImGui::StyleColorsDark();
}

myImGuiManager::~myImGuiManager()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void myImGuiManager::BeginFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void myImGuiManager::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void myImGuiManager::debugV3Input(glm::vec3& vector, const char* name, float from, float to)
{
    ImGui::InputFloat3(name, (float*)&vector.x);
}

void myImGuiManager::debugV3Slider(glm::vec3& vector , const char* name , float from , float to) {
    //ImGui::Begin("MVP Controller");
    ImGui::SliderFloat3(name, &vector.x, from, to);
    //ImGui::End();
}
