#pragma once

#include "Prostopadloscian.h"
#include "Walec.h"
#include "Ostroslup.h"

class Dom
{
private:
	struct Vector3
	{
		GLfloat x;
		GLfloat y;
		GLfloat z;
	};
	Prostopadloscian* dom;
	Ostroslup* dach;
public:
	Dom(Vector3 pozycja, GLfloat rozmiar);
	~Dom();
	void draw();
};
