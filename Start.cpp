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
#include <exception>

#ifdef __linux__
#include <X11/Xlib.h>
#endif

void init(MainWindowClass *window)
{
    // Initialize the universe
    Universe universe(UniverseFactory::createLargeUniverse());

    universe.createBigBang(window);
    std::cout << universe << std::endl;
    universe.checkTime();
}

int main()
{
#ifdef __linux__
    XInitThreads();
#endif

    try
    {
        auto &x = MainWindowClass::get_app("SpaceEngine", 1000, 500);


        init(&x); // Initialize the universe
        x.WinStartRendering();
    }

    catch (PlanetariumException &e)
    {
        if (const PlanetariumArgumentException* argExc = dynamic_cast<const PlanetariumArgumentException*>(&e))
        {
            std::cout << "PlanetariumArgumentException: " << argExc->what() << std::endl;
        }
        else if (const PlanetariumLogicException* logicExc = dynamic_cast<const PlanetariumLogicException*>(&e))
        {
            std::cout << "PlanetariumLogicException: " << logicExc->what() << std::endl;
        }
        else if (const PlanetariumRuntimeException* runtimeExc = dynamic_cast<const PlanetariumRuntimeException*>(&e))
        {
            std::cout << "PlanetariumRuntimeException: " << runtimeExc->what() << std::endl;
        }
        else
        {
            std::cout << "PlanetariumException: " << e.what() << std::endl;
        }
    }

    std::cin.get();
    return 0;
}
