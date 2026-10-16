#ifndef MUJO_CALLBACK_H
#define MUJO_CALLBACK_H
//ofc define the stuff here callback yes
#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>

using namespace std;

//set callback void, since simulation needs to declare this
void CallBacks(GLFWwindow* window);

#endif //MUJO_CALLBACK_H
