#pragma once

#include "Prostopadloscian.h"
#include "Walec.h"

class Siano
{
private:
	struct Vector3
	{
		GLfloat x;
		GLfloat y;
		GLfloat z;
	};
	Walec	*siano_1, *siano_2, *siano_3,
			*siano_4, *siano_5, *siano_6;
	GLfloat m_rozmiar;
	GLfloat kolor[3];
public:
	Siano(Vector3 pozycja, GLfloat rozmiar);
	~Siano();
	void draw();
};
