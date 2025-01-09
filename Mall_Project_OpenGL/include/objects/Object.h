#pragma once
#include "core.h"
#include "SkyBox.h"

class Object
{
public:
	Object() :
		m_Model(1.0f), m_ParentModel(1.0f),
		m_RotationAngle(0.0f), m_Position(0.0f),
		m_RotationAxis(0.0f, 1.0f, 0.0f), m_UniformScale(1.0f), m_NonUniformScale(1.0f), m_Center(0.0f),
		m_TargetPosition(0.0f), m_TargetRotationAxis(0.0f, 1.0f, 0.0f), m_TargetRotationAngle(0.0f),
		m_TargetScale(1.0f)
	{
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
	void setTargetPosition(const glm::vec3& targetPosition);
	glm::mat4 m_Model, m_ParentModel;
	glm::vec3 m_Position, m_NonUniformScale, m_RotationAxis, m_Center;
	float m_RotationAngle, m_UniformScale;

	// Add target state variables
	glm::vec3 m_TargetPosition;
	glm::vec3 m_TargetRotationAxis;
	float m_TargetRotationAngle;
	glm::vec3 m_TargetScale;

	// Speed of interpolation (units per second)
	float m_MoveSpeed = 0.01f;
	float m_RotateSpeed = 45.0f; // Degrees per second
	float m_ScaleSpeed = 1.0f;

	void setTargetRotation(float targetAngle, const glm::vec3& targetAxis);

	void setTargetScale(const glm::vec3& targetScale);

	// Add a function to update the object's state over time
	void update();
};

