#include "supermarket.h"

SupermarketRoom::SupermarketRoom() :
	wall_base(16.0f, 18.0f, 119.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {3, 25}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
	wall_sec(16.0f, 18.0f, 49.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {3, 12.5}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
	wall_front(0.2f, 12.0f, 30.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {3, 12.5}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
	wall_enter(16.0f, 12.0f, 19.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {3, 12.5}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {1, 1}} }),
	arma(34.0f, 6.0f, 119.9f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag", { {Face::Up, {5, 12}},{Face::Down, {3, 10}},{Face::Right, {1, 1}} ,{Face::Left, {1, 1}},{Face::Front, {10, 6}},{Face::Back, {10, 6}} }),
	registerCach("assets/obj/cash_register/scene.gltf", "assets/shaders/model_loading.vert", "assets/shaders/model_loading.frag")
{
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	//Stands
	rafs.push_back(Box(1.0f, 6.0f, 10.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	rafs.push_back(Box(10.0f, 6.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));


	brad.push_back(Box(4.0f, 1.0f, 4.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(4.0f, 1.0f, 4.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(4.0f, 1.0f, 4.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(4.0f, 1.0f, 4.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(8.0f, 4.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(8.0f, 4.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(8.0f, 4.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	brad.push_back(Box(8.0f, 4.0f, 1.0f, "assets/shaders/vertexSh.vert", "assets/shaders/fragSh.frag"));
	setTex();

	wall_base.setPosition(glm::vec3((wall_base.getWidth() / 2), (wall_base.getHeight() / 2), (wall_base.getDepth() / 2)));
	wall_sec.setPosition(glm::vec3((wall_sec.getWidth() / 2)- wall_base.getWidth(), (wall_sec.getHeight() / 2), (wall_sec.getDepth() / 2)));
	wall_front.setPosition(glm::vec3((wall_front.getWidth() / 2), (wall_front.getHeight() / 2),70+(wall_front.getDepth() /2 )));
	wall_enter.setPosition(glm::vec3((wall_enter.getWidth() / 2)- wall_base.getWidth(), (wall_enter.getHeight() / 2),100+ (wall_enter.getDepth() / 2)));
	arma.setPosition(glm::vec3(-1, -(arma.getHeight() / 2)+ wall_base.getHeight(), +(arma.getDepth() / 2)));
}

void SupermarketRoom::drawOpaque() {
	//Postions 

	//Draw
	wall_base.setParentModel(getModel());
	wall_sec.setParentModel(getModel());
	wall_front.setParentModel(getModel());
	wall_enter.setParentModel(getModel());
	arma.setParentModel(getModel());
	registerCach.setParentModel(getModel());
	for (int i = 0; i < 10; i++)
	{
		rafs[i].setParentModel(getModel());
		rafs[i].setPosition(glm::vec3(wall_base.getWidth() / 2, rafs[i].getHeight() / 2, 30+ (i*8) + rafs[i].getDepth() / 2));
		rafs[i].drawOpaque();
	}
	rafs[10].setParentModel(getModel());
	rafs[10].setPosition(glm::vec3(wall_base.getWidth()- rafs[10].getWidth(), rafs[10].getHeight() / 2,4+ wall_base.getDepth() - rafs[10].getDepth()));
	rafs[10].drawOpaque();
	rafs[11].setParentModel(getModel());
	rafs[11].setPosition(glm::vec3(4+wall_base.getWidth()- rafs[11].getWidth(), rafs[11].getHeight() / 2, wall_base.getDepth() - rafs[11].getDepth()/2));
	rafs[11].drawOpaque();
	for (int i = 0; i < 4; i+=2)
	{
		brad[i].setParentModel(getModel());
		brad[i].setPosition(glm::vec3(-4+wall_base.getWidth() / 2, brad[i].getHeight() / 2, 10 + (i*3) + brad[i].getDepth() / 2));
		brad[i].drawOpaque();
		brad[i+1].setParentModel(getModel());
		brad[i+1].setPosition(glm::vec3(+4+wall_base.getWidth() / 2, brad[i].getHeight() / 2, 10 + (i*3) + brad[i].getDepth() / 2));
		brad[i+1].drawOpaque();
	}

	brad[4].setParentModel(getModel());
	brad[4].setPosition(glm::vec3(+4 + wall_base.getWidth() / 2, brad[4].getHeight() / 2, 0.001 +brad[4].getDepth() / 2));
	brad[4].drawOpaque();
	
	brad[5].setParentModel(getModel());
	brad[5].setPosition(glm::vec3(+4 + wall_base.getWidth() / 2- brad[4].getWidth(), brad[5].getHeight() / 2, 0.001 + brad[5].getDepth() / 2));
	brad[5].drawOpaque();
	brad[6].setParentModel(getModel());
	brad[6].setPosition(glm::vec3(+4 + wall_base.getWidth() / 2- brad[4].getWidth() - brad[5].getWidth(), brad[6].getHeight() / 2, 0.001 + brad[6].getDepth() / 2));
	brad[6].drawOpaque();
	brad[7].setParentModel(getModel());
	brad[7].setPosition(glm::vec3(+4 + wall_base.getWidth() / 2- brad[4].getWidth() - brad[5].getWidth() - brad[6].getWidth(), brad[7].getHeight() / 2, 0.001 + brad[7].getDepth() / 2));
	brad[7].drawOpaque();

	wall_base.drawOpaque();
	wall_sec.drawOpaque();
	

	arma.drawOpaque();

	registerCach.setPosition(glm::vec3(2, 3, 30));
	registerCach.setRotation(-90, glm::vec3(1.0f, 0.0f, 0.0f));
	registerCach.setScale(3);
	registerCach.drawOpaque();
	

}

void SupermarketRoom::getTransparent() {
	wall_front.getTransparent();
	wall_enter.getTransparent();

}


void SupermarketRoom::onImguiRender() {
	ImGui::SliderFloat3("TableElectronic Position ", &m_Position.x, -100.0f, 100.0f);
	
}

void SupermarketRoom::setTex()
{
	wall_front.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_3.png", 1);
	wall_enter.setFaceTexture(Face::Back, "assets/textures/electronic/elecroom1_3.png", 1);
	wall_enter.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 1, 1, 1);
	wall_enter.setFaceTexture(Face::Down, "assets/textures/electronic/t6.png", 1, 0);
	//wall_enter.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_3.png", 1);

	wall_base.setFaceTexture(Face::Down, "assets/textures/electronic/t6.png", 0, 0);
	wall_base.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_7.png", 0, 1);
	wall_base.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_6.png", 1, 0);
	wall_base.setFaceTexture(Face::Right, "assets/textures/electronic/t1.jpg", 0);
	wall_base.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 0, 0);
	wall_base.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 0, 1, 1);
	
	wall_sec.setFaceTexture(Face::Down, "assets/textures/electronic/t6.png", 0, 0);
	wall_sec.setFaceTexture(Face::Up, "assets/textures/electronic/elecroom1_7.png", 0, 1);
	wall_sec.setFaceTexture(Face::Left, "assets/textures/electronic/elecroom1_6.png", 1, 0);
	wall_sec.setFaceTexture(Face::Right, "assets/textures/electronic/t1.jpg", 1);
	wall_sec.setFaceTexture(Face::Back, "assets/textures/electronic/t1.jpg", 0, 0);
	wall_sec.setFaceTexture(Face::Front, "assets/textures/electronic/t1.jpg", 0, 1, 1);

	arma.setFaceTexture(Face::Down, "assets/textures/market/r1.jpg", 0, 0);
	arma.setFaceTexture(Face::Up, "assets/textures/market/arma1.png", 0, 1);
	arma.setFaceTexture(Face::Left, "assets/textures/market/arma1.png", 0, 0);
	arma.setFaceTexture(Face::Right, "assets/textures/market/arma1.png", 0);
	arma.setFaceTexture(Face::Back, "assets/textures/market/arma1.png", 0, 0);
	arma.setFaceTexture(Face::Front, "assets/textures/market/arma1.png", 0, 1, 1);

	for (int i = 0; i < 10; i++)
	{
		rafs[i].setFaceTexture(Face::Down, "assets/textures/market/p1.jpg", 0, 0);
		rafs[i].setFaceTexture(Face::Up, "assets/textures/market/p1.jpg", 0, 1);
		rafs[i].setFaceTexture(Face::Left, "assets/textures/market/p1.jpg", 0, 0);
		rafs[i].setFaceTexture(Face::Right, "assets/textures/market/p1.jpg", 0);
	}
	rafs[0].setFaceTexture(Face::Back, "assets/textures/market/s1.jpg");
	rafs[0].setFaceTexture(Face::Front, "assets/textures/market/s2.jpg");
	rafs[1].setFaceTexture(Face::Back, "assets/textures/market/s3.jpg");
	rafs[1].setFaceTexture(Face::Front, "assets/textures/market/s5.jpg");
	rafs[2].setFaceTexture(Face::Back, "assets/textures/market/s6.jpg");
	rafs[2].setFaceTexture(Face::Front, "assets/textures/market/s7.jpg");
	rafs[3].setFaceTexture(Face::Back, "assets/textures/market/s8.jpg");
	rafs[3].setFaceTexture(Face::Front, "assets/textures/market/s10.jpg");
	rafs[4].setFaceTexture(Face::Back, "assets/textures/market/m12.jpg");
	rafs[4].setFaceTexture(Face::Front, "assets/textures/market/m11.jpg");
	rafs[5].setFaceTexture(Face::Back, "assets/textures/market/m10.jpg");
	rafs[5].setFaceTexture(Face::Front, "assets/textures/market/m9.jpg");
	rafs[6].setFaceTexture(Face::Back, "assets/textures/market/m8.jpg");
	rafs[6].setFaceTexture(Face::Front, "assets/textures/market/m7.jpg");
	rafs[7].setFaceTexture(Face::Back, "assets/textures/market/m6.jpg");
	rafs[7].setFaceTexture(Face::Front, "assets/textures/market/m5.jpg");
	rafs[8].setFaceTexture(Face::Back, "assets/textures/market/m4.jpg");
	rafs[8].setFaceTexture(Face::Front, "assets/textures/market/m3.jpg");
	rafs[9].setFaceTexture(Face::Back, "assets/textures/market/m2.jpg");
	rafs[9].setFaceTexture(Face::Front, "assets/textures/market/m1.jpg");

	rafs[10].setFaceTexture(Face::Left, "assets/textures/market/h3.jpg");
	rafs[10].setFaceTexture(Face::Back, "assets/textures/market/p1.jpg", 0, 0);
	rafs[10].setFaceTexture(Face::Up, "assets/textures/market/p1.jpg", 0, 1);
	rafs[10].setFaceTexture(Face::Front, "assets/textures/market/p1.jpg", 0, 0);
	rafs[10].setFaceTexture(Face::Right, "assets/textures/market/p1.jpg", 0);

	rafs[11].setFaceTexture(Face::Back, "assets/textures/market/h1.jpg");
	rafs[11].setFaceTexture(Face::Front, "assets/textures/market/p1.jpg", 0, 0);
	rafs[11].setFaceTexture(Face::Up, "assets/textures/market/p1.jpg", 0, 1);
	rafs[11].setFaceTexture(Face::Left, "assets/textures/market/p1.jpg", 0, 0);
	rafs[11].setFaceTexture(Face::Right, "assets/textures/market/p1.jpg", 0);

	for (int i = 0; i < 4; i++)
	{
		brad[i].setFaceTexture(Face::Front, "assets/textures/market/l5.png", 0, 0);
		brad[i].setFaceTexture(Face::Back, "assets/textures/market/l5.png", 0, 1);
		brad[i].setFaceTexture(Face::Left, "assets/textures/market/l5.png", 0, 0);
		brad[i].setFaceTexture(Face::Right, "assets/textures/market/l5.png", 0);
		brad[i].setFaceTexture(Face::Down, "assets/textures/market/l5.png", 0);
	}
	brad[0].setFaceTexture(Face::Up, "assets/textures/market/l1.jpg");
	brad[1].setFaceTexture(Face::Up, "assets/textures/market/l2.jpg");
	brad[2].setFaceTexture(Face::Up, "assets/textures/market/l3.jpg");
	brad[3].setFaceTexture(Face::Up, "assets/textures/market/l4.jpg");
	brad[4].setFaceTexture(Face::Front, "assets/textures/market/n8.jpg");
	brad[4].setFaceTexture(Face::Up, "assets/textures/market/l5.png");
	brad[5].setFaceTexture(Face::Front, "assets/textures/market/n4.jpg");
	brad[5].setFaceTexture(Face::Up, "assets/textures/market/l5.png");
	brad[6].setFaceTexture(Face::Front, "assets/textures/market/n7.jpg");
	brad[6].setFaceTexture(Face::Up, "assets/textures/market/l5.png");
	brad[7].setFaceTexture(Face::Front, "assets/textures/market/n1.jpg");
	brad[7].setFaceTexture(Face::Up, "assets/textures/market/l5.png");
	brad[7].setFaceTexture(Face::Left, "assets/textures/market/l5.png");

	
}