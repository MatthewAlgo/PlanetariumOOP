#include "star.h"

// Implement all the functions in the header file of star
void Star::draw() {
    // Draw the star
}

double Star::getMass() const {
    return this->mass;
}

void Star::setMass(double mass) {
    this->mass = mass;
}

double Star::getRadius() const{
    return this->radius;
}

void Star::setRadius(double radius) {
    this->radius = radius;
}

double Star::getDistanceFromCenterOfGalaxy() const{
    return this->distanceFromCenterOfGalaxy;
}

void Star::setDistanceFromCenterOfGalaxy(double distanceFromCenterOfGalaxy) {
    this->distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
}

double Star::getRotationSpeed() const {
    return this->rotationSpeed;
}

void Star::setRotationSpeed(double rotationSpeed) {
    this->rotationSpeed = rotationSpeed;
}

double Star::getRotationAngle() const {
    return this->rotationAngle;
}

void Star::setRotationAngle(double rotationAngle) {
    this->rotationAngle = rotationAngle;
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
    this->mass = star.mass;
    this->radius = star.radius;
    this->distanceFromCenterOfGalaxy = star.distanceFromCenterOfGalaxy;
    this->orbitSpeed = star.orbitSpeed;
    this->rotationSpeed = star.rotationSpeed;
    this->rotationAngle = star.rotationAngle;
    this->name = star.name;
    this->planets = star.planets;
}

Star &Star::operator=(const Star &star) {
    this->mass = star.mass;
    this->radius = star.radius;
    this->distanceFromCenterOfGalaxy = star.distanceFromCenterOfGalaxy;
    this->orbitSpeed = star.orbitSpeed;
    this->rotationSpeed = star.rotationSpeed;
    this->rotationAngle = star.rotationAngle;
    this->name = star.name;
    this->planets = star.planets;
    return *this;
}

Star::~Star() {
    std::cout << "Star destructor called" << std::endl;
}

// Constructor
Star::Star(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double orbitSpeed) : CelestialObject(name, 0, 0) {
    this->mass = mass;
    this->radius = radius;
    this->distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
    this->orbitSpeed = orbitSpeed;
    this->name = name;
}

// Implement getter for the moons vector
std::vector<Planet> &Star::getPlanets() {
    return planets;
}