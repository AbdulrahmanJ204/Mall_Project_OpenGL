#pragma once
#include "core.h"
#include "Box.h"

class Parent
{
public:
	Parent() :model(1.0f), parentModel(1.0f) {};
	~Parent() {};
	virtual void draw() = 0;
	void translate(glm::vec3 pos);
	void rotate(float angle , glm::vec3 axis);
	void scale(float factor, glm::vec3 axis);
	void setParentModel(glm::mat4 pModel);
	glm::mat4 getModel();
	glm::mat4  model, parentModel; ;
};

