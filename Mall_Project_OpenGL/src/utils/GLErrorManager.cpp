#include "GLErrorManager.h"
#include <iomanip>

#include<iostream>	

 void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}
 bool GLLogCall(const char* function, const char* file, int line) {

	while (GLenum error = glGetError()) {
		std::cout << "[OpenGl Error] (" << std::hex<< error << "): " << function << " ### " << file << " | Line : " << line << std::endl;
		return false;
	}
	return true;
}


