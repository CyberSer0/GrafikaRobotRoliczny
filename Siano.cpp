#include "Siano.h"

Siano::Siano(Vector3 pozycja, GLfloat rozmiar)
{
	// ---------------------------------------------------------------------------------------------
	// ==   prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ==   Walec(GLfloat promien, GLfloat dlugosc, GLfloat posX, GLfloat posY, GLfloat posZ)
	// ---------------------------------------------------------------------------------------------

	m_rozmiar = rozmiar;
	kolor[0] = 0.75f;
	kolor[1] = 0.90f;
	kolor[2] = 0.f;

	// siano bela 1 dó³
	siano_1 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, (pozycja.x + 48.f) * m_rozmiar, pozycja.y * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_1->setColor(kolor[0], kolor[1], kolor[2]);

	// siano bela 2 dó³
	siano_2 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, pozycja.x * m_rozmiar, pozycja.y * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_2->setColor(kolor[0], kolor[1], kolor[2]);

	// siano bela 3 dó³
	siano_3 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, (pozycja.x - 48.f) * m_rozmiar, pozycja.y * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_3->setColor(kolor[0], kolor[1], kolor[2]);

	// siano bela 4 œrodek 
	siano_4 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, (pozycja.x - 24.f) * m_rozmiar, (pozycja.y + 32.f) * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_4->setColor(kolor[0], kolor[1], kolor[2]);

	// siano bela 5 œrodek
	siano_5 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, (pozycja.x + 24.f) * m_rozmiar, (pozycja.y + 32.f) * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_5->setColor(kolor[0], kolor[1], kolor[2]);

	// siano bela 6 góra
	siano_6 = new Walec(20.f * m_rozmiar, 50.f * m_rozmiar, pozycja.x * m_rozmiar, (pozycja.y + 64.f) * m_rozmiar, (pozycja.z - 25.f) * m_rozmiar);
	siano_6->setColor(kolor[0], kolor[1], kolor[2]);
}

Siano::~Siano()
{
	delete	siano_1, siano_2, siano_3,
			siano_4, siano_5, siano_6;
}

void Siano::draw()
{
	siano_1->draw();
	siano_2->draw();
	siano_3->draw();
	siano_4->draw();
	siano_5->draw();
	siano_6->draw();
}
