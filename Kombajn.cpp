#include "Kombajn.h"

Kombajn::Kombajn(GLfloat rozmiar)
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

	// Podwozie
	Prostopadloscian podwozie = Prostopadloscian(100.f * rozmiar, 30.f * rozmiar, 45.f * rozmiar, -65.f * rozmiar, -5.f * rozmiar, -22.5f * rozmiar, kolorCiemnoSzary);
	
	// Nadwozie
	Prostopadloscian nadwozie = Prostopadloscian(150.f * rozmiar, 45.f * rozmiar, 75.f * rozmiar, -65.f * rozmiar, 22.5f * rozmiar, -37.5f * rozmiar, kolorCiemnoCiemnoCzerwony);
	
	// Kokpit
	Prostopadloscian kokpit = Prostopadloscian(25.f * rozmiar, 50.f * rozmiar, 40.f * rozmiar, -85.f * rozmiar, 20.f * rozmiar, -20.f * rozmiar, kolorJasnoNiebieski);

	// Zbierak
	Walec zbierak = Walec(15.f * rozmiar, 70.f * rozmiar, -80.f * rozmiar, 0.f * rozmiar, -35.f * rozmiar, kolorJasnoSzary);

	// Rura do zrzucania
	// Rurka 1
	Prostopadloscian rurka1 = Prostopadloscian(5.f * rozmiar, 15.f * rozmiar, 5.f * rozmiar, -60.f * rozmiar, 65.f * rozmiar, -30.f * rozmiar, kolorCiemnoNiebieski);
	//Rurka 2
	Prostopadloscian rurka2 = Prostopadloscian(80.f * rozmiar, 7.5f * rozmiar, 7.5f * rozmiar, -60.f * rozmiar, 72.5f * rozmiar, -31.5f * rozmiar, kolorCiemnoNiebieski);

	// Ko�o prz�d lewo du�e
	Walec koloPrzodLewoDuze = Walec(20.f * rozmiar, 10.f * rozmiar, -45.f * rozmiar, 0.f * rozmiar, 20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaPrzodLewoDuza = Walec(10.f * rozmiar, 10.f * rozmiar, -45.f * rozmiar, 0.f * rozmiar, 22.5f * rozmiar, kolorJasnoSzary);

	// Ko�o prz�d prawo du�e
	Walec koloPrzodPrawoDuze = Walec(20.f * rozmiar, -10.f * rozmiar, -45.f * rozmiar, 0.f * rozmiar, -20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaPrzodPrawoDuza = Walec(10.f * rozmiar, -10.f * rozmiar, -45.f * rozmiar, 0.f * rozmiar, -22.5f * rozmiar, kolorJasnoSzary);

	// Ko�o �rodek lewo ma�e
	Walec koloSrodekLewoMale = Walec(15.f * rozmiar, 10.f * rozmiar, -7.5f * rozmiar, -5.f * rozmiar, 20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaSrodekLewoMala = Walec(7.5f * rozmiar, 10.f * rozmiar, -7.5f * rozmiar, -5.f * rozmiar, 22.5f * rozmiar, kolorJasnoSzary);

	// Ko�o �rodek prawo ma�e
	Walec koloSrodekPrawoMale = Walec(15.f * rozmiar, -10.f * rozmiar, -7.5f * rozmiar, -5.f * rozmiar, -20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaSrodekPrawoMala = Walec(7.5f * rozmiar, -10.f * rozmiar, -7.5f * rozmiar, -5.f * rozmiar, -22.5f * rozmiar, kolorJasnoSzary);

	// Ko�o ty� lewo ma�e
	Walec koloTylLewoMale = Walec(15.f * rozmiar, 10.f * rozmiar, 25.f * rozmiar, -5.f * rozmiar, 20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaTylLewoMala = Walec(7.5f * rozmiar, 10.f * rozmiar, 25.f * rozmiar, -5.f * rozmiar, 22.5f * rozmiar, kolorJasnoSzary);

	// Ko�o ty� prawo ma�e
	Walec koloTylPrawoMale = Walec(15.f * rozmiar, -10.f * rozmiar, 25.f * rozmiar, -5.f * rozmiar, -20.f * rozmiar, kolorCiemnoCiemnoSzary);
	Walec felgaTylPrawoMala = Walec(7.5f * rozmiar, -10.f * rozmiar, 25.f * rozmiar, -5.f * rozmiar, -22.5f * rozmiar, kolorJasnoSzary);

	//Prostopadloscian(40.0f * rozmiar, 20.0f * rozmiar, 30.0f * rozmiar, 0.f * rozmiar, 0.f * rozmiar, 10.f * rozmiar); // dolny
	//Prostopadloscian(60.0f * rozmiar, 30.f * rozmiar, 30.0f * rozmiar, 0.0f * rozmiar, 30.0f * rozmiar, 0.0f * rozmiar); // gorny

	//Walec(15.0f * rozmiar, 10.0f * rozmiar, 15.0f * rozmiar, 2.0f * rozmiar, 5.0f * rozmiar); // przod
	//Walec(15.0f * rozmiar, 10.0f * rozmiar, 15.0f * rozmiar, 2.0f * rozmiar, 55.0f * rozmiar); // prodz

	//Walec(10.0f * rozmiar, 12.0f * rozmiar, 46.0f * rozmiar, 0.0f * rozmiar, 5.0f * rozmiar); // srodek
	//Walec(10.0f * rozmiar, 12.0f * rozmiar, 46.0f * rozmiar, 0.0f * rozmiar, 55.0f * rozmiar); // srodek

	//Walec(10.0f * rozmiar, 12.0f * rozmiar, 75.0f * rozmiar, 0.0f * rozmiar, 5.0f * rozmiar); // tyl
	//Walec(10.0f * rozmiar, 12.0f * rozmiar, 75.0f * rozmiar, 0.0f * rozmiar, 55.0f * rozmiar); // tyl

	//Walec(70.0f * rozmiar, 13.0f * rozmiar, -13.0f * rozmiar, 10.0f * rozmiar, 0.0f * rozmiar); // zbierak

	//Prostopadloscian(30.0f * rozmiar, 15.f * rozmiar, 25.0f * rozmiar, -15.0f * rozmiar, 30.0f * rozmiar, 15.0f * rozmiar); // kabina 

	//Prostopadloscian(10.0f * rozmiar, 5.f * rozmiar, 5.0f * rozmiar, 80.0f * rozmiar, 0.0f * rozmiar, 25.0f * rozmiar); // orka
}

Kombajn::~Kombajn()
{
}
