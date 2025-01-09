#include "Square.h"
#include <VBOLayout.h>
#include <Scene.h>


Square::Square(const float* vertices ,float size, const std::string& vertexPath, const std::string& fragmentPath)
    : m_IsTransparent(false) {
    m_VAO = std::make_unique<VAO>();
    m_VBO = std::make_unique<VBO>(vertices, size );
    VBOLayout layout;
    layout.Push<float>(3); // Position
    layout.Push<float>(3); // Normals
    layout.Push<float>(2); // Texture coordinates
    m_Normal = glm::vec3(vertices[3], vertices[4], vertices[5]);
    m_VAO->AddBuffer(*m_VBO, layout);
    m_Center = glm::vec3(vertices[0], vertices[1], vertices[2]);
    std::set<float> stx , sty , stz;
    for (int i = 0; i < 6; ++i) { // Assuming 4 vertices
        stx.insert(vertices[i * 8 + 0]); // x 
        sty.insert(vertices[i * 8 + 1]); // y coordinate
        stz.insert(vertices[i * 8 + 2]); // z coordinate
    }
    for (auto x : stx) {
        m_Center.x += x;
    }
    for (auto x : sty) {
        m_Center.y += x;
    }
    for (auto x : stz) {
        m_Center.z += x;
    }
    m_Center /= 4.0f; // Average
    m_Shader = std::make_shared<Shader>(vertexPath, fragmentPath);
    m_VAO->Unbind();
}

Square::~Square() {}

void Square::setTexture(const std::string& texturePath, bool isTransparent, bool mirrorX, bool mirrorY) {
    m_IsTransparent = isTransparent;
    m_Texture = std::make_shared<Texture>(texturePath, mirrorX, mirrorY);
}

void Square::drawOpaque() {
    if (m_IsTransparent) return;

    updateModelMatrix();
   
    m_Shader->Bind();
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->setUniformMat4f("model", getModel());
    m_Shader->setUniformMat4f("view", Scene::getView());

    //if (m_Texture) {
        m_Texture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    //}

    m_VAO->Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); // 6 vertices per face
    m_VAO->Unbind();
    m_Shader->Unbind();
}
float Square::distanceToPlane() {
    // Camera position
    glm::vec3 point = Scene::instancePtr->getCameraPosition();

    // Transform the normal
    glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(getModel())));
    glm::vec3 transformedNormal = normalMatrix * m_Normal;
    transformedNormal = glm::normalize(transformedNormal);

    // Transform the plane point (center of the face)
    glm::vec3 planePoint = glm::vec3(getModel() * glm::vec4(m_Center, 1.0f));

    // Calculate the signed distance from the camera to the plane
    float signedDistance = glm::dot(transformedNormal, point - planePoint);
    float distance = glm::abs(signedDistance);

    // Debug output
    std::cout << "-------------------------------\n";
    std::cout << "Original Normal: (" << m_Normal.x << ", " << m_Normal.y << ", " << m_Normal.z << ")\n";
    std::cout << "Transformed Normal: (" << transformedNormal.x << ", " << transformedNormal.y << ", " << transformedNormal.z << ")\n";
    std::cout << "Plane Point (Local): (" << m_Center.x << ", " << m_Center.y << ", " << m_Center.z << ")\n";
    std::cout << "Plane Point (World): (" << planePoint.x << ", " << planePoint.y << ", " << planePoint.z << ")\n";
    std::cout << "Camera Position: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    std::cout << "Signed Distance: " << signedDistance << "\n";
    std::cout << "Distance: " << distance << "\n";
    std::cout << "-------------------------------\n";

    return distance;
}
void Square::drawTransparent()
{
    if (!m_IsTransparent) return;
    updateModelMatrix();
    m_Shader->Bind();
    m_Shader->setUniformMat4f("projection", Scene::getProjection());
    m_Shader->setUniformMat4f("model", getModel());
    m_Shader->setUniformMat4f("view", Scene::getView());

    //if (m_Texture) {
        m_Texture->Bind();
        m_Shader->SetUniform1i("u_Texture", 0);
    //}

    m_VAO->Bind();
    GLCall(glDrawArrays(GL_TRIANGLES, 0, 6)); // 6 vertices per face
    m_VAO->Unbind();
    m_Shader->Unbind();
}

void Square::getTransparent() {
    if (!m_IsTransparent) return;
    Scene::addTransparent(this);
}

void Square::onImguiRender() {
    glm::vec3 planeNormal = (glm::transpose(glm::inverse(getModel()))) * glm::vec4(m_Normal , 1.0f);
    planeNormal = glm::normalize(planeNormal);
    glm::mat4 transform = getModel(); // Transformation matrix for the box
    glm::mat3 normalMatrix = glm::transpose(glm::inverse(glm::mat3(transform)));

    // Transform the normal
    glm::vec3 originalNormal = m_Normal; // Original normal of the face
    glm::vec3 transformedNormal = normalMatrix * originalNormal;

    ImGui::InputFloat3("NORMALS", &transformedNormal.x);
    float d = distanceToPlane();
    ImGui::InputFloat("Distance", &d);
    ImGui::SliderFloat3("Position", &m_Position.x, -100, 100);
}