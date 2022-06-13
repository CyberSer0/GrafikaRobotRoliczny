#include "Prostopadloscian.h"

Prostopadloscian::Prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
{
	m_pos = {posX, posY, posZ};
	//rozmiar = 30.0f;
	//glBegin(GL_TRIANGLE_STRIP);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Parametry wierzcholkow

	sa[0] = posX - dlugosc / 2;
	sa[1] = posY;
	sa[2] = posZ + szerokosc / 2;

	sb[0] = posX - dlugosc / 2;
	sb[1] = posY;
	sb[2] = posZ - szerokosc / 2;

	sc[0] = posX + dlugosc / 2;
	sc[1] = posY;
	sc[2] = posZ - szerokosc / 2;

	sd[0] = posX + dlugosc / 2;
	sd[1] = posY;
	sd[2] = posZ + szerokosc / 2;

	se[0] = posX - dlugosc / 2;
	se[1] = posY + wysokosc;
	se[2] = posZ + szerokosc / 2;

	sf[0] = posX - dlugosc / 2;
	sf[1] = posY + wysokosc;
	sf[2] = posZ - szerokosc / 2;

	sg[0] = posX + dlugosc / 2;
	sg[1] = posY + wysokosc;
	sg[2] = posZ - szerokosc / 2;

	sh[0] = posX + dlugosc / 2;
	sh[1] = posY + wysokosc;
	sh[2] = posZ + szerokosc / 2;

	kolor[0] = 0.5f;
	kolor[1] = 0.5f;
	kolor[2] = 0.5f;

	vertices[0] = sa;
	vertices[1] = sb;
	vertices[2] = sc;
	vertices[3] = sd;
	vertices[4] = se;
	vertices[5] = sf;
	vertices[6] = sg;
	vertices[7] = sh;
	m_rotPoint = {0, 0, 0};
}


Prostopadloscian::~Prostopadloscian() 
{
	
}


void Prostopadloscian::draw()
{
	glPushMatrix();
	glRotatef(angle, 0, 1.0f, 0);
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

	glPopMatrix();
}

void Prostopadloscian::setColor(GLfloat red, GLfloat green, GLfloat blue)
{
	kolor[0] = red;
	kolor[1] = green;
	kolor[2] = blue;
}

void Prostopadloscian::move(glm::vec3 przemieszczenie)
{
	for (GLfloat* i : vertices)
	{
		i[0] += przemieszczenie.x;
		i[1] += przemieszczenie.y;
		i[2] += przemieszczenie.z;
	}
}

void Prostopadloscian::turn(GLfloat angle, glm::vec3 point)
{
	this->angle += angle;
	m_rotPoint = point;
}

GLfloat Prostopadloscian::getAngle() const
{
	return angle;
}