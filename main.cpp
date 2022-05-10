// Gl_template.c
//Wy��czanie b��d�w przed "fopen"
#define  _CRT_SECURE_NO_WARNINGS



// �adowanie bibliotek:

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
#include <cmath>				// Define for sqrt
#include <cstdio>
#include "Kombajn.h"
#include "Ziemia.h"
#include "Dom.h"
#include "Ogrodzenie.h"
#include "Siano.h"
#include "Kamera.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.14


// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;


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


int mouseCameraRotation = 0;
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
	kamera = new Kamera(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);
	return 0;
}

// Rendering objects
int DrawObjects()
{
	kombajn->draw();
	ziemia->draw();
	dom->draw();
	ogrodzenie->draw();
	siano->draw();
	return 0;
}


// Called to draw scene
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (mouseCameraRotation)
	{
		if (oldMousePosX != newMousePosX)
		{
			glPushMatrix();
			xRot = newMousePosX - oldMousePosX;
			
		}
		if (oldMousePosY != newMousePosY)
		{
			
			glPushMatrix();
			yRot = newMousePosY - oldMousePosY;
		}
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



	//unsigned char pixels[16 * 16 * 4];
	//memset(pixels, 0xff, sizeof(pixels));
	//GLFWimage image;
	//image.width = 16;
	//image.height = 16;
	//image.pixels = pixels;
	//GLFWcursor *cursor = glfwCreateCursor(&image, 0, 0);
	//glfwSetCursor(window, cursor);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluLookAt(0.f, 2.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
	//glOrtho(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, 0, 400);
	gluPerspective(60.0f,screenWidth / screenHeight,1, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	InitObjects();

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwGetCursorPos(window, &newMousePosY, &newMousePosX);

		RenderScene();

		glfwSwapBuffers(window);
		glfwPollEvents();
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
		mouseCameraRotation = 0;
	}
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left button pressed" << std::endl;
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		mouseCameraRotation = 1;
	}
}


void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	std::cout << xoffset << " : " << yoffset << std::endl;
}
