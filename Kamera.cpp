#include "Kamera.h"
#include <iostream>

Kamera::Kamera()
{
	m_poz = glm::vec3(0.f, 0.f, 0.f);
	m_rot = glm::vec3(1.f, 0.f, 0.f);
	m_dim = { 800.f, 600.f };
	m_fov = 60.f;
	m_nearCutoff = 0.f;
	m_farCutoff = 200.f;
	m_lookAtPoz = glm::vec3(0.f, 0.f, 0.f);
}


Kamera::Kamera(glm::vec3 poz, glm::vec2 dim, float fov, float nearCutoff, float farCutoff)
{
	m_poz = poz;
	m_rot = glm::vec3(1.f, 0.f, 0.f); 
	m_dim = dim;
	m_fov = fov;
	m_nearCutoff = nearCutoff;
	m_farCutoff = farCutoff;
	m_lookAtPoz = glm::vec3(0.f, 0.f, 0.f);
}


Kamera::Kamera(glm::vec3 poz, glm::vec2 dim, glm::vec3 rot, float fov, float nearCutoff, float farCutoff)
{
	m_poz = poz;
	m_rot = rot;
	m_dim = dim;
	m_fov = fov;
	m_nearCutoff = nearCutoff;
	m_farCutoff = farCutoff;
	m_lookAtPoz = glm::vec3(0.f, 0.f, 0.f);
}


Kamera::~Kamera()
{
}

void Kamera::update()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(m_fov, m_dim.x / m_dim.y, m_nearCutoff, m_farCutoff);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(m_poz.x, m_poz.y, m_poz.z, m_lookAtPoz.x, m_lookAtPoz.y, m_lookAtPoz.z, 0.f, 1.f, 0.f);
	debugPrint();
}

void Kamera::move(glm::vec3 moveTo)
{
	m_poz += moveTo;
}

void Kamera::setPosition(glm::vec3 newPoz)
{
	m_poz = newPoz;
}

void Kamera::setRotation(glm::vec3 newRot)
{
	m_rot = newRot;
}

void Kamera::lookAt(glm::vec3 lookAtPoz)
{
	m_lookAtPoz = lookAtPoz;
}

void Kamera::debugPrint()
{
	std::cout << m_poz.x << " : " << m_poz.y << " : " << m_poz.z << std::endl;
}
