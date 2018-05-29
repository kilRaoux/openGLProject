#ifndef DEF_CAISSE
#define DEF_CAISSE


// Includes

#include "Cube.h"
#include "Texture.h"
#include "VertexBufferObject.h"
#include <string>


// Classe Caisse

class Caisse : public Cube
{
    public:

		Caisse(float taille, std::string const vertexShader, std::string const fragmentShader, std::string const texture);
		~Caisse();

		void charger();
		void afficher(glm::mat4 &projection, glm::mat4 &modelview);


    private:
		VertexBufferObject vbo;
		Texture m_texture;
		float m_coordTexture[72];
		int m_tailleCoordTextureBytes;
};

#endif
