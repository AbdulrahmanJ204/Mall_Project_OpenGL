#include"Application.h"
// Force NVIDIA GPU
extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;

// Force AMD GPU
extern "C" __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
int main() {
	std::unique_ptr<Application> app = std::make_unique<Application>() ;
	app->run();
	return 0;
}