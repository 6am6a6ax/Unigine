#include <ctime>

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Vector2f.h"
#include "Rectangle.h"
#include "QuadTree.h"

#include "Config.h"

#include "Draw.h"

#include "Input.h"
#include "Callbacks.h"

#include "Random.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

	// Binding GLFW callbacks
    //--------------------------------------------------

    glfwSetKeyCallback(window, KeyCallback);
	
    glfwSetWindowSizeCallback(window, WindowSizeCallback);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	// Main task
	//--------------------------------------------------

    QuadTree quadTree = QuadTree(Rectangle(FIELD_LEFT, FIELD_TOP, FIELD_WIDTH, FIELD_HEIGHT));

    std::vector<Unit> units = Random();

    for (const Unit& unit : units)
        quadTree.Insert(unit);

    for (std::size_t i = 0; i != units.size(); i++)
    {
        std::vector<Unit> around = quadTree.Query(units[i]);

        unsigned int res = 0;
    	for (const Unit& j : around)
    	{
            if (Check(units[i], j))
				res++;
    	}

    	// Uncomment this to view console output
        // std::cout << "Unit #" << i << ": see " << res << " units." << std::endl;
    }

	// Render
    //--------------------------------------------------

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
    	
        glfwPollEvents();
    	
		Draw(std::make_shared<QuadTree>(quadTree));

		for (const auto& unit : units)
		   Draw(unit);
    	
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}