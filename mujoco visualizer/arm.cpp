#include "simulation.h"

#include <iostream>
using namespace std;

int main(int argc, const char** argv){
	if (argc < 2) {
    std::printf("Usage: %s <model name>.xml\n", argv[0]);
    return 1;
  }
	
	mjsim sim;	//declare the class mjsim as sim
	sim.run(argv[1]); //2nd pointer is the xml
	
}


