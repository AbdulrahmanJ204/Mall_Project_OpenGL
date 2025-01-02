#pragma once

// Debugging
#include <intrin.h> // for __debugbreak()

// Logging
#include "spdlog/spdlog.h"

// OpenGL and GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// GLM (math library)
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ImGui
#include "imGui/imgui.h"
#include "imGui/imgui_impl_glfw.h"
#include "imGui/imgui_impl_opengl3.h"

// Standard library (only essentials)
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <array>
#include <algorithm>

// Optional: Include additional headers where needed
#include "GLErrorManager.h"
#include "myImGuiManager.h"
#include "stb_image/stb_image.h" // Only include if universally required
