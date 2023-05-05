#include "moon.h"

// Implement all the functions in the header file
[[maybe_unused]]
void Moon::draw(sf::RenderWindow* window) {
    // Draw the moon
    std::cout<<"Drawing the moon for a planet\n"<<std::endl;
}

//[[maybe_unused]]
//double Moon::getMass() {
//    return this->mass;
//}
//[[maybe_unused]]
//void Moon::setMass(double m) {
//    mass = m;
//}
//[[maybe_unused]]
//double Moon::getRadius() {
//    return radius;
//}
//[[maybe_unused]]
//void Moon::setRadius(double r) {
//    radius = r;
//}
//[[maybe_unused]]
//double Moon::getDistanceFromPlanet() {
//    return distanceFromPlanet;
//}
//[[maybe_unused]]
//void Moon::setDistanceFromPlanet(double dist) {
//    distanceFromPlanet = dist;
//}
//[[maybe_unused]]
//double Moon::getOrbitSpeed() {
//    return orbitSpeed;
//}
//[[maybe_unused]]
//void Moon::setOrbitSpeed(double os) {
//    this->orbitSpeed = os;
//}
//[[maybe_unused]]
//double Moon::getRotationSpeed() {
//    return rotationSpeed;
//}
//[[maybe_unused]]
//double Moon::getColor() {
//    return color;
//}
//[[maybe_unused]]
//void Moon::setColor(double c) {
//    color = c;
//}
//[[maybe_unused]]
//double Moon::getTexture() {
//    return texture;
//}
//[[maybe_unused]]
//void Moon::setTexture(double text) {
//    texture = text;
//}
//[[maybe_unused]]
//void Moon::setRotationSpeed(double rs) {
//    this->rotationSpeed = rs;
//}
//[[maybe_unused]]
//double Moon::getRotationAngle() {
//    return rotationAngle;
//}
//[[maybe_unused]]
//void Moon::setRotationAngle(double rAng) {
//    this->rotationAngle = rAng;
//}

// friend ostream for <<
std::ostream& operator<<(std::ostream& os, const Moon& moon){
    os << "Moon: " << moon.name << ", Mass: " << moon.mass << ", Radius: " << moon.radius << ", Distance from planet: " << moon.distanceFromPlanet << ", Orbit speed: " << moon.orbitSpeed << ", Rotation speed: " << moon.rotationSpeed << ", Texture: " << moon.texture << ", Rotation angle: " << moon.rotationAngle;
    return os;
}

// Destructor, copy constructor and assignment operator
Moon::~Moon() {
    std::cout << "Moon " << this->name << " destroyed!" << std::endl;
}

Moon::Moon(const std::string& name, double mass, double radius, double distanceFromPlanet, double orbitSpeed)
    : CelestialObject(name, 0, 0), mass(mass), radius(radius), distanceFromPlanet(distanceFromPlanet), orbitSpeed(orbitSpeed), rotationSpeed(0), rotationAngle(0) {
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

// Add the equal operator
Moon& Moon::operator=(const Moon& moon){
    std::cout<<"Moon assignment operator called!"<<std::endl;
    this->mass = moon.mass;
    this->radius = moon.radius;
    this->distanceFromPlanet = moon.distanceFromPlanet;
    this->orbitSpeed = moon.orbitSpeed;
    this->rotationSpeed = moon.rotationSpeed;
    this->color = moon.color;
    this->texture = moon.texture;
    this->rotationAngle = moon.rotationAngle;
    return *this;
}
