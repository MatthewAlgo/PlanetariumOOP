#include "abstract/universe_factory.h" 
#include "abstract/universe.h"


Universe UniverseFactory::createSmallUniverse() {
    Universe universe(Constants::SMALL_NUMBER_OF_GALAXIES);
    Universe::numberOfUniverseObjects++;
    return universe;
}

Universe UniverseFactory::createMediumUniverse() {
    Universe universe(Constants::MEDIUM_NUMBER_OF_GALAXIES);
    Universe::numberOfUniverseObjects++;
    return universe;
}

Universe UniverseFactory::createLargeUniverse() {
    Universe universe(Constants::LARGE_NUMBER_OF_GALAXIES);
    Universe::numberOfUniverseObjects++;
    return universe;
}
