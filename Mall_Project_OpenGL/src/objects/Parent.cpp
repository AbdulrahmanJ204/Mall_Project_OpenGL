#include "Parent.h"

void Parent::setParentModel(glm::mat4 pModel)
{
	m_ParentModel = pModel;
}

void Parent::setPosition(const glm::vec3& position) {
	m_Position = position;
	updateModelMatrix();
}

void Parent::setRotation(float angle, const glm::vec3& axis) {
	m_RotationAngle = angle;
	m_RotationAxis = axis;
	updateModelMatrix();
}

void Parent::setScale(const glm::vec3& scale) {
	m_Scale = scale;
	updateModelMatrix();
}


void Parent::updateModelMatrix() {
	m_Model = glm::mat4(1.0f);
	m_Model = glm::translate(m_Model, m_Position);
	m_Model = glm::rotate(m_Model, glm::radians(m_RotationAngle), m_RotationAxis);
	m_Model = glm::scale(m_Model, m_Scale);
	m_Model =  m_Model * m_ParentModel;
}

glm::mat4 Parent::getModel()
{
	// TODO: Check if order is correct .
	return m_ParentModel* m_Model;
};
