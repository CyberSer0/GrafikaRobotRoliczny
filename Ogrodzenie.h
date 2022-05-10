#pragma once

#include "Prostopadloscian.h"
#include "Walec.h"

class Ogrodzenie
{
private:
	struct Vector3
	{
		GLfloat x;
		GLfloat y;
		GLfloat z;
	};
	Prostopadloscian	*pien_1, *pien_2, *pien_3, *pien_4,
						*srodek1_1, *srodek1_2, *srodek2_1,
						*srodek2_2, *srodek3_1, *srodek3_2;
	GLfloat kolorCiemnoZielony[3] = { 0.f, 0.5f, 0.f };
	GLfloat kolorCiemnoCiemnoCzerwony[3] = { 0.25f, 0.f, 0.f };
public:
	Ogrodzenie(Vector3 pozycja, GLfloat rozmiar);
	~Ogrodzenie();
	void draw();
};
