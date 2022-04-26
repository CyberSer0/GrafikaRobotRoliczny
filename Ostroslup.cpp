#include "Ostroslup.h"

Ostroslup::Ostroslup(GLfloat dlugosc, GLfloat szerokosc, GLfloat wysokosc, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat kolory[3])
{
	GLfloat spod1[3] = { posX + dlugosc / 2, posY, posZ + szerokosc / 2 };
	GLfloat spod2[3] = { posX - dlugosc / 2, posY, posZ + szerokosc / 2 };
	GLfloat spod3[3] = { posX + dlugosc / 2, posY, posZ - szerokosc / 2 };
	GLfloat spod4[3] = { posX - dlugosc / 2, posY, posZ - szerokosc / 2 };
	GLfloat wierzcholek[3] = {0, posY + wysokosc, 0};
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glColor3f(0.25f, 0.25f, 0.25f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(spod1[0], spod1[1], spod1[2]);
	glVertex3f(spod2[0], spod2[1], spod2[2]);
	glVertex3f(spod3[0], spod3[1], spod3[2]);
	glVertex3f(spod4[0], spod4[1], spod4[2]);
	glEnd();

	glColor3f(kolory[0], kolory[1], kolory[2]);
	glBegin(GL_TRIANGLES);
	glVertex3f(spod1[0], spod1[1], spod1[2]);
	glVertex3f(spod2[0], spod2[1], spod2[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();

	glColor3f(kolory[0] - 0.25f, kolory[1] - 0.25f, kolory[2] + 0.25f);
	glBegin(GL_TRIANGLES);
	glVertex3f(spod1[0], spod1[1], spod1[2]);
	glVertex3f(spod3[0], spod3[1], spod3[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();

	glColor3f(kolory[0] + 0.25f, kolory[1] -0.25f, kolory[2] - 0.25f);
	glBegin(GL_TRIANGLES);
	glVertex3f(spod3[0], spod3[1], spod3[2]);
	glVertex3f(spod4[0], spod4[1], spod4[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();

	glColor3f(kolory[0] - 0.25f, kolory[1] -0.25f, kolory[2] - 0.25f);
	glBegin(GL_TRIANGLES);
	glVertex3f(spod4[0], spod4[1], spod4[2]);
	glVertex3f(spod2[0], spod2[1], spod2[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();
}

Ostroslup::~Ostroslup()
{

}