#include "Object.h"

void Object::setParentModel(glm::mat4 pModel)
{
	m_ParentModel = pModel;
}

void Object::setPosition(const glm::vec3& position) {
	m_Position = position;
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

glm::vec3 Object::getModifiedPosition()
{
	return glm::vec3(getModel() * glm::vec4(m_Center, 1.0f));
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
