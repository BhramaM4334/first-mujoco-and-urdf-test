
//main headers
#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
//control is for callback
#include "callback.h"
#include "simulation.h"

//glfw error thing
static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

//run command
void mjsim::run(const char* model_path) {
	char error[1024] = {0};
    m = mj_loadXML(model_path, nullptr, error, sizeof(error));
 //check 
	if (!m) {
        fprintf(stderr, "Could not load model: %s\n", error);
        return;
    }
    d = mj_makeData(m);
//init glfw, use the static void
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {	//if init fail
        fprintf(stderr, "Could not initialize GLFW\n");
        return;
    }

//create window/context
    glfwWindowHint(GLFW_DOUBLEBUFFER, 1);
    window = glfwCreateWindow(1200, 900, "MuJoCo Modular Viewer", nullptr, nullptr);
    if (!window) {	//if window fail to open, throw this 
        fprintf(stderr, "Could not create GLFW window\n");
        glfwTerminate();
        return;
    }
//conteext current to window and swap interval (vsync)
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
	
// Register input callbacks
    CallBacks(window);	//using window pointer initialized before

//set default
    mjv_defaultCamera(&cam);
    cam.lookat[0] = 0.0;
    cam.lookat[1] = 0.0;
    cam.lookat[2] = 0.5;
    
    mjv_defaultOption(&opt);
    mjv_defaultScene(&scn);
    mjr_defaultContext(&con);

//make scene and make context
    mjv_makeScene(m, &scn, 2000);
    mjr_makeContext(m, &con, mjFONTSCALE_100);

    cam.type = mjCAMERA_FREE;
    mj_forward(m, d);

//loop main
    while (!glfwWindowShouldClose(window)) {
    	
//stepping 
	    mj_step(m, d);
//cout the joint degree
		for(int i=0;i<6;i++){
			double deg = d->qpos[i] * (180.0 / 3.141592653589793);	//radian calculate
			printf("Joint %d: %f degrees\n", i, deg);
		}
//frame buffer
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        mjrRect viewport = {0, 0, width, height};
//update scene
        mjv_updateScene(m, d, &opt, nullptr, &cam, mjCAT_ALL, &scn);
        mjr_render(viewport, &scn, &con);
//swap the buffers, for completed buffer at window pointer and pollevent
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
//freeing
    mjr_freeContext(&con);
    mjv_freeScene(&scn);
    mj_deleteData(d);
    mj_deleteModel(m);
    glfwTerminate();
	
	
}

