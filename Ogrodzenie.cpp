#include "Ogrodzenie.h"

Ogrodzenie::Ogrodzenie(Vector3 pozycja, GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ---------------------------------------------------------------------------------------------

	GLfloat kolorCiemnoZielony[3] = { 0.f, 0.5f, 0.f };
	GLfloat kolorCiemnoCiemnoCzerwony[3] = { 0.25f, 0.f, 0.f };

	// pien 1
	pien_1 = new Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, pozycja.x * rozmiar, (pozycja.y) * rozmiar, (pozycja.z - 75.f) * rozmiar);
	pien_1->setColor(kolorCiemnoCiemnoCzerwony[0], kolorCiemnoCiemnoCzerwony[1], kolorCiemnoCiemnoCzerwony[2]);

	//srodek 1/1
	srodek1_1 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 10.f) * rozmiar, (pozycja.z - 65.f) * rozmiar);
	srodek1_1->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	//srodek 1/2
	srodek1_2 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 35.f) * rozmiar, (pozycja.z - 65.f) * rozmiar);
	srodek1_2->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	// pien 2
	pien_2 = new Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, pozycja.x * rozmiar, (pozycja.y) * rozmiar, (pozycja.z) * rozmiar);
	pien_2->setColor(kolorCiemnoCiemnoCzerwony[0], kolorCiemnoCiemnoCzerwony[1], kolorCiemnoCiemnoCzerwony[2]);

	//srodek 2/1
	srodek2_1 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 10.f) * rozmiar, (pozycja.z + 10.f) * rozmiar);
	srodek2_1->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	//srodek 2/2
	srodek2_2 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 35.f) * rozmiar, (pozycja.z + 10.f) * rozmiar);
	srodek2_2->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	// pien 3
	pien_3 = new Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, pozycja.x * rozmiar, (pozycja.y) * rozmiar, (pozycja.z + 75.f) * rozmiar);
	pien_3->setColor(kolorCiemnoCiemnoCzerwony[0], kolorCiemnoCiemnoCzerwony[1], kolorCiemnoCiemnoCzerwony[2]);

	//srodek 3/1
	srodek3_1 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 10.f) * rozmiar, (pozycja.z + 85.f) * rozmiar);
	srodek3_1->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	//srodek 3/2
	srodek3_2 = new Prostopadloscian(7.f * rozmiar, 7.f * rozmiar, 65.f * rozmiar, pozycja.x * rozmiar, (pozycja.y + 35.f) * rozmiar, (pozycja.z + 85.f) * rozmiar);
	srodek3_2->setColor(kolorCiemnoZielony[0], kolorCiemnoZielony[1], kolorCiemnoZielony[2]);

	// pien 4
	pien_4 = new Prostopadloscian(10.f * rozmiar, 50.f * rozmiar, 10.f * rozmiar, pozycja.x * rozmiar, (pozycja.y) * rozmiar, (pozycja.z + 150.f) * rozmiar);
	pien_4->setColor(kolorCiemnoCiemnoCzerwony[0], kolorCiemnoCiemnoCzerwony[1], kolorCiemnoCiemnoCzerwony[2]);
}


Ogrodzenie::~Ogrodzenie()
{
	delete pien_1;
	delete pien_2;
	delete pien_3;
	delete pien_4;
	delete srodek1_1;
	delete srodek1_2;
	delete srodek2_1;
	delete srodek2_2;
	delete srodek3_1;
	delete srodek3_2;
}

void Ogrodzenie::draw()
{
	pien_1->draw();
	pien_2->draw();
	pien_3->draw();
	pien_4->draw();
	srodek1_1->draw();
	srodek1_2->draw();
	srodek2_1->draw();
	srodek2_2->draw();
	srodek3_1->draw();
	srodek3_2->draw();
}
