#include "except/exceptions.h"

// overrding the what() method
const char* PlanetariumException::what() const noexcept {
    return message_.c_str();
}

PlanetariumException::PlanetariumException(const std::string &message) : message_(message) {}

GalaxyNotFoundException::GalaxyNotFoundException(const std::string &galaxyName)
    : PlanetariumException("Galaxy not found: " + galaxyName) {
        message_ = "Galaxy not found: " + galaxyName;
    }

PlanetNotFoundException::PlanetNotFoundException(const std::string &planetName)
    : PlanetariumException("Planet not found: " + planetName) {
        message_ = "Planet not found: " + planetName;
    }

StarNotFoundException::StarNotFoundException(const std::string &starName)
    : PlanetariumException("Star not found: " + starName) {
        message_ = "Star not found: " + starName;
    }

PlanetariumRuntimeException::PlanetariumRuntimeException(const std::string &message)
    : PlanetariumException(message) {
        message_ = "Runtime error with message:" + message;
}


PlanetariumArgumentException::PlanetariumArgumentException(const std::string &message)
    : PlanetariumException(message) {
        message_ = "Invalid argument exception: " + message;
}

PlanetariumLogicException::PlanetariumLogicException(const std::string &message)
    : PlanetariumException(message) {
        message_ = "Logic exception: " + message;
}