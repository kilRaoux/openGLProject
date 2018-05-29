#include "Caisse.h"
#include <iostream>

// Permet d'�viter la r�-�criture du namespace glm::

using namespace glm;


// Constructeur et Destructeur

Caisse::Caisse(float taille, std::string const vertexShader,std::string const fragmentShader, std::string const texture) : Cube(taille, vertexShader, fragmentShader),
                                                                                                                           m_texture(texture),
                                                                                                                           m_tailleCoordTextureBytes(72 * sizeof(float))
{
    // Chargement de la texture

    m_texture.charger();

	float verticesTmp[] = { -taille, -taille, -taille,   taille, -taille, -taille,   taille, taille, -taille,     // Face 1
		-taille, -taille, -taille,   -taille, taille, -taille,   taille, taille, -taille,     // Face 1

		taille, -taille, taille,   taille, -taille, -taille,   taille, taille, -taille,       // Face 2
		taille, -taille, taille,   taille, taille, taille,   taille, taille, -taille,         // Face 2

		-taille, -taille, taille,   taille, -taille, taille,   taille, -taille, -taille,      // Face 3
		-taille, -taille, taille,   -taille, -taille, -taille,   taille, -taille, -taille,    // Face 3

		-taille, -taille, taille,   taille, -taille, taille,   taille, taille, taille,        // Face 4
		-taille, -taille, taille,   -taille, taille, taille,   taille, taille, taille,        // Face 4

		-taille, -taille, -taille,   -taille, -taille, taille,   -taille, taille, taille,     // Face 5
		-taille, -taille, -taille,   -taille, taille, -taille,   -taille, taille, taille,     // Face 5

		-taille, taille, taille,   taille, taille, taille,   taille, taille, -taille,         // Face 6
		-taille, taille, taille,   -taille, taille, -taille,   taille, taille, -taille };      // Face 6

	for (int i(0); i < 108; i++)
	{
		m_vertices[i] = verticesTmp[i];
	}
    // Coordonn�es de texture temporaires

    float coordTextureTmp[] = {0, 0,   1, 0,   1, 1,     // Face 1
                               0, 0,   0, 1,   1, 1,     // Face 1

                               0, 0,   1, 0,   1, 1,     // Face 2
                               0, 0,   0, 1,   1, 1,     // Face 2

                               0, 0,   1, 0,   1, 1,     // Face 3
                               0, 0,   0, 1,   1, 1,     // Face 3

                               0, 0,   1, 0,   1, 1,     // Face 4
                               0, 0,   0, 1,   1, 1,     // Face 4

                               0, 0,   1, 0,   1, 1,     // Face 5
                               0, 0,   0, 1,   1, 1,     // Face 5

                               0, 0,   1, 0,   1, 1,     // Face 6
                               0, 0,   0, 1,   1, 1};    // Face 6


    // Copie des valeurs dans le tableau final

    for(int i (0); i < 72; i++)
        m_coordTexture[i] = coordTextureTmp[i];
}


Caisse::~Caisse()
{

}


// M�thodes

void Caisse::charger()
{
    // Destruction d'un �ventuel ancien VBO

    if(glIsBuffer(m_vboID) == GL_TRUE)
        glDeleteBuffers(1, &m_vboID);
	vbo = VertexBufferObject(
		m_vertices, m_tailleVerticesBytes,
		m_coordTexture, m_tailleCoordTextureBytes);
    // G�n�ration de l'ID
	/*
    glGenBuffers(1, &m_vboID);
    // Verrouillage du VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
        // Allocation de la m�moire vid�o
        glBufferData(GL_ARRAY_BUFFER,
			m_tailleVerticesBytes + m_tailleCoordTextureBytes,
			0, GL_STATIC_DRAW);
        // Transfert des donn�es
        glBufferSubData(GL_ARRAY_BUFFER,
			0, m_tailleVerticesBytes, m_vertices);
        glBufferSubData(GL_ARRAY_BUFFER,
			m_tailleVerticesBytes, m_tailleCoordTextureBytes, m_coordTexture);
    // D�verrouillage de l'objet
    glBindBuffer(GL_ARRAY_BUFFER, 0);
	*/
    // Destruction d'un �ventuel ancien VAO

    if(glIsVertexArray(m_vaoID) == GL_TRUE)
        glDeleteVertexArrays(1, &m_vaoID);


    // G�n�ration de l'ID du VAO

    glGenVertexArrays(1, &m_vaoID);


    // Verrouillage du VAO

    glBindVertexArray(m_vaoID);

	vbo.load();
		/*
        // Verrouillage du VBO

        glBindBuffer(GL_ARRAY_BUFFER, m_vboID);
	//vbo.bind();


            // Acc�s aux vertices dans la m�moire vid�o

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
            glEnableVertexAttribArray(0);


            // Acc�s aux coordonn�es de texture dans la m�moire vid�o

            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_tailleVerticesBytes));
            glEnableVertexAttribArray(2);


        // D�verrouillage du VBO

        glBindBuffer(GL_ARRAY_BUFFER, 0);

		*/
		
    // D�verrouillage du VAO

    glBindVertexArray(0);
}


void Caisse::afficher(glm::mat4 &projection, glm::mat4 &modelview)
{
    // Activation du shader

    glUseProgram(m_shader.getProgramID());


        // Verrouillage du VAO

        glBindVertexArray(m_vaoID);


            // Envoi des matrices

            m_shader.envoyerMat4("modelviewProjection", projection * modelview);


            // Verrouillage de la texture

            glBindTexture(GL_TEXTURE_2D, m_texture.getID());

            // Rendu
            glDrawArrays(GL_TRIANGLES, 0, 36);


            // D�verrouillage de la texture

            glBindTexture(GL_TEXTURE_2D, 0);


        // D�verrouillage du VAO

        glBindVertexArray(0);


    // D�sactivation du shader

    glUseProgram(0);
}
