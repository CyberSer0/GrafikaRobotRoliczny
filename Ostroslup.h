#include <GL/glew.h>

class Ostroslup
{
private:
	GLfloat spod1[3];
	GLfloat spod2[3];
	GLfloat spod3[3];
	GLfloat spod4[3];
	GLfloat wierzcholek[3];
	GLfloat kolory[3];
public:
	Ostroslup(	GLfloat dlugosc, GLfloat szerokosc, GLfloat wysokosc,
				GLfloat posX, GLfloat posY, 
				GLfloat posZ);
	~Ostroslup();
	void draw();
};