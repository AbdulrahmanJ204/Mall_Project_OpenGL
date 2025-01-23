#include "MovingDoor.h"

#include "Application.h"
MovingDoor::MovingDoor(glm::vec3 position, float doorWidth, float doorHeight, float doorDepth,
    const std::string lvShader, const std::string lfShader,
    const std::string rvShader, const std::string rfShader)
    : m_Position(position),
    leftSide(doorWidth / 2, doorHeight, doorDepth, lvShader, lfShader),
    rightSide(doorWidth / 2, doorHeight, doorDepth, rvShader, rfShader) {
    // Closed positions
    leftClosedPos = m_Position + glm::vec3(-doorWidth / 4, 0.0f, 0.0f);
    rightClosedPos = m_Position + glm::vec3(doorWidth / 4, 0.0f, 0.0f);

    // Open positions
    leftOpenPos = leftClosedPos + glm::vec3(-doorWidth / 2, 0.0f, 0.0f);
    rightOpenPos = rightClosedPos + glm::vec3(doorWidth / 2, 0.0f, 0.0f);
}

void MovingDoor::update() {
    const glm::vec3& cameraPosition = Scene::instancePtr->getCameraPosition();
    float deltaTime = Application::instancePtr->deltaTime;
    float distance = glm::length(cameraPosition - getModifiedPosition(m_Position));

    isOpen = distance < 5.0f;

    glm::vec3 leftTargetPos = isOpen ? leftOpenPos : leftClosedPos;
    glm::vec3 rightTargetPos = isOpen ? rightOpenPos : rightClosedPos;

    updateDoorPosition(leftSide, leftTargetPos, deltaTime);
    updateDoorPosition(rightSide, rightTargetPos, deltaTime);
}

void MovingDoor::updateDoorPosition(Box& doorSide, const glm::vec3& targetPos, float deltaTime) {
    glm::vec3 currentPosition = doorSide.m_Position;
    glm::vec3 newPosition = glm::mix(currentPosition, targetPos, doorSpeed * deltaTime);
    doorSide.setPosition(newPosition);
}
void MovingDoor::setLeftTexture(doorTexture& textures)
{
    for (auto& x : textures) leftSide.setFaceTexture(x.first, x.second, true);
}
void MovingDoor::setRightTexture(doorTexture& textures)
{
    for (auto& x : textures) rightSide.setFaceTexture(x.first, x.second, true);
}
void MovingDoor::drawOpaque()
{
    leftSide.setParentModel(getModel());
    rightSide.setParentModel(getModel());
    leftSide. drawOpaque();
    rightSide.drawOpaque();
}

void MovingDoor::getTransparent()
{
    leftSide.setParentModel(getModel());
    rightSide.setParentModel(getModel());
    leftSide.getTransparent();
    rightSide.getTransparent();
}
