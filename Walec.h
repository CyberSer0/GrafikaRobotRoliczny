#pragma once

#include <GL/glew.h>
#include <cmath>
#include <glm/glm.hpp>

class Walec
{
private:
	GLfloat m_posX;
	GLfloat m_posY;
	GLfloat m_posZ;
	GLfloat m_promien;
	GLfloat m_dlugosc;
	GLfloat kolor[3];
	glm::vec3 m_rotPoint;
	GLfloat angle;
public:
	Walec();
	Walec(	GLfloat promien, GLfloat wysokosc,
			GLfloat posX, GLfloat posY,
			GLfloat posZ);
	~Walec();
	void draw();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
	void move(glm::vec3 przemieszczenie);
	void turn(GLfloat angle, glm::vec3 point);
};