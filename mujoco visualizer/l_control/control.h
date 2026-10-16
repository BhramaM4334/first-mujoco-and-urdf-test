#ifndef MUJO_CONTROL_H
#define MUJO_CONTROL_H
//this for the callback functions

#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
//no need for other include except these above

using namespace std;

void keyboardC(GLFWwindow* window, int key, int scancode, int act, int mods);
void mouseButtonC(GLFWwindow* window, int button, int act, int mods);
void mouseMoveC(GLFWwindow* window, double xpos, double ypos);
void scrollC(GLFWwindow* window, double xoffset, double yoffset);

#endif //mujo control h
