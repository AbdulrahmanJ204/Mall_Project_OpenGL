#pragma once
#include "core.h"
#include "SkyBox.h"
class Object
{
public:
	Object() :
		m_Model(1.0f), m_ParentModel(1.0f),
		m_RotationAngle(0.0f), m_Position(0.0f),
		m_RotationAxis(0.0f, 1.0f, 0.0f) , m_UniformScale(1.0f) , m_NonUniformScale(1.0f), m_Center(0.0f) {
	};
	~Object() {};
	virtual void drawOpaque() = 0;
	virtual void drawTransparent() {};
	virtual void getTransparent() = 0;
	virtual void onImguiRender() {}; // For debugging.
	void setParentModel(glm::mat4 pModel);
	void setPosition(const glm::vec3& position);
	void setRotation(float angle, const glm::vec3& axis);
	void setScale(const glm::vec3& scale);
	void setScale(const float& scale);
	void updateModelMatrix();
	glm::vec3 getModifiedPosition();
	glm::mat4 getModel();
	glm::mat4 m_Model, m_ParentModel;
	glm::vec3 m_Position, m_NonUniformScale, m_RotationAxis,m_Center;
	float m_RotationAngle, m_UniformScale;
};

