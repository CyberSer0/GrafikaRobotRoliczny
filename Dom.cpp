#include "Dom.h"

Dom::Dom(GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ---------------------------------------------------------------------------------------------

	GLfloat kolorCiemnoZielony[3] = { 0.f, 0.5f, 0.f };
	GLfloat kolorCiemnoNiebieski[3] = { 0.f, 0.f, 0.5f };
	GLfloat kolorCiemnoCzerwony[3] = { 0.5f, 0.f, 0.f };
	GLfloat kolorCiemnoCiemnoCzerwony[3] = { 0.25f, 0.f, 0.f };
	GLfloat kolorCiemnoSzary[3] = { 0.2f, 0.2f, 0.2f };
	GLfloat kolorCiemnoCiemnoSzary[3] = { 0.1f, 0.1f, 0.1f };
	GLfloat kolorJasnoSzary[3] = { 0.5f, 0.5f, 0.5f };
	GLfloat kolorJasnoNiebieski[3] = { 0.f, 1.f, 1.f };
	GLfloat kolorCzerwony[3] = { 1.f, 0.f, 0.f };

	// domek
	Prostopadloscian dom = Prostopadloscian(175.f * rozmiar, 70.f * rozmiar, 120.f * rozmiar, -300.f * rozmiar, -20.f * rozmiar, -200.f * rozmiar, kolorCzerwony);

	// dach 1
	Prostopadloscian dach1 = Prostopadloscian(150.f * rozmiar, 30.f * rozmiar, 95.f * rozmiar, -300.f * rozmiar, 50.f * rozmiar, -200.f * rozmiar, kolorCiemnoNiebieski);

	// dach 2
	Prostopadloscian dach2 = Prostopadloscian(125.f * rozmiar, 30.f * rozmiar, 70.f * rozmiar, -300.f * rozmiar, 80.f * rozmiar, -200.f * rozmiar, kolorJasnoNiebieski);
}

Dom::~Dom()
{
}
