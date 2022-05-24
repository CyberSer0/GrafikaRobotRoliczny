#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Prostopadloscian.h"
#include "Walec.h"
#include "BMP.h"
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

    struct ColorRGB
    {
	    GLfloat r;
	    GLfloat g;
	    GLfloat b;
    };
    GLfloat m_rozmiar;

    std::vector< Vector3 > vertices;
    std::vector< Vector3 > faces;
    std::vector< ColorRGB > colors; 

    BMP m_tex = BMP("trawa.bmp");

public:
	Ziemia(GLfloat rozmiar);
	~Ziemia();
    void draw();
    void setTexture(BMP tex);
};
