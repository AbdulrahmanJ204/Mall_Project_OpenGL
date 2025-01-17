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
	m_RotationAxis = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::normalize(axis));
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

void Object::setRotationX(float angle)
{
	m_RotationMatrixX = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
	updateModelMatrix();
}

void Object::setRotationY(float angle)
{
	m_RotationMatrixY = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
	updateModelMatrix();
}

void Object::setRotationZ(float angle)
{
	m_RotationMatrixZ = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	updateModelMatrix();
}

glm::vec3 Object::getModifiedPosition(glm::vec3 point)
{	
	return glm::vec3(getModel() * glm::vec4(point, 1.0f));
}



void Object::updateModelMatrix() {
	m_Model = glm::mat4(1.0f);
	m_Model = glm::translate(m_Model, m_Position);
	m_Model *= m_RotationMatrixX * m_RotationMatrixY * m_RotationMatrixZ * m_RotationAxis;
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
	
}
