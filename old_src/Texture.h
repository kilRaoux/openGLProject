#ifndef DEF_TEXTURE
#define DEF_TEXTURE


// Include Windows

#include <GL/glew.h>
#include <SDL_image.h>



// Autres includes

#include <SDL.h>
#include <iostream>
#include <string>


// Classe Textures

class Texture
{
    public:

    Texture();
    Texture(std::string fichierImage);
    Texture(int largeur, int hauteur, GLenum format, GLenum formatInterne, bool textureVide);
    Texture(Texture const &textureACopier);
    ~Texture();

    Texture& operator=(Texture const &textureACopier);
    bool charger();
    void chargerTextureVide();
    SDL_Surface* inverserPixels(SDL_Surface *imageSource) const;

    GLuint getID() const;
    void setFichierImage(const std::string &fichierImage);


    private:

    GLuint m_id;
    std::string m_fichierImage;

    int m_largeur;
    int m_hauteur;
    GLenum m_format;
    GLenum m_formatInterne;
    bool m_textureVide;
};

#endif
