#include "Ogrodzenie.h"

Ogrodzenie::Ogrodzenie(GLfloat rozmiar)
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

	// pien 1
	Prostopadloscian pien_1 = Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, -200.f * rozmiar, -20.f * rozmiar, -75.f * rozmiar, kolorCiemnoCiemnoCzerwony);

	//srodek 1/1
	Prostopadloscian srodek1_1 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, -10.f * rozmiar, -65.f * rozmiar, kolorCiemnoZielony);

	//srodek 1/2
	Prostopadloscian srodek1_2 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, 15.f * rozmiar, -65.f * rozmiar, kolorCiemnoZielony);

	// pien 2
	Prostopadloscian pien_2 = Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, -200.f * rozmiar, -20.f * rozmiar, 0.f * rozmiar, kolorCiemnoCiemnoCzerwony);

	//srodek 2/1
	Prostopadloscian srodek2_1 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, -10.f * rozmiar, 10.f * rozmiar, kolorCiemnoZielony);

	//srodek 2/2
	Prostopadloscian srodek2_2 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, 15.f * rozmiar, 10.f * rozmiar, kolorCiemnoZielony);

	// pien 3
	Prostopadloscian pien_3 = Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, -200.f * rozmiar, -20.f * rozmiar, 75.f * rozmiar, kolorCiemnoCiemnoCzerwony);

	//srodek 3/1
	Prostopadloscian srodek3_1 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, -10.f * rozmiar, 85.f * rozmiar, kolorCiemnoZielony);

	//srodek 3/2
	Prostopadloscian srodek3_2 = Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, -200.f * rozmiar, 15.f * rozmiar, 85.f * rozmiar, kolorCiemnoZielony);

	// pien 4
	Prostopadloscian pien_4 = Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, -200.f * rozmiar, -20.f * rozmiar, 150.f * rozmiar, kolorCiemnoCiemnoCzerwony);
}


Ogrodzenie::~Ogrodzenie()
{
}
