#pragma once

#include <GL/glew.h>
#include <math.h>

class Walec
{
public:
	Walec(	GLfloat promien, GLfloat wysokosc,
			GLfloat posX, GLfloat posY,
			GLfloat posZ, GLfloat kolory[3]);
	~Walec();
};