#ifndef _CALLBACKS_H_
#define _CALLBACKS_H_

#include <GLFW/glfw3.h>

void WindowSizeCallback(GLFWwindow* window, int width, int height)
{
    glPushMatrix();

    glLoadIdentity();
	
    glOrtho(0.0, width, height, 0.0, 0.0, 10.0);
	
    glPopMatrix();
}

void FramebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

#endif