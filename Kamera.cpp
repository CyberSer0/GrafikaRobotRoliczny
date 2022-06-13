#include "Kamera.h"
#include <iostream> 
#include <glm/gtc/quaternion.hpp>

// TODO: https://github.com/VictorGordan/opengl-tutorials/blob/main/YoutubeOpenGL%208%20-%20Camera/Camera.h;

Kamera::Kamera()
{
	m_poz = glm::vec3(0.f, 0.f, 0.f);
	m_rot = glm::vec3(0.f, 0.f, -1.f);
	m_dim = { 800.f, 600.f };
	m_fov = 60.f;
	m_nearCutoff = 0.f;
	m_farCutoff = 200.f;
	m_mouseControlsActivated = false;
	upVector = glm::vec3(0.f, 1.f, 0.f);
	frontVector = glm::vec3(1.0f, 0.0f, 0.0f);
	rightVector = glm::vec3(0.0f, 0.0f, 1.0f);
	movementSpeed = 5.0f;
}


Kamera::Kamera(glm::vec3 poz, glm::vec2 dim, float fov, float nearCutoff, float farCutoff)
{
	m_poz = poz;
	m_rot = glm::vec3(0.f, -1.f, -1.f);
	m_dim = dim;
	m_fov = fov;
	m_nearCutoff = nearCutoff;
	m_farCutoff = farCutoff;
	m_mouseControlsActivated = false;
	upVector = glm::vec3(0.f, 1.f, 0.f);
	frontVector = glm::vec3(1.0f, 0.0f, 0.0f);
	rightVector = glm::vec3(0.0f, 0.0f, 1.0f);
	movementSpeed = 5.0f;
}


Kamera::Kamera(glm::vec3 poz, glm::vec2 dim, glm::vec3 rot, float fov, float nearCutoff, float farCutoff)
{
	m_poz = poz;
	m_rot = rot;
	m_dim = dim;
	m_fov = fov;
	m_nearCutoff = nearCutoff;
	m_farCutoff = farCutoff;
	m_mouseControlsActivated = false;
	upVector = glm::vec3(0.f, 1.f, 0.f);
	frontVector = glm::vec3(0.0f, 0.0f, 1.0f);
	rightVector = glm::vec3(1.0f, 0.0f, 0.0f);
	movementSpeed = 5.0f;
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
	//debugPrint();
}

void Kamera::move(glm::vec3 moveTo)
{
	m_poz += moveTo * 2.5f;
}

void Kamera::setPosition(glm::vec3 newPoz)
{
	m_poz = newPoz * movementSpeed;
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
