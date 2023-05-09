#include "abstract/galaxy.h"
#include "structs/mt_randomengine.h"

Galaxy::~Galaxy() {
}

Galaxy::Galaxy(const Galaxy& galaxy) : name(galaxy.name), distanceFromCenterOfUniverse(galaxy.distanceFromCenterOfUniverse), rotationSpeed(galaxy.rotationSpeed), radius(galaxy.radius), luminosity(galaxy.luminosity), starClusters(galaxy.starClusters), blackHole(galaxy.blackHole) {
    position = galaxy.position;
}

Galaxy& Galaxy::operator=(const Galaxy& galaxy) {
    if (this != &galaxy) {
        this->starClusters = galaxy.starClusters;
    }
    name = galaxy.name;
    distanceFromCenterOfUniverse = galaxy.distanceFromCenterOfUniverse;
    radius = galaxy.radius;
    rotationSpeed = galaxy.rotationSpeed;
    luminosity = galaxy.luminosity;
    blackHole = galaxy.blackHole;
    position = galaxy.position;
    return *this;
}

// Operator ==
bool Galaxy::operator==(const Galaxy& galaxy) {
    return this->distanceFromCenterOfUniverse == galaxy.distanceFromCenterOfUniverse;
}

std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy){
    // Output galaxy information
    os << "Galaxy information:" << std::endl;
    os << "Name: " << galaxy.name << std::endl;
    os << "Distance from center of universe: " << galaxy.distanceFromCenterOfUniverse << std::endl;
    os << "Rotation speed: " << galaxy.rotationSpeed << std::endl;
    os << "Radius: " << galaxy.radius << std::endl;
    os << "Luminosity: " << galaxy.luminosity << std::endl;

    // Output lonely stars
    os << "Lonely stars:" << std::endl;
    for (int i = 0; i < (int)galaxy.lonelyStars.size(); i++) {
        os << galaxy.lonelyStars[i] << std::endl;
    }

    return os;
}

Galaxy::Galaxy(const std::string& n, double dist, double rad) : name(n), distanceFromCenterOfUniverse(dist),rotationSpeed(0), radius(rad), luminosity(0), blackHole(BlackHole(Constants::BLACKHOLEMASS_SUPERMASSIVE, Constants::BLACKHOLERADIUS_MASSIVE, Constants::BLACKHOLERADIUS_MASSIVE, Constants::BLACKHOLEMASS_MASSIVE)) {
    // Create a galaxy with a central black hole
    position = RandomEngine::randomPositionInRect(0, 0, Constants::WindowWidth, Constants::WindowHeight);
}

// Getter and setter for the rotation speed and luminosity
double Galaxy::getRotationSpeed() const {
    return rotationSpeed;
}

void Galaxy::setRotationSpeed(double rotSpeed) {
    rotationSpeed = rotSpeed;
}

double Galaxy::getLuminosity() const {
    return luminosity;
}

void Galaxy::setLuminosity(double lum) {
    luminosity = lum;
}

void Galaxy::addStar(const Star& star) {
    lonelyStars.push_back(star);
}

std::vector<Star>& Galaxy::getLonelyStars() {
    return lonelyStars;
}

void Galaxy::setLonelyStars(const std::vector<Star>& stars) {
    lonelyStars = stars;
}


std::pair<double, double> Galaxy::getPosition() const {
    return position;
}

void Galaxy::setPosition(const std::pair<double, double>& pos) {
    position = pos;
}

double Galaxy::getRadius() const {
    return radius;
}
