#include "control.h"
#include "simulation.h"
//this for the callback functions

#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
//no need for other include except these above

using namespace std;

static bool button_left = false, button_right = false, button_middle = false;
static double lastx = 0, lasty = 0;

void keyboardC(GLFWwindow* window, int key, int scancode, int act, int mods){
//if the act is press and its escape then close mujoco visualizer
if (act == GLFW_PRESS && key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    
//actuator thing, if act is pressed or its repeating do
double step = 0.1; //step is 0.01	|| lets use qwerty, total of 6 actuators
    if (act == GLFW_PRESS || act == GLFW_REPEAT) {
        if (key == GLFW_KEY_Q) d->ctrl[0] += step;
        if (key == GLFW_KEY_W) d->ctrl[0] -= step;
    	if (key == GLFW_KEY_E) d->ctrl[1] += step;
    	if (key == GLFW_KEY_R) d->ctrl[1] -= step;
    	if (key == GLFW_KEY_T) d->ctrl[2] += step;
    	if (key == GLFW_KEY_Y) d->ctrl[2] -= step;
    	//last 3
        if (key == GLFW_KEY_A) d->ctrl[3] += step;
        if (key == GLFW_KEY_S) d->ctrl[3] -= step;
    	if (key == GLFW_KEY_D) d->ctrl[4] += step;
    	if (key == GLFW_KEY_F) d->ctrl[4] -= step;
    	if (key == GLFW_KEY_G) d->ctrl[5] += step;
    	if (key == GLFW_KEY_H) d->ctrl[5] -= step; 	
	}
  }
//mouse button check
void mouseButtonC(GLFWwindow* window, int button, int act, int mods){
  //glfw for mouse button press detection, check for mouse button pressing function stuff yes or uh idk actually 
	button_left = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS);
    button_middle = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS);
    button_right = (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS);
    
  //save cursor position when a click happens || this is used for dragging when mousemove to drag cam
	glfwGetCursorPos(window, &lastx, &lasty);
}
//scroll

void mouseMoveC(GLFWwindow* window, double xpos, double ypos){
  if (!m) return;
  
  // If no mouse button is pressed, just update last position
  if (!button_left && !button_right && !button_middle) {
    lastx = xpos;
    lasty = ypos;
    return;
  }

  // Compute motion in window coordinates, normalize by framebuffer height (stable across DPI) || dy and dx divided by the height so that it's stable
  int fbw = 0, fbh = 1;
  glfwGetFramebufferSize(window, &fbw, &fbh);
  if (fbh <= 0) fbh = 1;
// because /0 is 0 or smth like that, delta x and delta y, for smoothing
  double dx = (xpos - lastx) / (double)fbh;
  double dy = (ypos - lasty) / (double)fbh;
  lastx = xpos;
  lasty = ypos;

//check for mouse button triggers, these functions are here insteadf of mousebutton because of the positions at x and y
  if (button_left) {
    // Left-drag: rotate
    mjv_moveCamera(m, mjMOUSE_ROTATE_H, dx, dy, &scn, &cam); //mouse rotate horizontal
  } else if (button_right) {
    // Right-drag: pan horizontally
    mjv_moveCamera(m, mjMOUSE_MOVE_H, dx, dy, &scn, &cam);	//mouse move horizontal
  } else if (button_middle) {
    // Middle-drag: zoom
    mjv_moveCamera(m, mjMOUSE_ZOOM, dx, dy, &scn, &cam);	//mid drag zoom
  }
}

void scrollC(GLFWwindow* window, double xoffset, double yoffset){
	  if (!m) return;
  // Scroll to zoom (gentle factor)
  mjv_moveCamera(m, mjMOUSE_ZOOM, 0, -0.05 * yoffset, &scn, &cam);
	
	
}
