#include "Siano.h"

Siano::Siano(GLfloat rozmiar)
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

	// siano bela 1 dó³
	Walec siano_1 = Walec(20.f * rozmiar, 50.f * rozmiar, -100.f * rozmiar, 0.f * rozmiar, -130.f * rozmiar, kolorJasnoNiebieski);

	// siano bela 2 dó³
	Walec siano_2 = Walec(20.f * rozmiar, 50.f * rozmiar, -55.f * rozmiar, 0.f * rozmiar, -130.f * rozmiar, kolorJasnoNiebieski);

	// siano bela 3 dó³
	Walec siano_3 = Walec(20.f * rozmiar, 50.f * rozmiar, -10.f * rozmiar, 0.f * rozmiar, -130.f * rozmiar, kolorJasnoNiebieski);

	// siano bela 4 œrodek 
	Walec siano_4 = Walec(20.f * rozmiar, 50.f * rozmiar, -77.5f * rozmiar, 32.f * rozmiar, -130.f * rozmiar, kolorCiemnoNiebieski);

	// siano bela 5 œrodek
	Walec siano_5 = Walec(20.f * rozmiar, 50.f * rozmiar, -32.5f * rozmiar, 32.f * rozmiar, -130.f * rozmiar, kolorCiemnoNiebieski);

	// siano bela 6 góra
	Walec siano_6 = Walec(20.f * rozmiar, 50.f * rozmiar, -55.f * rozmiar, 64.f * rozmiar, -130.f * rozmiar, kolorCiemnoCzerwony);
}

Siano::~Siano()
{
}
