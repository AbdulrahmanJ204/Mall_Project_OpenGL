#pragma once
#include "Parent.h"
#include <chair.h>
#include <Cylinder.h>
#include <Cup.h>
class Mall : public Parent
{
public:
	Mall();
	// Inherited via Parent
	void draw() override;
	void onImguiRender() override {
		ImGui::SliderFloat("Mall Rotation ", &m_RotationAngle, 0.0f, 360.0f);
	};
private:

	Cup cup;
	Cylinder cylinder;
	Chair chair;
	//chair ch;
};

