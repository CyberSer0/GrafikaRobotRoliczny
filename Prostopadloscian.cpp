#include "Prostopadloscian.h"

Prostopadloscian::Prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
{
	//rozmiar = 30.0f;
	//glBegin(GL_TRIANGLE_STRIP);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Parametry wierzcholkow

	sa[0] = posX;
	sa[1] = posY;
	sa[2] = posZ + szerokosc;

	sb[0] = posX;
	sb[1] = posY;
	sb[2] = posZ;

	sc[0] = posX + dlugosc;
	sc[1] = posY;
	sc[2] = posZ;

	sd[0] = posX + dlugosc;
	sd[1] = posY;
	sd[2] = posZ + szerokosc;

	se[0] = posX;
	se[1] = posY + wysokosc;
	se[2] = posZ + szerokosc;

	sf[0] = posX;
	sf[1] = posY + wysokosc;
	sf[2] = posZ;

	sg[0] = posX + dlugosc;
	sg[1] = posY + wysokosc;
	sg[2] = posZ;

	sh[0] = posX + dlugosc;
	sh[1] = posY + wysokosc;
	sh[2] = posZ + szerokosc;

	kolor[0] = 0.5f;
	kolor[1] = 0.5f;
	kolor[2] = 0.5f;
}


Prostopadloscian::~Prostopadloscian() 
{
	
}


void Prostopadloscian::draw()
{
	// Sciany skladowe
	// Spodnia
	glColor3f(kolor[0] * 0.75f, kolor[1] * 0.75f, kolor[2] * 0.75f);
	glBegin(GL_POLYGON);
	glVertex3fv(sa);
	glVertex3fv(sb);
	glVertex3fv(sc);
	glVertex3fv(sd);
	glEnd();

	// Najdalsza od kamery
	glColor3f(kolor[0] * 0.88f, kolor[1] * 0.88f, kolor[2] * 0.88f);
	glBegin(GL_POLYGON);
	glVertex3fv(sb);
	glVertex3fv(sf);
	glVertex3fv(sg);
	glVertex3fv(sc);
	glEnd();

	// Górna
	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_POLYGON);
	glVertex3fv(sf);
	glVertex3fv(se);
	glVertex3fv(sh);
	glVertex3fv(sg);
	glEnd();

	// Najbli¿sza kamery
	glColor3f(kolor[0] * 0.88f, kolor[1] * 0.88f, kolor[2] * 0.88f);
	glBegin(GL_POLYGON);
	glVertex3fv(se);
	glVertex3fv(sa);
	glVertex3fv(sd);
	glVertex3fv(sh);
	glEnd();

	// Prawa
	glColor3f(kolor[0] * 0.95f, kolor[1] * 0.95f, kolor[2] * 0.95f);
	glBegin(GL_POLYGON);
	glVertex3fv(sd);
	glVertex3fv(sc);
	glVertex3fv(sg);
	glVertex3fv(sh);
	glEnd();

	// Lewa
	glColor3f(kolor[0] * 0.95f, kolor[1] * 0.95f, kolor[2] * 0.95f);
	glBegin(GL_POLYGON);
	glVertex3fv(sb);
	glVertex3fv(sa);
	glVertex3fv(se);
	glVertex3fv(sf);
	glEnd();

}

void Prostopadloscian::setColor(GLfloat red, GLfloat green, GLfloat blue)
{
	kolor[0] = red;
	kolor[1] = green;
	kolor[2] = blue;
}
