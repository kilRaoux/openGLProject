#pragma once
#include <string>
#include <unordered_map>
#include "glm/glm.hpp"
struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class ShaderObject
{
public:
	ShaderObject(const char *filename);
	~ShaderObject();
	void bind();
	void unbind();
	void setUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
	void setUniformMat4(const std::string& name, glm::mat4 matrix);
private:

	std::unordered_map<std::string, unsigned int> m_locationCache;
	std::string filepath;
	unsigned int getUniformLocation(const std::string name);
	static unsigned int compileShader(
		unsigned int type,
		const std::string& source);
	static ShaderProgramSource parseShader(const std::string& filepath);
	unsigned int m_id;
};

