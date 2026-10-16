#include "callback.h"
#include "control.h"

#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
using namespace std;

void CallBacks(GLFWwindow* window){
	glfwSetKeyCallback(window, keyboardC);
	glfwSetMouseButtonCallback(window, mouseButtonC);
	glfwSetCursorPosCallback(window, mouseMoveC);
	glfwSetScrollCallback(window, scrollC);
}
