#include <iostream>
#include "abstract/universe.h"
#include "star.h"
#include "blackHole.h"
#include "abstract/galaxy.h"
#include "constants.h"

#include "window/window.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void init(std::shared_ptr<sf::RenderWindow> window) {
    // Initialize the universe
    Universe universe(Constants::MEDIUM_NUMBER_OF_GALAXIES);
    universe.createBigBang(window);
    std::cout<<universe<<std::endl;
    universe.checkTime();
}

int main() {
    #ifdef __linux__
	    XInitThreads();
    #endif

    MainWindowClass* MyMainWindow;
	MyMainWindow = new MainWindowClass("SpaceEngine", 1000, 500); // Initialize the window

    std::shared_ptr<sf::RenderWindow> window_to_shared(MyMainWindow->getWindow());
    init(window_to_shared); // Initialize the universe

    std::cin.get();
    return 0;
}
