#ifndef _INPUT_H_
#define _INPUT_H_

#include <GLFW/glfw3.h>

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
        glScalef(.5f, .5f, 0.f);

    else if (key == GLFW_KEY_E && action == GLFW_PRESS)
        glScalef(1.5f, 1.5f, 0.f);

    else if (key == GLFW_KEY_W && action == GLFW_PRESS)
        glTranslatef(0.f, -5.5f, 0.f);

    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        glTranslatef(0.f, 5.5f, 0.f);

    else if (key == GLFW_KEY_A && action == GLFW_PRESS)
        glTranslatef(5.5f, .0f, 0.f);

    else if (key == GLFW_KEY_D && action == GLFW_PRESS)
        glTranslatef(-5.5f, .0f, 0.f);
}

#endif
