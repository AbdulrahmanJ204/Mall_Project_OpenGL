#include "Cube.h"
#include "Scene.h"
// TODO: Clean this :-)
Cube::Cube() :
	m_Length(100.0f),
	m_FScale(1.0f),
	m_Degree(0.0f),
	m_Axis(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_Translate(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_Scale(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_CubeColor(glm::vec3(1.0f, 0.5f, 0.31f)),
	m_LightColor(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_LightPos(glm::vec3(10.0f, 10.0f, 20.0f)),
	m_PointLight(m_LightPos, lightProp, 100.0f),
	m_SpotLight(m_LightPos ,glm::vec3(0.0f , 0.0f ,0.0f), lightProp, 30.0f),
	m_Model(glm::mat4(1.0f)),
	m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0.0f)))
{
	
	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
	m_Proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 2000.0f);
}

Cube::Cube(float width, float height, float depth, const std::string& vertexPath, const std::string& fragPath, glm::vec3 trans) :
	m_Length(0),
	m_FScale(1.0f),
	m_Degree(0.0f),
	m_Axis(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_Translate(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_Scale(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_CubeColor(glm::vec3(1.0f, 0.5f, 0.31f)),
	m_LightColor(glm::vec3(1.0f, 1.0f, 1.0f)),
	m_LightPos(glm::vec3(0.0f, 0.0f, 0.0f)),
	m_Model(glm::mat4(1.0f)),
	m_PointLight(m_LightPos, lightProp, 600),
	m_SpotLight(m_LightPos,glm::vec3(0.0f, 0.0f, 0.0f), lightProp, 100.0f),
	m_Pos(trans),
	m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0.0f)))
{
	int screenWidth, screenHeight;
	
	glfwGetWindowSize(glfwGetCurrentContext(), &screenWidth, &screenHeight);
	m_Proj = glm::perspective(glm::radians(45.0f), (float)screenWidth / screenHeight, 0.1f, 2000.0f);
	float vertices[] = {
		// Front face
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
		
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 0.0f, -1.0f,  0.0f, 1.0f,

		// Back face
		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 1.0f,
		
		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 0.0f,  1.0f,  0.0f, 1.0f,

		// Left face
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		-width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		
		-width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		-width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		-width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z, -1.0f, 0.0f,  0.0f,  0.0f, 0.0f,

		// Right face
		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		
		 width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
		 width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
		 width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  1.0f, 0.0f,  0.0f,  0.0f, 0.0f,

		 // Top face
		 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
		 
		 -width / 2 + trans.x,  height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  1.0f, 0.0f,
		 -width / 2 + trans.x,  height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, 1.0f,  0.0f,  0.0f, 0.0f,

		 // Bottom face
		 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		
		 -width / 2 + trans.x, -height / 2 + trans.y, -depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 1.0f,
		  width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  1.0f, 0.0f,
		 -width / 2 + trans.x, -height / 2 + trans.y,  depth / 2 + trans.z,  0.0f, -1.0f, 0.0f,  0.0f, 0.0f,
	};
	m_VBO = std::make_unique<VBO>(vertices, sizeof(vertices));
	VBOLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);
	m_VAO = std::make_unique<VAO>();
	m_VAO->AddBuffer(*m_VBO, layout);
	m_Texture = std::make_unique<Texture>("assets/textures/oh.png");
	m_SpMap = std::make_unique<Texture>("assets/textures/container2_specular.png");
	m_Shader = std::make_unique<Shader>(vertexPath, fragPath);
	m_Texture->Bind();
	m_Shader->Bind();
	//m_Shader->SetUniform1i("u_Texture", 0); // 0 is slot number. it should match with slot we chose
	updateUniforms();
	m_VAO->Unbind();
	m_Shader->Unbind();
}

Cube::~Cube()
{
}

void Cube::draw()
{
	m_VAO->Bind();
	m_Texture->Bind();
	m_SpMap->Bind(1);
	m_Shader->Bind();
	updateUniforms();
	GLCall(glDrawArrays(GL_TRIANGLES, 0, 36));
}
void Cube::updateUniforms() {
	m_Shader->Bind();

	m_Shader->setUniformMat4f("model", m_Model);
	m_Shader->setUniformMat4f("view", m_View);
	m_Shader->setUniformMat4f("projection", m_Proj);

	if (m_Shader->getPath().find("light_cube") != std::string::npos) return;


	m_Shader->SetUniform3fv("viewPos", Scene::instancePtr->getCameraPosition());
	m_PointLight.updatePosition(m_LightPos);
	m_PointLight.uploadToShader(*m_Shader, "pointLight");

	if (isSpotOn)
	{

		m_SpotLight.updateDircetion(Scene::instancePtr->getCamera().Front);
		m_SpotLight.updatePosition(Scene::instancePtr->getCameraPosition());
		m_SpotLight.uploadToShader(*m_Shader, "spotLight");
	}
	else m_SpotLight.turnOff(*m_Shader, "spotLight");
	m_Shader->SetUniform1f("material.shininess", 32.0f);
	m_Shader->SetUniform1i("material.diffuse", 0);
	m_Shader->SetUniform1i("material.specular", 1);







}
void Cube::Rotate(float degree, glm::vec3& axis) {
	m_Model = glm::rotate(m_Model, glm::radians(-m_Degree), m_Axis);
	m_Degree = degree, m_Axis = axis;
	m_Model = glm::rotate(m_Model, glm::radians(m_Degree), m_Axis);
}
void Cube::Translate(glm::vec3& translate) {
	m_Model = glm::translate(m_Model, -m_Translate);
	m_Pos -= m_Translate;
	m_Translate = translate;
	m_Pos += m_Translate;
	m_Model = glm::translate(m_Model, m_Translate);
}
void Cube::Scale(glm::vec3& scale) {
	m_Model = glm::scale(m_Model, glm::vec3(1.0f, 1.0f, 1.0f) / m_Scale);
	m_Scale = scale;
	m_Model = glm::scale(m_Model, m_Scale);
}
void Cube::Scale(float scale) {
	m_Model = glm::scale(m_Model, glm::vec3(1.0f / m_FScale, 1.0f / m_FScale, 1.0f / m_FScale));
	m_FScale = scale;
	m_Scale = glm::vec3(m_FScale, m_FScale, m_FScale);
	m_Model = glm::scale(m_Model, m_Scale);
}



void Cube::SetView(glm::mat4 view) {
	m_View = view;

}

void Cube::SetProj(glm::mat4 proj) {
	m_Proj = proj;

}

void Cube::SetLightPos(glm::vec3 pos) {
	m_LightPos = pos;
}
