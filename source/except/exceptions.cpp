#include "except/exceptions.h"

explicit PlanetariumException::PlanetariumException(const std::string &message) : message_(message) {}

const char *PlanetariumException::what() const noexcept
{
    return message_.c_str();
}

explicit GalaxyNotFoundException::GalaxyNotFoundException(const std::string &galaxyName)
    : PlanetariumException("Galaxy not found: " + galaxyName) {}

explicit PlanetNotFoundException::PlanetNotFoundException(const std::string &planetName)
    : PlanetariumException("Planet not found: " + planetName) {}

explicit StarNotFoundException::StarNotFoundException(const std::string &starName)
    : PlanetariumException("Star not found: " + starName) {}

explicit WindowNotFoundException::WindowNotFoundException(const std::string &windowName)
    : PlanetariumException("Window not found: " + windowName) {}