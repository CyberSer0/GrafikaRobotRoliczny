#include "Dom.h"

Dom::Dom(Vector3 pozycja, GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// Ostroslup(	GLfloat dlugosc, GLfloat szerokosc, GLfloat wysokosc, GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat kolory[3]);
	// ---------------------------------------------------------------------------------------------
	
	GLfloat kolorCiemnoSzary[3] = { 0.2f, 0.2f, 0.2f };
	GLfloat kolorCzerwony[3] = { 1.f, 0.f, 0.f };

	// domek
	dom = new Prostopadloscian(175.f * rozmiar, 70.f * rozmiar, 120.f * rozmiar, (pozycja.x - 87.5f) * rozmiar, pozycja.y * rozmiar, (pozycja.z - 60.f) * rozmiar);
	dom->setColor(kolorCzerwony[0], kolorCzerwony[1], kolorCzerwony[2]);

	// daszek
	dach = new Ostroslup(190.f *rozmiar, 150.f*rozmiar, 120.f*rozmiar, pozycja.x * rozmiar, (pozycja.y + 70.f) * rozmiar, pozycja.z * rozmiar);
}

Dom::~Dom()
{
	delete dom;
	delete dach;
}

void Dom::draw()
{
	dom->draw();
	dach->draw();
}
