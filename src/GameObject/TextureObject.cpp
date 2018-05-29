#include "TextureObject.h"



TextureObject::TextureObject(std::string filename): m_filename(filename)
{
}


TextureObject::TextureObject(std::string filename)
{
}

TextureObject::~TextureObject()
{
}

bool TextureObject::load()
{
	SDL_Surface * image = IMG_Load(m_filename.c_str());
	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);

	GLenum formatInterne(0);
	GLenum format(0);

	if (image->format->BytesPerPixel == 3)
	{
		formatInterne = GL_RGB;
		if (image->format->Rmask == 0xff)
			format = GL_RGB;
		else
			format = GL_BGR;
	}
	else if (image->format->BytesPerPixel == 4)
	{
		formatInterne = GL_RGBA;
		if (image->format->Rmask == 0xff)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	}
	glTexImage2D(GL_TEXTURE_2D, 0, formatInterne,
		image->w, image->h, 0, format, GL_UNSIGNED_BYTE, image->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	return false;
}

void TextureObject::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void TextureObject::unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
