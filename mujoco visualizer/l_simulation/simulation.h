#ifndef MUJO_SIMULATION_H
#define MUJO_SIMULATION_H
//include header libraries, simulation should be uhh idk actually sure why not lol

//main headers
#include <mujoco/mujoco.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//oh use inline so that every library, including the main can use this
inline mjModel* m = nullptr;	// m to path xml
inline mjData* d = nullptr;	// d to actuator or data, since its a data
inline mjvScene scn;
inline mjvCamera cam;
inline mjvOption opt;
inline mjrContext con;

//window create
class mjsim {

public:
	void run(const char* xml_file); //the xml file path as const char, just for checking
	GLFWwindow* window = nullptr;	//define window pointer as null first, we'll define at the .cpp
	
};



#endif //#define MUJO_SIMULATION_H
