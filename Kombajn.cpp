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

	m_poz = {-15.f, 15.f, 0.f};

	// Podwozie
	podwozie = new Prostopadloscian(100.f * rozmiar, 30.f * rozmiar, 45.f * rozmiar, -15.f * rozmiar, 15.f * rozmiar, 0.f * rozmiar);
	podwozie->setColor(kolorCiemnoSzary[0], kolorCiemnoSzary[1], kolorCiemnoSzary[2]);
	
	// Nadwozie
	nadwozie = new Prostopadloscian(150.f * rozmiar, 45.f * rozmiar, 75.f * rozmiar, 5.f * rozmiar, 42.5f * rozmiar, 0.f * rozmiar);
	nadwozie->setColor(kolorCiemnoCiemnoCzerwony[0], kolorCiemnoCiemnoCzerwony[1], kolorCiemnoCiemnoCzerwony[2]);

	// Kokpit
	kokpit = new Prostopadloscian(25.f * rozmiar, 50.f * rozmiar, 40.f * rozmiar, -65.f * rozmiar, 40.f * rozmiar, 0.f * rozmiar);
	kokpit->setColor(kolorJasnoNiebieski[0], kolorJasnoNiebieski[1], kolorJasnoNiebieski[2]);

	// Zbierak
	zbierak = new Walec(15.f * rozmiar, 70.f * rozmiar, -80.f * rozmiar, 20.f * rozmiar, -35.f * rozmiar);
	zbierak->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Rura do zrzucania
	// Rurka 1
	rurka1 = new Prostopadloscian(5.f * rozmiar, 15.f * rozmiar, 5.f * rozmiar, -40.f * rozmiar, 85.f * rozmiar, -15.f * rozmiar);
	rurka1->setColor(kolorCiemnoNiebieski[0], kolorCiemnoNiebieski[1], kolorCiemnoNiebieski[2]);

	//Rurka 2
	rurka2 = new Prostopadloscian(80.f * rozmiar, 7.5f * rozmiar, 7.5f * rozmiar, 0.f * rozmiar, 95.f * rozmiar, -15.f * rozmiar);
	rurka2->setColor(kolorCiemnoNiebieski[0], kolorCiemnoNiebieski[1], kolorCiemnoNiebieski[2]);

	// Ko³o przód lewo du¿e
	koloPrzodLewoDuze = new Walec(20.f * rozmiar, 10.f * rozmiar, -45.f * rozmiar, 15.f * rozmiar, 20.f * rozmiar);
	koloPrzodLewoDuze->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaPrzodLewoDuza = new Walec(10.f * rozmiar, 10.f * rozmiar, -45.f * rozmiar, 15.f * rozmiar, 22.5f * rozmiar);
	felgaPrzodLewoDuza->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Ko³o przód prawo du¿e
	koloPrzodPrawoDuze = new Walec(20.f * rozmiar, -10.f * rozmiar, -45.f * rozmiar, 15.f * rozmiar, -20.f * rozmiar);
	koloPrzodPrawoDuze->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaPrzodPrawoDuza = new Walec(10.f * rozmiar, -10.f * rozmiar, -45.f * rozmiar, 15.f * rozmiar, -22.5f * rozmiar);
	felgaPrzodPrawoDuza->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Ko³o œrodek lewo ma³e
	koloSrodekLewoMale = new Walec(15.f * rozmiar, 10.f * rozmiar, -7.5f * rozmiar, 10.f * rozmiar, 20.f * rozmiar);
	koloSrodekLewoMale->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaSrodekLewoMala = new Walec(7.5f * rozmiar, 10.f * rozmiar, -7.5f * rozmiar, 10.f * rozmiar, 22.5f * rozmiar);
	felgaSrodekLewoMala->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Ko³o œrodek prawo ma³e
	koloSrodekPrawoMale = new Walec(15.f * rozmiar, -10.f * rozmiar, -7.5f * rozmiar, 10.f * rozmiar, -20.f * rozmiar);
	koloSrodekPrawoMale->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaSrodekPrawoMala = new Walec(7.5f * rozmiar, -10.f * rozmiar, -7.5f * rozmiar, 10.f * rozmiar, -22.5f * rozmiar);
	felgaSrodekPrawoMala->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Ko³o ty³ lewo ma³e
	koloTylLewoMale = new Walec(15.f * rozmiar, 10.f * rozmiar, 25.f * rozmiar, 10.f * rozmiar, 20.f * rozmiar);
	koloTylLewoMale->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaTylLewoMala = new Walec(7.5f * rozmiar, 10.f * rozmiar, 25.f * rozmiar, 10.f * rozmiar, 22.5f * rozmiar);
	felgaTylLewoMala->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

	// Ko³o ty³ prawo ma³e
	koloTylPrawoMale = new Walec(15.f * rozmiar, -10.f * rozmiar, 25.f * rozmiar, 10.f * rozmiar, -20.f * rozmiar);
	koloTylPrawoMale->setColor(kolorCiemnoCiemnoSzary[0], kolorCiemnoCiemnoSzary[1], kolorCiemnoCiemnoSzary[2]);

	felgaTylPrawoMala = new Walec(7.5f * rozmiar, -10.f * rozmiar, 25.f * rozmiar, 10.f * rozmiar, -22.5f * rozmiar);
	felgaTylPrawoMala->setColor(kolorJasnoSzary[0], kolorJasnoSzary[1], kolorJasnoSzary[2]);

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
	delete podwozie;
	delete nadwozie;
	delete kokpit;
	delete rurka1;
	delete rurka2;
	delete zbierak;
	delete koloPrzodLewoDuze;
	delete felgaPrzodLewoDuza;
	delete koloPrzodPrawoDuze;
	delete felgaPrzodPrawoDuza;
	delete koloSrodekLewoMale;
	delete felgaSrodekLewoMala;
	delete koloSrodekPrawoMale;
	delete koloSrodekLewoMale;
	delete koloTylLewoMale;
	delete felgaTylLewoMala;
	delete koloTylPrawoMale;
	delete felgaTylPrawoMala;
}

