#include <GL/glew.h>

class Ostroslup
{
public:
	Ostroslup(	GLfloat dlugosc, GLfloat szerokosc, GLfloat wysokosc,
				GLfloat posX, GLfloat posY, 
				GLfloat posZ, GLfloat kolory[3]);
	~Ostroslup();
};