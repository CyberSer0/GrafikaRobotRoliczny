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
        if (strcmp(lineHeader, "v") == 0)
        {
            Vector3 vertex;
            fscanf(powierzchnia, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }
    }
    
    int colorSwitch = 0;
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i < vertices.size(); i++)
    {
        switch (colorSwitch)
        {
        case 0:
            glColor3f(kolorZielony[0], kolorZielony[1], kolorZielony[2]);
            colorSwitch = 1;
        case 1:
            glColor3f(kolorCiemnoCzerwony[0], kolorCiemnoCzerwony[1], kolorCiemnoCzerwony[2]);
            colorSwitch = 0;
        }
        glVertex3f(vertices[i].x * rozmiar, (vertices[i].y - 10.f) * rozmiar, vertices[i].z * rozmiar);
    }
    glEnd();

	//Prostopadloscian ziemia = Prostopadloscian(750.f * rozmiar, 0.f * rozmiar, 750.f * rozmiar, -450.f * rozmiar, -20.f * rozmiar, -450.f * rozmiar, kolorZielony);
}

Ziemia::~Ziemia()
{
}
