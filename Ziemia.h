#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Prostopadloscian.h"
#include "Walec.h"
#include <math.h>
#include <vector>

class Ziemia
{
private:
    struct Vector3
    {
        GLfloat x;
        GLfloat y;
        GLfloat z;

    };
    struct Trojkat
    {
        int v1;
        int v2;
        int v3;
    };
    std::vector< Vector3 > vertices;
    std::vector< Trojkat > faces;
public:
	Ziemia(GLfloat rozmiar);
	~Ziemia();
};
