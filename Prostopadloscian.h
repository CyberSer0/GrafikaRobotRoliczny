#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Prostopadloscian
{
private:
	GLfloat sa[3];
	GLfloat sb[3];
	GLfloat sc[3];
	GLfloat sd[3];
	GLfloat se[3];
	GLfloat sf[3];
	GLfloat sg[3];
	GLfloat sh[3];
	GLfloat kolor[3];
	GLfloat* vertices[8];
	glm::vec3 m_rotPoint;
	GLfloat angle;
	glm::vec3 m_pos;
public:
	Prostopadloscian(GLfloat dlugosc, GLfloat wysokosc, GLfloat szerokosc, GLfloat posX, GLfloat posY, GLfloat posZ);
	~Prostopadloscian();
	void draw();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
	void move(glm::vec3 przemieszczenie);
	void turn(GLfloat angle, glm::vec3 point);
	GLfloat getAngle() const;
};