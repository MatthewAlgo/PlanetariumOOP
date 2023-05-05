#include <iostream>
#include "abstract/universe.h"
#include "star.h"
#include "blackHole.h"
#include "abstract/galaxy.h"
#include "constants.h"

#include "window/window.h"
#include "except/exceptions.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void init(MainWindowClass* window) {
    // Initialize the universe
    Universe universe(Constants::MEDIUM_NUMBER_OF_GALAXIES);
    Universe::numberOfUniverseObjects++;

    try{

        universe.createBigBang(window);
        std::cout<<universe<<std::endl;
        universe.checkTime();

    } catch (WindowNotFoundException& e) {
        std::cout<<e.what()<<std::endl;
        exit(1);
    }
}

int main() {
    #ifdef __linux__
	    XInitThreads();
    #endif

    MainWindowClass* myMainWindow = new MainWindowClass("SpaceEngine", 1000, 500); // Initialize the window
	
    init(myMainWindow); // Initialize the universe

    myMainWindow->WinStartRendering();

    delete myMainWindow;
    return 0;
}
