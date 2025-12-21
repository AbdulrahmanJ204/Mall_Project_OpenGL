#include "caffeElsaffah\kanabePlusTable\KanabePlusWall.h";
KanabePlusWall::KanabePlusWall()

{
	setTex();
}

void KanabePlusWall::drawOpaque()
{
	k1.setParentModel(getModel());
	k1.setPosition(glm::vec3(26.5f, 1.0f, 2.5));
	k1.drawOpaque();

}

void KanabePlusWall::getTransparent()
{
}

void KanabePlusWall::onImguiRender()
{
	ImGui::SliderFloat3("Counter Position ", &m_Position.x, -200.0f, 200.0f);

}

void KanabePlusWall::setTex()
{
}
