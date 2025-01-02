#include "Parent.h"

void Parent::translate(glm::vec3 pos)
{
	model = glm::translate(model, pos);
};
void Parent::rotate(float angle, glm::vec3 axis)
{
	model = glm::rotate(model, glm::radians(angle), axis);
}
void Parent::scale(float factor, glm::vec3 axis)
{
	glm::vec3 scale1 = factor * axis;
	model = glm::scale(model, scale1);
}
void Parent::setParentModel(glm::mat4 pModel)
{
	parentModel = pModel;
}
glm::mat4 Parent::getModel()
{
	// TODO: Check if order is correct .
	return parentModel * model;
};
