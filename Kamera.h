#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H
#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Kamera
{
private:
	glm::vec3 m_poz;
	glm::vec2 m_dim;
	glm::vec3 m_lookAtPoz;
	float m_fov;
	float m_nearCutoff;
	float m_farCutoff;
	float movementSpeed;

public:
	glm::vec3 upVector;
	glm::vec3 frontVector;
	glm::vec3 rightVector;
	glm::vec3 m_rot;
	bool m_mouseControlsActivated;

	Kamera();
	Kamera(glm::vec3 poz, glm::vec2 dim, float fov, float nearCutoff, float farCutoff);
	Kamera(glm::vec3 poz, glm::vec2 dim, glm::vec3 rot, float fov, float nearCutoff, float farCutoff);
	~Kamera();
	void update();
	void move(glm::vec3 moveTo);
	void setPosition(glm::vec3 newPoz);
	void setRotation(glm::vec3 newRot);
	void lookAt(glm::vec3 lookAtPoz);
	void debugPrint();
};

#endif