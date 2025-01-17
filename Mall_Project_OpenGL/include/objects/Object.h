#pragma once
#include "core.h"
#include "PointLight.h"
#include "SkyBox.h"

enum Face {
	Back,
	Front,
	Left,
	Right,
	Up,
	Down,
};
#define faceRepeatMap std::map<Face, std::pair<int, int>>

class Object
{
public:
	Object() :
		m_Model(1.0f), m_ParentModel(1.0f),
		m_RotationAngle(0.0f), m_Position(0.0f),
		m_RotationAxis(1.0f), m_UniformScale(1.0f), m_NonUniformScale(1.0f), m_Center(0.0f),
		m_RotationMatrixX(1.0f),
		m_RotationMatrixY(1.0f),
		m_RotationMatrixZ(1.0f),
		m_TargetPosition(0.0f), m_TargetRotationAxis(0.0f, 1.0f, 0.0f), m_TargetRotationAngle(0.0f),
		m_TargetScale(1.0f)
	{
	};
	~Object() {};
	virtual void drawOpaque() = 0;
	virtual void drawTransparent() {};
	virtual void getTransparent() = 0;
	virtual void onImguiRender() {}; // For debugging.
	virtual float dist() { return 0.0f; }; // For distance.
	void setParentModel(glm::mat4 pModel);
	void setPosition(const glm::vec3& position);
	void setRotation(float angle, const glm::vec3& axis);
	void setScale(const glm::vec3& scale);
	void setScale(const float& scale);
	void setRotationX(float angle);
	void setRotationY(float angle);
	void setRotationZ(float angle);
	void updateModelMatrix();
	glm::mat4 getModel();
	void setTargetPosition(const glm::vec3& targetPosition);
	glm::mat4 m_Model, m_ParentModel;
	glm::vec3 m_Position, m_NonUniformScale, 
		m_Center;
	glm::mat4 m_RotationAxis,
		m_RotationMatrixX,
		m_RotationMatrixY,
		m_RotationMatrixZ;
	void updateLightsPositions(std::vector<PointLight>& lights) {
		for (PointLight& light : lights) {
			glm::vec3 pos(light.getPosition());
			pos = getModifiedPosition(pos);
			light.updatePosition(pos);
		}
	};
	void updateLights() {};
	float m_RotationAngle, m_UniformScale;
	glm::vec3 getModifiedPosition(glm::vec3 point);

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

