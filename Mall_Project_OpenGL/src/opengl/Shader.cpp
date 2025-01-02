#include "Shader.h"


Shader::Shader(const std::string& filepath) : m_FilePath(filepath), m_RendererID(0)
{
	ShaderSource shaderSource = ParseShader(filepath);
	m_RendererID = CreateShader(shaderSource.vertexSource, shaderSource.FragmentSource);
}

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	m_FilePath = "Vertex Shader Path : " + vertexPath +
		" Fragment Shader Path : " + fragmentPath;
	ShaderSource shaderSource;
	shaderSource.vertexSource = readShader(vertexPath);
	shaderSource.FragmentSource = readShader(fragmentPath);
	m_RendererID = CreateShader(shaderSource.vertexSource, shaderSource.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}

std::string Shader::readShader(const std::string& path) const
{
	std::fstream stream(path);
	std::string line;
	std::string s = "";
	while (getline(stream, line)) {
		s += line + "\n";
	}
	return s;
}
void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}



unsigned int Shader::CompileShader(unsigned int type, const std::string source)
{
	int id = glCreateShader(type);
	// making a pointer to the beggining of the string:
	const char* src = source.c_str();
	// shader , how many shaders , source id , end of shader if you dont want to compile the whole string.
	glShaderSource(id, 1, &src, nullptr); // specifies the source of shader

	// compile it
	glCompileShader(id);

	// Error Handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)_malloca(length * sizeof(char)); // dynamicly store char array in stack : just skip it.
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Faild to compile " << (type == GL_VERTEX_SHADER ? "vertex " : "fragment ") << " shader!\n";
		std::cout << message << std::endl;

		glDeleteShader(id);
		return 0;
	}
	return id;

}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	// attach shaders to program
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	// link program
	glLinkProgram(program);
	glValidateProgram(program);

	// delete intermidate data 
	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

ShaderSource Shader::ParseShader(const std::string& filepath) const
{
	std::fstream stream(m_FilePath);
	std::string line;
	enum class Type {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	Type type = Type::NONE;
	std::string s[2] = { "","" };
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = Type::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = Type::FRAGMENT;
			}
		}
		else {
			s[(int)type] += line + "\n";
		}
	}

	return { s[0] , s[1] };
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(getUniformLoacation(name), v0, v1, v2, v3));
}
void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GLCall(glUniformMatrix4fv(getUniformLoacation(name), 1, GL_FALSE, &matrix[0][0])); // location , how many matrix ary we providing , something about array format , pointer to the first elemnt in array
}
void Shader::SetUniform4fv(const std::string& name, glm::vec4 vec)
{
	GLCall(glUniform4fv(getUniformLoacation(name), 1, &vec[0]));
}

void Shader::SetUniform3f(const std::string& name, float v0, float v1, float v2)
{
	GLCall(glUniform3f(getUniformLoacation(name), v0, v1, v2));
}

void Shader::SetUniform3fv(const std::string& name, glm::vec3 vec)
{
	GLCall(glUniform3fv(getUniformLoacation(name), 1, &vec[0]));
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	GLCall(glUniform1i(getUniformLoacation(name), value));
}
void Shader::SetUniform1f(const std::string& name, float value)
{
	GLCall(glUniform1f(getUniformLoacation(name), value));
}


int Shader::getUniformLoacation(const std::string& name)
{
	if (m_UniformLoactionCache.find(name) != m_UniformLoactionCache.end())
		return m_UniformLoactionCache[name];
	int location;
	GLCall(location = glGetUniformLocation(m_RendererID, name.c_str()));

	if (location == -1)
		std::cout << "Warining: unifrom ' " << name << " ' doesn't exist" << std::endl;
	m_UniformLoactionCache[name] = location;
	return location;
}


