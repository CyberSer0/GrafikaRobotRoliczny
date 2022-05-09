#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Prostopadloscian.h"
#include "Walec.h"
#include <math.h>
#include <vector>
#include <time.h>
#include <iostream>

class Ziemia
{
private:
    struct Vector3
    {
        GLfloat x;
        GLfloat y;
        GLfloat z;

    };
    std::vector< Vector3 > vertices;
    std::vector< Vector3 > faces;
public:
	Ziemia(GLfloat rozmiar);
	~Ziemia();
};
