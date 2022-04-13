#include "Prostopadloscian.h"

Prostopadloscian::Prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat kolor[3])
{
	//rozmiar = 30.0f;
	//glBegin(GL_TRIANGLE_STRIP);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Parametry wierzcholkow

	GLfloat sa[3] = { posX,				posY,				posZ};
	GLfloat sb[3] = { posX,				posY,				posZ + szerokosc};
	GLfloat sc[3] = { posX + dlugosc,	posY,				posZ + szerokosc};
	GLfloat sd[3] = { posX + dlugosc,	posY,				posZ};
	GLfloat se[3] = { posX,				posY + wysokosc,	posZ};
	GLfloat sf[3] = { posX,				posY + wysokosc,	posZ + szerokosc};
	GLfloat sg[3] = { posX + dlugosc,	posY + wysokosc,	posZ + szerokosc};
	GLfloat sh[3] = { posX + dlugosc,	posY + wysokosc,	posZ};

	// Sciany skladowe
	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sa);
	glVertex3fv(sb);
	glVertex3fv(sc);
	glVertex3fv(sd);
	glEnd();

	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sb);
	glVertex3fv(sf);
	glVertex3fv(sg);
	glVertex3fv(sc);
	glEnd();

	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sf);
	glVertex3fv(se);
	glVertex3fv(sh);
	glVertex3fv(sg);
	glEnd();

	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(se);
	glVertex3fv(sa);
	glVertex3fv(sd);
	glVertex3fv(sh);
	glEnd();

	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sd);
	glVertex3fv(sc);
	glVertex3fv(sg);
	glVertex3fv(sh);
	glEnd();

	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sa);
	glVertex3fv(sb);
	glVertex3fv(sf);
	glVertex3fv(se);
	glEnd();
}

Prostopadloscian::~Prostopadloscian() 
{

}