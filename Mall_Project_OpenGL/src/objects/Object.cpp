#include "Object.h"
#include <Application.h>

void Object::setParentModel(glm::mat4 pModel)
{
	m_ParentModel = pModel;
}

void Object::setPosition(const glm::vec3& position) {
	m_Position = position;
	m_TargetPosition = position;
	updateModelMatrix();
}

void Object::setRotation(float angle, const glm::vec3& axis) {
	m_RotationAngle = angle;
	m_RotationAxis = axis;
	updateModelMatrix();
}

void Object::setScale(const glm::vec3& scale) {
	m_NonUniformScale = scale;
	updateModelMatrix();
}

void Object::setScale(const float& scale) {
	m_UniformScale = scale;
	updateModelMatrix();
}

glm::vec3 Object::getModifiedPosition(glm::vec3& point)
{	
	return glm::vec3(getModel() * glm::vec4(point, 1.0f));
}



void Object::updateModelMatrix() {
	m_Model = glm::mat4(1.0f);
	m_Model = glm::translate(m_Model, m_Position);
	m_Model = glm::rotate(m_Model, glm::radians(m_RotationAngle), m_RotationAxis);
	glm::vec3 combinedScale = m_NonUniformScale * m_UniformScale;
	m_Model = glm::scale(m_Model, combinedScale);
}

glm::mat4 Object::getModel()
{
	// TODO: Check if order is correct .
	return m_ParentModel* m_Model;
};

void Object::setTargetPosition(const glm::vec3& targetPosition) {
	m_TargetPosition = targetPosition;
}

void Object::setTargetRotation(float targetAngle, const glm::vec3& targetAxis) {
	m_TargetRotationAngle = targetAngle;
	m_TargetRotationAxis = targetAxis;
}

void Object::setTargetScale(const glm::vec3& targetScale) {
	m_TargetScale = targetScale;
}
void Object::update() {
	float deltaTime = Application::instancePtr->deltaTime;
	// Interpolate position
	m_Position = glm::mix(m_Position, m_TargetPosition, m_MoveSpeed * deltaTime);

	// Interpolate rotation
	m_RotationAngle = glm::mix(m_RotationAngle, m_TargetRotationAngle, m_RotateSpeed * deltaTime);
	m_RotationAxis = glm::mix(m_RotationAxis, m_TargetRotationAxis, m_RotateSpeed * deltaTime);

	// Interpolate scale
	m_NonUniformScale = glm::mix(m_NonUniformScale, m_TargetScale, m_ScaleSpeed * deltaTime);

	// Update the model matrix after interpolation
	updateModelMatrix();
}
