#include "Ziemia.h"

Ziemia::Ziemia(GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ---------------------------------------------------------------------------------------------

    
    FILE* powierzchnia = fopen("powierzchnia.obj", "r");
    if (powierzchnia == NULL) return;
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

            ColorRGB color;
            color.r = ((GLfloat)(rand() % 10000 + 1) / 10000.f) * 0.4f;
            color.g = ((GLfloat)(rand() % 10000 + 1) / 10000.f) * 0.25f + 0.5f;
            color.b = 0.f;
            colors.push_back(color);
        } else if (strcmp(lineHeader, "v") == 0)
        {
            Vector3 vertex;
            fscanf(powierzchnia, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
            vertices.push_back(vertex);
        }
    }

    m_rozmiar = rozmiar;

	//Prostopadloscian ziemia = Prostopadloscian(750.f * rozmiar, 0.f * rozmiar, 750.f * rozmiar, -450.f * rozmiar, -20.f * rozmiar, -450.f * rozmiar, kolorZielony);
}

Ziemia::~Ziemia()
{
}

void Ziemia::draw()
{
    for (int i = 0; i < faces.size(); i++)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(colors[i].r, colors[i].g, colors[i].b);
            glVertex3f(vertices[faces[i].x].x * m_rozmiar, (vertices[faces[i].x].y) * m_rozmiar, vertices[faces[i].x].z * m_rozmiar);
            glVertex3f(vertices[faces[i].y].x * m_rozmiar, (vertices[faces[i].y].y) * m_rozmiar, vertices[faces[i].y].z * m_rozmiar);
            glVertex3f(vertices[faces[i].z].x * m_rozmiar, (vertices[faces[i].z].y) * m_rozmiar, vertices[faces[i].z].z * m_rozmiar);
        glEnd();
    }
}
