#pragma once
#include "core.h"
#include "Box.h"
//class Box;

class Parent
{
public:
	Parent() :m_View(1.0f),
		m_Projection(1.0f),
		model(1.0f) {
	};
	~Parent() {};
	virtual void draw() = 0;
	void translate(glm::vec3 pos) {
		model = glm::translate(model, pos);
	};
	void rotate(float angle , glm::vec3 axis) {
		model = glm::rotate(model, glm::radians(angle), axis);
	}

	;
	void scale(float factor, glm::vec3 axis) {
		glm::vec3 scale1 = factor * axis;
		model = glm::scale(model, scale1);
	}
	;
	void setProjection(glm::mat4 proj) {
		m_Projection = proj;
	};
	void setView(glm::mat4 view) {
		m_View = view;

	};
	glm::mat4  model ,m_View , m_Projection;
};

