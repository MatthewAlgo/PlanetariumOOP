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

        if (x.getWindowHeight() < 0 || x.getWindowWidth() < 0)
        {
            std::cout << "Window size cannot be negative. Reverting to default values..." << std::endl;
            x.setWindowHeight(500); // Set default window height
            x.setWindowWidth(1000); // Set default window width
        }

        init(&x); // Initialize the universe
        x.WinStartRendering();
    }

    catch (PlanetariumArgumentException &e)
    {
        std::cout << "The program encountered an error regarding the arguments of a function: " << e.what() << std::endl;
        exit(1);
    }
    catch (WindowNotFoundException &e)
    {
        std::cout << "The program encountered an error regarding the window: " << e.what() << std::endl;
        exit(1);
    }
    catch (PlanetariumException &e)
    {
        std::cout << "The program encountered a planetarium-related error: " << e.what() << std::endl;
        exit(1);
    }
    catch (std::exception &e)
    {
        std::cout << "The program encountered an error: " << e.what() << std::endl;
        exit(1);
    }
    catch (...)
    {
        std::cout << "The program encountered an unknown error" << std::endl;
        exit(1);
    }

    std::cin.get();
    return 0;
}
