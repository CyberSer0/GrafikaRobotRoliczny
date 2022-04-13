#include "Walec.h"

Walec::Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat kolory[3])
{
	glColor3f(kolory[0], kolory[1], kolory[2]);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(posX, posY, posZ);
	for (int i = 0; i <= 20; i++)
	{
		glVertex3f(posX + (promien * cos(i * 2.0f * 3.14 / 20)),
			posY + (promien * sin(i * 2.0f * 3.14 / 20)), 0 + posZ);
	}

	int i = 21;
	glVertex3f(posX + (promien * cos(i * 2.0f * 3.14 / 20)),
		posY + (promien * sin(i * 2.0f * 3.14 / 20)), 0 + posZ);

	glEnd();
	glColor3f(kolory[0], kolory[1], kolory[2]);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(posX, posY, posZ + dlugosc);
	for (int i = 0; i <= 20; i++)
	{
		glVertex3f(posX + (promien * cos(i * 2.0f * 3.14 / 20)),
			posY + (promien * sin(i * 2.0f * 3.14 / 20)), dlugosc + posZ);
	}
	i = 21;
	glVertex3f(posX + (promien * cos(i * 2.0f * 3.14 / 20)),
		posY + (promien * sin(i * 2.0f * 3.14 / 20)), dlugosc + posZ);

	glEnd();

	int j = 0;
	glColor3f(kolory[0], kolory[1], kolory[2]);
	glBegin(GL_TRIANGLE_STRIP);

	for (j = 0; j <= 20; j++)
	{
		glVertex3f(posX + (promien * cos(j * 2.0f * 3.14 / 20)),
			posY + (promien * sin(j * 2.0f * 3.14 / 20)), dlugosc + posZ);
		glVertex3f(posX + (promien * cos(j * 2.0f * 3.14 / 20)),
			posY + (promien * sin(j * 2.0f * 3.14 / 20)), 0 + posZ);

	}
	glEnd();
}

Walec::~Walec()
{

}