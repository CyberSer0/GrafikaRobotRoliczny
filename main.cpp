// main.cpp
// Ignore fopen errors
#define  _CRT_SECURE_NO_WARNINGS

// OpenGL libraries
#ifdef _MSC_VER                         // Check if MS Visual C compiler
#  pragma comment(lib, "opengl32.lib")  // Compiler-specific directive to avoid manually configuration
#  pragma comment(lib, "glu32.lib")     // Link libraries
#endif


// Ustalanie trybu tekstowego:
#ifdef _MSC_VER        // Check if MS Visual C compiler
#   ifndef _MBCS
#      define _MBCS    // Uses Multi-byte character set
#   endif
#   ifdef _UNICODE     // Not using Unicode character set
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif

#include <windows.h>            // Window defines
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>				// Define for sqrt
#include <cstdio>
#include "Kombajn.h"
#include "Ziemia.h"
#include "Dom.h"
#include "Ogrodzenie.h"
#include "Siano.h"
#include "Kamera.h"
#include "BMP.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.14


// Translations

// Zmienne przechowujące obiekty
Kombajn* kombajn;
Ziemia* ziemia;
Dom* dom;
Ogrodzenie* ogrodzenie;
Siano* siano;
Kamera* kamera;


static void cursorPositionCallback( GLFWwindow *window, double xpos, double ypos );
void cursorEnterCallback( GLFWwindow *window, int entered );
void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods );
void scrollCallback( GLFWwindow *window, double xoffset, double yoffset );
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;
int mouseWindowFocus = 0;
double oldMousePosX = SCREEN_WIDTH / 2;
double oldMousePosY = SCREEN_HEIGHT / 2;
double newMousePosX = SCREEN_WIDTH / 2;
double newMousePosY = SCREEN_HEIGHT / 2;

// Inicjalizacja obiektów
int InitObjects()
{
	srand(time(0));
	kombajn = new Kombajn(0.75f);
	ziemia = new Ziemia(25.f);
	dom = new Dom({-325.f, 135.f, -250.f}, 0.75f);
	ogrodzenie = new Ogrodzenie({-225.f, 135.f, -350.f}, 0.75f);
	siano = new Siano({-250.f, 100.f, -110.f}, 1.f);
	kamera = new Kamera({ 100.f, 100.f, 100.f }, { screenWidth, screenHeight }, 60.f, 0.f, 400.f);
	
	return 0;
}

// Rendering objects
int DrawObjects()
{
	kombajn->draw();
	ziemia->draw();
	ogrodzenie->draw();
	siano->draw();
	dom->draw();
	return 0;
}


// Called to draw scene
void RenderScene(void)
{
	glPushMatrix();
	if (mouseWindowFocus)
	{
		
	}

	glPolygonMode(GL_BACK, GL_LINE);

	DrawObjects();

	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	glFlush();
}


int main( void )
{
	GLFWwindow *window;
	

	float orthoZoom = 2.5f;

	if(!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow (SCREEN_WIDTH, SCREEN_HEIGHT, "Giga kombajn rolniczy", NULL, NULL);

	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	glfwSetCursorEnterCallback(window, cursorEnterCallback);

	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);

	glfwSetScrollCallback(window, scrollCallback);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glEnable(GL_DEPTH_TEST | GL_CULL_FACE);
	InitObjects();
	glViewport(0.0f, 0.0f, screenWidth, screenHeight);

	GLuint texture = 0;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	/*glTexImage2D(GL_TEXTURE_2D, 0, ziemiaTekstura.HasAlphaChannel() ? GL_RGBA : GL_RGB, ziemiaTekstura.GetWidth(), ziemiaTekstura.GetWidth(), 0, ziemiaTekstura.HasAlphaChannel() ? GL_BGRA : GL_BGR, GL_UNSIGNED_BYTE, ziemiaTekstura.GetPixels().data());*/

	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
		glfwGetCursorPos(window, &newMousePosY, &newMousePosX);
		kamera->update();
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		RenderScene();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}


static void cursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
{
	std::cout << xpos << " : " << ypos << std::endl;
}


void cursorEnterCallback(GLFWwindow* window, int entered)
{
	if (entered)
	{
		std::cout << "Entered window" << std::endl;
	} else
	{
		std::cout << "Left window" << std::endl;
	}
}


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right button pressed" << std::endl;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		mouseWindowFocus = 0;
	}
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left button pressed" << std::endl;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		mouseWindowFocus = 1;
	}
}


void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	std::cout << xoffset << " : " << yoffset << std::endl;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	std::cout << key << " pressed" << std::endl;
	if (key == GLFW_KEY_W && action == GLFW_REPEAT)
	{
		kamera->move({5.f, 0.f, 0.f});
	}
	if (key == GLFW_KEY_S && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		kamera->move({ -5.f, 0.f, 0.f });
	}
	if (key == GLFW_KEY_A && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		kamera->move({ 0.f, 0.f, -5.f });
	}
	if (key == GLFW_KEY_D && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		kamera->move({ 0.f, 0.f, 5.f });
	}
	if (key == GLFW_KEY_SPACE && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		kamera->move({ 0.f, 5.f, 0.f });
	}
	if (key == GLFW_KEY_LEFT_CONTROL && (action == GLFW_REPEAT || action == GLFW_PRESS))
	{
		kamera->move({ 0.f, -5.f, 0.f });
	}
}