#include "moon.h"

// Implement all the functions in the header file
void Moon::draw() {
    // Draw the moon
}

double Moon::getMass() {
    return this->mass;
}

void Moon::setMass(double mass) {
    this->mass = mass;
}

double Moon::getRadius() {
    return this->radius;
}

void Moon::setRadius(double radius) {
    this->radius = radius;
}

double Moon::getDistanceFromPlanet() {
    return this->distanceFromPlanet;
}

void Moon::setDistanceFromPlanet(double distanceFromPlanet) {
    this->distanceFromPlanet = distanceFromPlanet;
}

double Moon::getOrbitSpeed() {
    return this->orbitSpeed;
}

void Moon::setOrbitSpeed(double orbitSpeed) {
    this->orbitSpeed = orbitSpeed;
}

double Moon::getRotationSpeed() {
    return this->rotationSpeed;
}

double Moon::getColor() {
    return this->color;
}

void Moon::setColor(double color) {
    this->color = color;
}

double Moon::getTexture() {
    return this->texture;
}

void Moon::setTexture(double texture) {
    this->texture = texture;
}


void Moon::setRotationSpeed(double rotationSpeed) {
    this->rotationSpeed = rotationSpeed;
}

double Moon::getRotationAngle() {
    return this->rotationAngle;
}

void Moon::setRotationAngle(double rotationAngle) {
    this->rotationAngle = rotationAngle;
}

// friend ostream for <<
std::ostream& operator<<(std::ostream& os, const Moon& moon){
    os << "Moon: " << moon.name << ", Mass: " << moon.mass << ", Radius: " << moon.radius << ", Distance from planet: " << moon.distanceFromPlanet << ", Orbit speed: " << moon.orbitSpeed << ", Rotation speed: " << moon.rotationSpeed << ", Color: " << moon.color << ", Texture: " << moon.texture << ", Rotation angle: " << moon.rotationAngle;
    return os;
}

// Destructor, copy constructor and assignment operator
Moon::~Moon() {
    std::cout << "Moon " << this->name << " destroyed!" << std::endl;
}

Moon::Moon(std::string name, double mass, double radius, double distanceFromPlanet, double orbitSpeed)
    : CelestialObject(name, 0, 0), radius(radius), distanceFromPlanet(distanceFromPlanet), orbitSpeed(orbitSpeed) {
    std::cout << "Moon constructor called!" << std::endl;
}

Moon::Moon(const Moon& moon) : CelestialObject(moon.name, 0, 0){
    std::cout<<"Moon copy constructor called!"<<std::endl;
    this->mass = moon.mass;
    this->radius = moon.radius;
    this->distanceFromPlanet = moon.distanceFromPlanet;
    this->orbitSpeed = moon.orbitSpeed;
    this->rotationSpeed = moon.rotationSpeed;
    this->color = moon.color;
    this->texture = moon.texture;
    this->rotationAngle = moon.rotationAngle;
}
