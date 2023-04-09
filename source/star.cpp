#include "star.h"

void Star::draw() {
    // Draw the star
}

[[maybe_unused]]
double Star::getMass() const {
    return mass;
}
[[maybe_unused]]
void Star::setMass(double m) {
    mass = m;
}
[[maybe_unused]]
double Star::getRadius() const{
    return radius;
}
[[maybe_unused]]
void Star::setRadius(double r) {
    radius = r;
}
[[maybe_unused]]
double Star::getDistanceFromCenterOfGalaxy() const{
    return distanceFromCenterOfGalaxy;
}
[[maybe_unused]]
void Star::setDistanceFromCenterOfGalaxy(double dist) {
    distanceFromCenterOfGalaxy = dist;
}
[[maybe_unused]]
double Star::getRotationSpeed() const {
    return rotationSpeed;
}
[[maybe_unused]]
void Star::setRotationSpeed(double rot) {
    rotationSpeed = rot;
}
[[maybe_unused]]
double Star::getRotationAngle() const {
    return rotationAngle;
}
[[maybe_unused]]
void Star::setRotationAngle(double rA) {
    rotationAngle = rA;
}

// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const Star &star) {
    os << "Star name: " << star.name << std::endl;
    os << "Star mass: " << star.mass << std::endl;
    os << "Star radius: " << star.radius << std::endl;
    os << "Star distance from center of galaxy: " << star.distanceFromCenterOfGalaxy << std::endl;
    os << "Star orbit speed: " << star.orbitSpeed << std::endl;
    os << "Star rotation speed: " << star.rotationSpeed << std::endl;
    os << "Star rotation angle: " << star.rotationAngle << std::endl;
    os << "Star moons: " << std::endl;
    for (int i = 0; i < star.planets.size(); i++) {
        os << star.planets[i] << std::endl;
    }
    return os;
}

// Operator= and copy constructor
Star::Star(const Star &star) : CelestialObject(star.name, 0, 0){
    mass = star.mass;
    radius = star.radius;
    distanceFromCenterOfGalaxy = star.distanceFromCenterOfGalaxy;
    orbitSpeed = star.orbitSpeed;
    rotationSpeed = star.rotationSpeed;
    rotationAngle = star.rotationAngle;
    name = star.name;
    planets = star.planets;
}

Star &Star::operator=(const Star &star) {
    mass = star.mass;
    radius = star.radius;
    distanceFromCenterOfGalaxy = star.distanceFromCenterOfGalaxy;
    orbitSpeed = star.orbitSpeed;
    rotationSpeed = star.rotationSpeed;
    rotationAngle = star.rotationAngle;
    name = star.name;
    planets = star.planets;
    return *this;
}

Star::~Star() {
    std::cout << "Star destructor called" << std::endl;
}

// Constructor
Star::Star(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double orbitSpeed) : CelestialObject(name, 0, 0) {
    mass = mass;
    radius = radius;
    distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
    orbitSpeed = orbitSpeed;
    name = name;
}

// Implement getter for the moons vector
std::vector<Planet> &Star::getPlanets() {
    return planets;
}