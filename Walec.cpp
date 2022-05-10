#include "Walec.h"

Walec::Walec()
{
	m_posX = 0.f;
	m_posY = 0.f;
	m_posZ = 0.f;
	m_promien = 1.f;
	m_dlugosc = 1.f;
	kolor[0] = 0.5f;
	kolor[1] = 0.5f;
	kolor[2] = 0.5f;
}

Walec::Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
{
	m_posX = posX;
	m_posY = posY;
	m_posZ = posZ;
	m_promien = promien;
	m_dlugosc = dlugosc;
}

Walec::~Walec()
{
	
}

void Walec::draw()
{
	glColor3f(kolor[0], kolor[1], kolor[2]);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(m_posX, m_posY, m_posZ);
	for (int i = 0; i <= 20; i++)
	{
		glVertex3f(m_posX + (m_promien * cos(i * 2.0f * 3.14 / 20)),
			m_posY + (m_promien * sin(i * 2.0f * 3.14 / 20)), 0 + m_posZ);
	}

	int i = 21;
	glVertex3f(m_posX + (m_promien * cos(i * 2.0f * 3.14 / 20)),
		m_posY + (m_promien * sin(i * 2.0f * 3.14 / 20)), 0 + m_posZ);

	glEnd();
	glColor3f(kolor[0], kolor[1], kolor[2]);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(m_posX, m_posY, m_posZ + m_dlugosc);
	for (int i = 0; i <= 20; i++)
	{
		glVertex3f(m_posX + (m_promien * cos(i * 2.0f * 3.14 / 20)),
			m_posY + (m_promien * sin(i * 2.0f * 3.14 / 20)), m_dlugosc + m_posZ);
	}
	i = 21;
	glVertex3f(m_posX + (m_promien * cos(i * 2.0f * 3.14 / 20)),
		m_posY + (m_promien * sin(i * 2.0f * 3.14 / 20)), m_dlugosc + m_posZ);

	glEnd();

	int j = 0;
	glColor3f(kolor[0] * 0.88f, kolor[1] * 0.88f, kolor[2] * 0.88f);
	glBegin(GL_TRIANGLE_STRIP);

	for (j = 0; j <= 20; j++)
	{
		glVertex3f(m_posX + (m_promien * cos(j * 2.0f * 3.14 / 20)),
			m_posY + (m_promien * sin(j * 2.0f * 3.14 / 20)), m_dlugosc + m_posZ);
		glVertex3f(m_posX + (m_promien * cos(j * 2.0f * 3.14 / 20)),
			m_posY + (m_promien * sin(j * 2.0f * 3.14 / 20)), 0 + m_posZ);

	}
	glEnd();
}

void Walec::setColor(GLfloat red, GLfloat green, GLfloat blue)
{
	kolor[0] = red;
	kolor[1] = green;
	kolor[2] = blue;
}
