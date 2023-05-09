#include "except/exceptions.h"

PlanetariumException::PlanetariumException(const std::string &message) : message_(message) {}

GalaxyNotFoundException::GalaxyNotFoundException(const std::string &galaxyName)
    : PlanetariumException("Galaxy not found: " + galaxyName) {
    }

PlanetNotFoundException::PlanetNotFoundException(const std::string &planetName)
    : PlanetariumException("Planet not found: " + planetName) {}

StarNotFoundException::StarNotFoundException(const std::string &starName)
    : PlanetariumException("Star not found: " + starName) {}

WindowNotFoundException::WindowNotFoundException(const std::string &message)
    : PlanetariumException(message) {}