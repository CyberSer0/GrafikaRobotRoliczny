#pragma once

#include <GL/glew.h>
#include <cmath>

class Walec
{
private:
	GLfloat m_posX;
	GLfloat m_posY;
	GLfloat m_posZ;
	GLfloat m_promien;
	GLfloat m_dlugosc;
	GLfloat kolor[3];
public:
	Walec();
	Walec(	GLfloat promien, GLfloat wysokosc,
			GLfloat posX, GLfloat posY,
			GLfloat posZ);
	~Walec();
	void draw();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};