void Kombajn::draw()
{
	podwozie->draw();
	nadwozie->draw();
	kokpit->draw();
	rurka1->draw();
	rurka2->draw();
	zbierak->draw();
	koloPrzodLewoDuze->draw();
	felgaPrzodLewoDuza->draw();
	koloPrzodPrawoDuze->draw();
	felgaPrzodPrawoDuza->draw();
	koloSrodekLewoMale->draw();
	felgaSrodekLewoMala->draw();
	koloSrodekPrawoMale->draw();
	felgaSrodekPrawoMala->draw();
	koloTylLewoMale->draw();
	felgaTylLewoMala->draw();
	koloTylPrawoMale->draw();
	felgaTylPrawoMala->draw();
}

void Kombajn::update()
{
	std::cout << m_poz.x << " " << m_poz.y << " " << m_poz.z << std::endl;
}

void Kombajn::move(glm::vec3 przemieszczenie)
{
	m_poz += przemieszczenie;
	podwozie->move(przemieszczenie);
	nadwozie->move(przemieszczenie);
	kokpit->move(przemieszczenie);
	rurka1->move(przemieszczenie);
	rurka2->move(przemieszczenie);
	zbierak->move(przemieszczenie);
	koloPrzodLewoDuze->move(przemieszczenie);
	felgaPrzodLewoDuza->move(przemieszczenie);
	koloPrzodPrawoDuze->move(przemieszczenie);
	felgaPrzodPrawoDuza->move(przemieszczenie);
	koloSrodekLewoMale->move(przemieszczenie);
	felgaSrodekLewoMala->move(przemieszczenie);
	koloSrodekPrawoMale->move(przemieszczenie);
	felgaSrodekPrawoMala->move(przemieszczenie);
	koloTylLewoMale->move(przemieszczenie);
	felgaTylLewoMala->move(przemieszczenie);
	koloTylPrawoMale->move(przemieszczenie);
	felgaTylPrawoMala->move(przemieszczenie);
}

void Kombajn::turn(GLfloat angle)
{
	if (angle < -360.f || angle > 360.f) angle = 0.f;
	podwozie->turn(angle, m_poz);
	nadwozie->turn(angle, m_poz);
	kokpit->turn(angle, m_poz);
	rurka1->turn(angle, m_poz);
	rurka2->turn(angle, m_poz);
	zbierak->turn(angle, m_poz);
	koloPrzodLewoDuze->turn(angle, m_poz);
	felgaPrzodLewoDuza->turn(angle, m_poz);
	koloPrzodPrawoDuze->turn(angle, m_poz);
	felgaPrzodPrawoDuza->turn(angle, m_poz);
	koloSrodekLewoMale->turn(angle, m_poz);
	felgaSrodekLewoMala->turn(angle, m_poz);
	koloSrodekPrawoMale->turn(angle, m_poz);
	felgaSrodekPrawoMala->turn(angle, m_poz);
	koloTylLewoMale->turn(angle, m_poz);
	felgaTylLewoMala->turn(angle, m_poz);
	koloTylPrawoMale->turn(angle, m_poz);
	felgaTylPrawoMala->turn(angle, m_poz);
}