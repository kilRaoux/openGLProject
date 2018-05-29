#pragma once
#include <string>
#include <SDL_image.h>
#include <SDL.h>
#include <GL\glew.h>

class TextureObject
{
public:
	TextureObject(std::string filename);
	~TextureObject();
	bool load();
	void bind();
	void unbind();
private:
	unsigned int m_id;
	std::string m_filename;
};

