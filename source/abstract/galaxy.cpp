#include "abstract/galaxy.h"

Galaxy::~Galaxy() {
}

Galaxy::Galaxy(const Galaxy& galaxy) : distanceFromCenterOfUniverse(galaxy.distanceFromCenterOfUniverse), rotationSpeed(galaxy.rotationSpeed), radius(galaxy.radius), luminosity(galaxy.luminosity), starClusters(galaxy.starClusters) {
}

Galaxy& Galaxy::operator=(const Galaxy& galaxy) {
    if (this != &galaxy) {
        this->starClusters = galaxy.starClusters;
    }
    distanceFromCenterOfUniverse = galaxy.distanceFromCenterOfUniverse;
    radius = galaxy.radius;
    rotationSpeed = galaxy.rotationSpeed;
    luminosity = galaxy.luminosity;
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

Galaxy::Galaxy(double dist, double rad) {
    this->distanceFromCenterOfUniverse = dist;
    this->radius = rad;
    rotationSpeed = 0;
    luminosity = 0;
}