#include "ShaderObject.h"
#include <GL\glew.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "glm/gtc/type_ptr.hpp"
#include "..\debugFoo.h"



ShaderObject::ShaderObject(const char *filename):
	filepath(filename)
{
	m_id = glCreateProgram();
	ShaderProgramSource sps = parseShader(filename);
	LOG(sps.VertexSource);
	unsigned int vs = compileShader(GL_VERTEX_SHADER, sps.VertexSource);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, sps.FragmentSource);

	glAttachShader(m_id, vs);
	glAttachShader(m_id, fs);
	glLinkProgram(m_id);
	glValidateProgram(m_id);

	glDeleteShader(vs);
	glDeleteShader(fs);
}


ShaderObject::~ShaderObject()
{
	glDeleteProgram(m_id);
}

void ShaderObject::bind()
{
	glUseProgram(m_id);
}

void ShaderObject::unbind()
{
	glUseProgram(0);
}

void ShaderObject::setUniform4f(const std::string & name, float f0, float f1, float f2, float f3)
{
	glUniform4f(getUniformLocation(name), f0, f1, f2, f3);
}

void ShaderObject::setUniformMat4(const std::string & name, glm::mat4 matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, false, glm::value_ptr(matrix));
}

unsigned int ShaderObject::getUniformLocation(const std::string name)
{
	if (m_locationCache.find(name) != m_locationCache.end())
		return m_locationCache[name];
	unsigned int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
		std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
	m_locationCache[name] = location;
	return location;
}
unsigned int ShaderObject::compileShader(unsigned int type,const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, msg);
		std::cout << "Error: Fail to compile " 
			<< (type == GL_VERTEX_SHADER ? "vertex" : "fragment") 
			<< " shader !" << std::endl;
		std::cout << msg << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}

ShaderProgramSource ShaderObject::parseShader(const std::string& filepath)
{
	std::ifstream stream(filepath);

	enum class ShaderType
	{
		NONE = -1,
		VERTEX = 0,
		FRAMENT = 1

	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAMENT;
		}
		else if (type != ShaderType::NONE)
		{
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };
}
