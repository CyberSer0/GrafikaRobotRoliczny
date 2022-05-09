#include "Ziemia.h"

Ziemia::Ziemia(GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ---------------------------------------------------------------------------------------------

	GLfloat kolorCiemnoZielony[3] = { 0.f, 0.5f, 0.f };
	GLfloat kolorCiemnoNiebieski[3] = { 0.f, 0.f, 0.5f };
	GLfloat kolorCiemnoCzerwony[3] = { 0.5f, 0.f, 0.f };
	GLfloat kolorCiemnoCiemnoCzerwony[3] = { 0.25f, 0.f, 0.f };
	GLfloat kolorCiemnoSzary[3] = { 0.2f, 0.2f, 0.2f };
	GLfloat kolorCiemnoCiemnoSzary[3] = { 0.1f, 0.1f, 0.1f };
	GLfloat kolorJasnoSzary[3] = { 0.5f, 0.5f, 0.5f };
	GLfloat kolorJasnoNiebieski[3] = { 0.f, 1.f, 1.f };
	GLfloat kolorZielony[3] = { 0.f, 1.f, 0.f };

    FILE* powierzchnia = fopen("powierzchnia.obj", "r");
    while (1)
    {
        char lineHeader[128];
        int res = fscanf(powierzchnia, "%s", lineHeader);
        if (res == EOF) break;
        if (strcmp(lineHeader, "f") == 0)
        {
            Vector3 face;
            fscanf(powierzchnia, "%f %f %f\n", &face.x, &face.y, &face.z);
            face.x--;
            face.y--;
            face.z--;
            faces.push_back(face);
        } else if (strcmp(lineHeader, "v") == 0)
        {
            Vector3 vertex;
            fscanf(powierzchnia, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }
    }
    
    for (int i = 0; i < faces.size(); i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(rand() * 0.5, rand() * 0.3, 0);
            glVertex3f(vertices[faces[i].x].x * rozmiar, (vertices[faces[i].x].y) * rozmiar, vertices[faces[i].x].z * rozmiar);
            glVertex3f(vertices[faces[i].y].x * rozmiar, (vertices[faces[i].y].y) * rozmiar, vertices[faces[i].y].z * rozmiar);
            glVertex3f(vertices[faces[i].z].x * rozmiar, (vertices[faces[i].z].y) * rozmiar, vertices[faces[i].z].z * rozmiar);
        glEnd();
    }

	//Prostopadloscian ziemia = Prostopadloscian(750.f * rozmiar, 0.f * rozmiar, 750.f * rozmiar, -450.f * rozmiar, -20.f * rozmiar, -450.f * rozmiar, kolorZielony);
}

Ziemia::~Ziemia()
{
}
