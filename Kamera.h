#pragma once
#include <GL/glew.h>

class Kamera
{
public:
	Kamera(	GLfloat PozycjaPoczX,
			GLfloat PozycjaPoczY,
			GLfloat PozycjaPoczZ,

			GLfloat PozyczjaNaKtoraPatrzyX,
			GLfloat PozyczjaNaKtoraPatrzyY,
			GLfloat PozyczjaNaKtoraPatrzyZ,

			GLfloat OrientacjaX,	
			GLfloat OrientacjaY,	
			GLfloat OrientacjaZ);

	~Kamera();
};

