#pragma once

#include "Prostopadloscian.h"
#include "Walec.h"

class Kombajn
{
private:
	Prostopadloscian *podwozie, *nadwozie, *kokpit, *rurka1, *rurka2;
	Walec *zbierak, *koloPrzodLewoDuze, *felgaPrzodLewoDuza, *koloPrzodPrawoDuze, *felgaPrzodPrawoDuza, *koloSrodekLewoMale, *felgaSrodekLewoMala, *koloSrodekPrawoMale, *felgaSrodekPrawoMala, *koloTylLewoMale, *felgaTylLewoMala, *koloTylPrawoMale, *felgaTylPrawoMala;
public:
	Kombajn(GLfloat rozmiar);
	~Kombajn();
	void draw();
};