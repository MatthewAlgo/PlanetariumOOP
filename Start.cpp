#include <iostream>
#include "abstract/universe.h"
#include "abstract/universe_factory.h"
#include "star.h"
#include "blackHole.h"
#include "abstract/galaxy.h"
#include "constants.h"

#include "window/window.h"
#include "except/exceptions.h"
#include "structs/mt_randomengine.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void init(MainWindowClass* window) {
    // Initialize the universe
    Universe universe(UniverseFactory::createLargeUniverse());

    try {
        universe.createBigBang(window);
        std::cout<<universe<<std::endl;
        universe.checkTime();
    } catch (WindowNotFoundException& e) {
        std::cout<<e.what()<<std::endl;
    } catch (GalaxyNotFoundException& e) {
        std::cout<<e.what()<<std::endl;
    } catch (PlanetNotFoundException& e) {
        std::cout<<e.what()<<std::endl;
    } catch (StarNotFoundException& e) {
        std::cout<<e.what()<<std::endl;
    } 
}

int main() {
    #ifdef __linux__
	    XInitThreads();
    #endif

    // std::shared_ptr<MainWindowClass> myMainWindow = std::make_shared<MainWindowClass>("SpaceEngine", 1000, 500); // Initialize the window
	auto& x = MainWindowClass::get_app("SpaceEngine", 1000, 500);

    if (x.getWindowHeight() < 0 || x.getWindowWidth() < 0) {
        std::cout<<"Window size cannot be negative. Reverting to default values..."<<std::endl;
        x.setWindowHeight(500); // Set default window height
        x.setWindowWidth(1000); // Set default window width
    }

    init(&x); // Initialize the universe

    try {
        x.WinStartRendering();
    }
    catch (PlanetariumException& e) {
        std::cout<<e.what()<<std::endl;
        exit(1);
    }

    std::cin.get();
    return 0;
}
