#pragma once
#include "core.h"
#include "Box.h"
#include "Cylinder.h"

class Parent
{
public:
	Parent() :
		m_Model(1.0f), m_ParentModel(1.0f),
		m_RotationAngle(0.0f), m_Position(0.0f),
		m_RotationAxis(0.0f, 1.0f, 0.0f) , m_Scale(1.0f){
	};
	~Parent() {};
	virtual void draw() = 0;
	virtual void onImguiRender() {}; // For debugging.
	void setParentModel(glm::mat4 pModel);
	void setPosition(const glm::vec3& position);
	void setRotation(float angle, const glm::vec3& axis);
	void setScale(const glm::vec3& scale);
	void updateModelMatrix();
	glm::mat4 getModel();
	glm::mat4 m_Model, m_ParentModel;
	glm::vec3 m_Position, m_Scale, m_RotationAxis;
	float m_RotationAngle;

};

