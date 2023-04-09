#include "abstract/galaxy.h"

Galaxy::~Galaxy() {
}

Galaxy::Galaxy(const Galaxy& galaxy) {
    this->starClusters = galaxy.starClusters;
}

Galaxy& Galaxy::operator=(const Galaxy& galaxy) {
    if (this != &galaxy) {
        this->starClusters = galaxy.starClusters;
    }
    return *this;
}

// Operator ==
bool Galaxy::operator==(const Galaxy& galaxy) {
    return this->distanceFromCenterOfUniverse == galaxy.distanceFromCenterOfUniverse;
}

std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy){
    // Output galaxy information
    os << "Galaxy information:" << std::endl;
    os << "Distance from center of universe: " << galaxy.distanceFromCenterOfUniverse << std::endl;
    os << "Rotation speed: " << galaxy.rotationSpeed << std::endl;
    os << "Radius: " << galaxy.radius << std::endl;
    os << "Luminosity: " << galaxy.luminosity << std::endl;

    return os;
}

