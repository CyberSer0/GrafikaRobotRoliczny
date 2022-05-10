#pragma once

#include <GL/glew.h>

class Prostopadloscian
{
private:
	GLfloat sa[3];
	GLfloat sb[3];
	GLfloat sc[3];
	GLfloat sd[3];
	GLfloat se[3];
	GLfloat sf[3];
	GLfloat sg[3];
	GLfloat sh[3];
	GLfloat kolor[3];
public:
	Prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ);
	~Prostopadloscian();
	void draw();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};