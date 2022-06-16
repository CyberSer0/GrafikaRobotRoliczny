#pragma once

#include "Prostopadloscian.h"
#include "Walec.h"
#include <glm/glm.hpp>
#include <iostream>

class Kombajn
{
private:
	Prostopadloscian *podwozie, *nadwozie, *kokpit, *rurka1, *rurka2, *punktRotacyjny;
	Walec *zbierak, *koloPrzodLewoDuze, *felgaPrzodLewoDuza, *koloPrzodPrawoDuze, *felgaPrzodPrawoDuza, *koloSrodekLewoMale, *felgaSrodekLewoMala, *koloSrodekPrawoMale, *felgaSrodekPrawoMala, *koloTylLewoMale, *felgaTylLewoMala, *koloTylPrawoMale, *felgaTylPrawoMala;
public:
	glm::vec3 m_poz;
	Kombajn(GLfloat rozmiar);
	~Kombajn();
	void draw();
	void update();
	void move(glm::vec3 przemieszczenie);
	void turn(GLfloat angle);
};