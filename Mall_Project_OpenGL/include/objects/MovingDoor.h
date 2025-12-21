#pragma once
#include "core.h"
#include "Object.h"
#include "Box.h"

#define doorTexture std::map<Face , std::string>
class MovingDoor : public Object {
public:
    MovingDoor(glm::vec3 position, float doorWidth, float doorHeight, float doorDepth,
        const std::string lvShader, const std::string lfShader,
        const std::string rvShader, const std::string rfShader);

    void update();

    void updateDoorPosition(Box& doorSide, const glm::vec3& targetPos, float deltaTime);

    void setLeftTexture(doorTexture& textures);
    void setRightTexture(doorTexture& textures);
    void drawOpaque() override;
    void getTransparent() override;

private:
    Box leftSide, rightSide;
    glm::vec3 m_Position;
    glm::vec3 leftClosedPos, leftOpenPos;
    glm::vec3 rightClosedPos, rightOpenPos;
    bool isOpen = false;

    // Movement speed.
    float doorSpeed = 1.0f;
};
