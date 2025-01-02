#include "Window.h"
#include "Application.h"
Window* Window::instancePtr = nullptr;
int Window::s_Width = 1800;
int Window::s_Height= 900;

Window::Window(std::string title, int width , int height) :
	m_Title(title), m_Window(nullptr), m_Monitor(nullptr) , windowedWidth(width) , windowedHeight(height)
{
	if(!initGLFW() ) return;
	if(!initGLAD()) return;
	instancePtr = this;
}

Window::~Window()
{	
	instancePtr = nullptr;
	if (m_Window) {
		glfwDestroyWindow(m_Window);
	}
	glfwTerminate();
}

bool Window::initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	m_Window = glfwCreateWindow(s_Width, s_Height, m_Title.c_str(), NULL, NULL);
	if (m_Window == NULL) {
		spdlog::error("Failed to create GLFW window");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(m_Window);
	// v-sync
	glfwSwapInterval(1);
	instancePtr = this;
	m_initalized = true;
	setupCallbacks();
	return true;
}

bool Window::initGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		spdlog::error("Failed to initialize GLAD");
		return false;
	}
	return true;
}

void Window::onWindowError(int32_t errorCode, const char* description) {
	std::stringstream ss;
	ss << "GLFW: **ERROR** error=" << errorCode << " description=" << description << "\n";
	spdlog::error(ss.str());
}

void Window::onKeyEvent(GLFWwindow*, int32_t key, int32_t scancode, int32_t action, int32_t mode) {
	
	Application::instance().processDiscreteInput(key, scancode, action, mode);
}

void Window::onResized(GLFWwindow*, int32_t width, int32_t height) {
	Application& app = Application::instance();
	Window& window = app.getWindow();
	s_Width = width, s_Height = height;
	glViewport(0, 0, width, height);
	// TODO: implement onResized in Application , i think projection matrix should be updated.
	//window.setWindowHeight(height);
	//window.setWindowWidth(width);

	//app.onResized(width, height);
}

void Window::onMouseButtonEvent(GLFWwindow*, int32_t button, int32_t action, int32_t mods) {
	// TODO: implement
	//Application::instance().onMouseButtonEvent(button, action, mods);
}

void Window::onCursorPosition(GLFWwindow*, double x, double y) {
	
	Application::instance().onCursorPositionEvent(x, y);
}

void Window::onRefreshWindow(GLFWwindow*) {
	
	// TODO: implement
	//Application::instance().onRefreshWindow();
}

void Window::setupCallbacks() {
	
	glfwSetKeyCallback(m_Window, onKeyEvent);
	//glfwSetMouseButtonCallback(m_Window, onMouseButtonEvent);
	glfwSetCursorPosCallback(m_Window, onCursorPosition);
	glfwSetFramebufferSizeCallback(m_Window, onResized);
//
//#ifndef BUILD_TYPE_DIST
//	glEnable(GL_DEBUG_OUTPUT);
//	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
//	glDebugMessageCallback(onOpenGlMessage, nullptr);
//	glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
//#endif

	glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetWindowRefreshCallback(m_Window, onRefreshWindow);
	glfwSetErrorCallback(Window::onWindowError);
}

void Window::toggleFullscreen() {
	if (isFullscreen) {
		// Switch to windowed mode
		glfwSetWindowMonitor(m_Window, nullptr, windowedX, windowedY, windowedWidth, windowedHeight, 0);
		isFullscreen = false;
	}
	else {
		// Save current window position and size
		glfwGetWindowPos(m_Window, &windowedX, &windowedY);
		glfwGetWindowSize(m_Window, &windowedWidth, &windowedHeight);

		// Get the primary monitor and its video mode
		m_Monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(m_Monitor);

		// Switch to fullscreen
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		isFullscreen = true;
	}
}
