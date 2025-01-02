#pragma once
#include "core.h"
#include "Box.h"

class Parent
{
public:
	Parent() :model(1.0f), parentModel(1.0f) {};
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
	};
	void setParentModel(glm::mat4 pModel) {
		parentModel = pModel;
	};
	glm::mat4 getModel() {
		// TODO: Check if order is correct .
		return model * parentModel;
	};
	glm::mat4  model, parentModel; ;
};

