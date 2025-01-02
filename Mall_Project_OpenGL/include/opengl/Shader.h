#pragma once
#include "core.h"

struct ShaderSource {
	std::string vertexSource;
	std::string FragmentSource;
};
class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_FilePath; // just for debug i think
	// caching for unifroms
	std::unordered_map<std::string, int> m_UniformLoactionCache;
public:
	Shader(const std::string& filepath);
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();

	inline std::string getPath() const { return m_FilePath; }
	// TODO : convert vec2 , 3 , 4 to & if always passing a defined vec3	
	void Bind() const;
	void Unbind() const;
	void SetUniform1i(const std::string& name,int value);
	void SetUniform1f(const std::string& name,float value);
	
	//void SetUniform2f(const std::string& name, float v0, float v1, float v2);
	//void SetUniform2fv(const std::string& name, glm::vec3 vec);
	
	void SetUniform3f(const std::string& name, float v0, float v1, float v2);// convert to vec4 when using math
	void SetUniform3fv(const std::string& name, glm::vec3 vec);
	
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);// convert to vec4 when using math
	void SetUniform4fv(const std::string& name, glm::vec4 vec);
	
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

	

private:
	unsigned int CompileShader(unsigned int type, const std::string source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderSource ParseShader(const std::string& filepath) const;
	int getUniformLoacation(const std :: string& name );
	std::string readShader(const std::string& path) const;
};	

