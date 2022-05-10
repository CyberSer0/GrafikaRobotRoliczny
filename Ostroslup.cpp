#include "Ostroslup.h"

Ostroslup::Ostroslup(GLfloat dlugosc, GLfloat szerokosc, GLfloat wysokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
{
	spod1[0] = posX + dlugosc / 2;
	spod1[1] = posY;
	spod1[2] = posZ + szerokosc / 2;

	spod2[0] = posX - dlugosc / 2;
	spod2[1] = posY;
	spod2[2] = posZ + szerokosc / 2;

	spod3[0] = posX + dlugosc / 2;
	spod3[1] = posY;
	spod3[2] = posZ - szerokosc / 2;

	spod4[0] = posX - dlugosc / 2;
	spod4[1] = posY;
	spod4[2] = posZ - szerokosc / 2;

	wierzcholek[0] = posX;
	wierzcholek[1] = posY + wysokosc;
	wierzcholek[2] = posZ;

	kolory[0] = 0.4f;
	kolory[1] = 0.1f;
	kolory[2] = 0.0f;
}

Ostroslup::~Ostroslup()
{

}

void Ostroslup::draw()
{
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

	glBegin(GL_TRIANGLES);
	glVertex3f(spod1[0], spod1[1], spod1[2]);
	glVertex3f(spod3[0], spod3[1], spod3[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(spod3[0], spod3[1], spod3[2]);
	glVertex3f(spod4[0], spod4[1], spod4[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(spod4[0], spod4[1], spod4[2]);
	glVertex3f(spod2[0], spod2[1], spod2[2]);
	glVertex3f(wierzcholek[0], wierzcholek[1], wierzcholek[2]);
	glEnd();
}
