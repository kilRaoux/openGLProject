#include "Cube.h"


// Permet d'�viter la r�-�criture du namespace glm::

using namespace glm;


// Constructeur et Destructeur

Cube::Cube(float taille, std::string const vertexShader, std::string const fragmentShader) : m_shader(vertexShader, fragmentShader), m_vboID(0),
                                                                                             m_tailleVerticesBytes(108 * sizeof(float)),
                                                                                             m_tailleCouleursBytes(108 * sizeof(float)), m_vaoID(0)
{
    // Chargement du shader

    m_shader.charger();


    // Division de la taille

    taille /= 2;


    // Vertices temporaires

    float verticesTmp[] = {-taille, -taille, -taille,   taille, -taille, -taille,   taille, taille, -taille,     // Face 1
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
                           -taille, taille, taille,   -taille, taille, -taille,   taille, taille, -taille};      // Face 6


    // Couleurs temporaires

    float couleursTmp[] = {1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1
                           1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 1

                           0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2
                           0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 2

                           0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3
                           0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 3

                           1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 4
                           1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0,           // Face 4

                           0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 5
                           0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0,           // Face 5

                           0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0,           // Face 6
                           0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0};          // Face 6


    // Copie des valeurs dans les tableaux finaux

    for(int i(0); i < 108; i++)
    {
        m_vertices[i] = verticesTmp[i];
        m_couleurs[i] = couleursTmp[i];
    }
}


Cube::~Cube()
{
    // Destruction du VBO

    glDeleteBuffers(1, &m_vboID);


    // Destruction du VAO

    glDeleteVertexArrays(1, &m_vaoID);
}


// M�thodes

void Cube::charger()
{
    // Destruction d'un �ventuel ancien VBO

    if(glIsBuffer(m_vboID) == GL_TRUE)
        glDeleteBuffers(1, &m_vboID);


    // G�n�ration de l'ID

    glGenBuffers(1, &m_vboID);


    // Verrouillage du VBO

    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);


        // Allocation de la m�moire vid�o

        glBufferData(GL_ARRAY_BUFFER, m_tailleVerticesBytes + m_tailleCouleursBytes, 0, GL_STATIC_DRAW);


        // Transfert des donn�es

        glBufferSubData(GL_ARRAY_BUFFER, 0, m_tailleVerticesBytes, m_vertices);
        glBufferSubData(GL_ARRAY_BUFFER, m_tailleVerticesBytes, m_tailleCouleursBytes, m_couleurs);


    // D�verrouillage de l'objet

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    // Destruction d'un �ventuel ancien VAO

    if(glIsVertexArray(m_vaoID) == GL_TRUE)
        glDeleteVertexArrays(1, &m_vaoID);


    // G�n�ration de l'identifiant du VAO

    glGenVertexArrays(1, &m_vaoID);


    // Verrouillage du VAO

    glBindVertexArray(m_vaoID);


        // Verrouillage du VBO

        glBindBuffer(GL_ARRAY_BUFFER, m_vboID);


            // Acc�s aux vertices dans la m�moire vid�o

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
            glEnableVertexAttribArray(0);


            // Acc�s aux couleurs dans la m�moire vid�o

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(m_tailleVerticesBytes));
            glEnableVertexAttribArray(1);


        // D�verrouillage du VBO

        glBindBuffer(GL_ARRAY_BUFFER, 0);


    // D�verrouillage du VAO

    glBindVertexArray(0);
}


void Cube::afficher(glm::mat4 &projection, glm::mat4 &modelview)
{
    // Activation du shader

    glUseProgram(m_shader.getProgramID());


        // Verrouillage du VAO

        glBindVertexArray(m_vaoID);


            // Envoi des matrices

            m_shader.envoyerMat4("modelviewProjection", projection * modelview);
    

            // Rendu

            glDrawArrays(GL_TRIANGLES, 0, 36);


        // D�verrouillage du VAO

        glBindVertexArray(0);


    // D�sactivation du shader

    glUseProgram(0);
}


void Cube::updateVBO(void *donnees, int tailleBytes, int decalage)
{
    // Verrouillage du VBO

    glBindBuffer(GL_ARRAY_BUFFER, m_vboID);


        // R�cup�ration de l'adresse du VBO

        void *adresseVBO = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);


        // Si l'adresse retourn�e est nulle alors on arr�te le transfert

        if(adresseVBO == NULL)
        {
            std::cout << "Erreur au niveau de la r�cup�ration du VBO" << std::endl;
            glBindBuffer(GL_ARRAY_BUFFER, 0);

            return;
        }


        // Mise � jour des donn�es

        memcpy((char*)adresseVBO + decalage, donnees, tailleBytes);


        // Annulation du pointeur

        glUnmapBuffer(GL_ARRAY_BUFFER);
        adresseVBO = 0;


    // D�verrouillage du VBO

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
