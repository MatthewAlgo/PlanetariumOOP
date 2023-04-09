#include "star.h"

void Star::draw() {
    // Draw the star
    std::cout<<"The star is drawn"<<std::endl;
}

//[[maybe_unused]]
//double Star::getMass() const {
//    return mass;
//}
//[[maybe_unused]]
//void Star::setMass(double m) {
//    mass = m;
//}
//[[maybe_unused]]
//double Star::getRadius() const{
//    return radius;
//}
//[[maybe_unused]]
//void Star::setRadius(double r) {
//    radius = r;
//}
//[[maybe_unused]]
//double Star::getDistanceFromCenterOfGalaxy() const{
//    return distanceFromCenterOfGalaxy;
//}
//[[maybe_unused]]
//void Star::setDistanceFromCenterOfGalaxy(double dist) {
//    distanceFromCenterOfGalaxy = dist;
//}

// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const Star &star) {
    os << "Star name: " << star.name << std::endl;
    os << "Star mass: " << star.mass << std::endl;
    os << "Star radius: " << star.radius << std::endl;
    os << "Star distance from center of galaxy: " << star.distanceFromCenterOfGalaxy << std::endl;
    os << "Star orbit speed: " << star.orbitSpeed << std::endl;
    os << "Star moons: " << std::endl;
    for (int i = 0; i < (int)star.planets.size(); i++) {
        os << star.planets[i] << std::endl;
    }
    return os;
}

// Operator= and copy constructor
Star::Star(const Star &star) : CelestialObject(star.name, 0, 0), mass(star.mass), radius(star.radius), orbitSpeed(star.orbitSpeed), distanceFromCenterOfGalaxy(star.distanceFromCenterOfGalaxy),  planets(star.planets) {
    // Init the variables
}

Star &Star::operator=(const Star &star) {
    CelestialObject::operator=(star);
    mass = star.mass;
    radius = star.radius;
    orbitSpeed = star.orbitSpeed;
    distanceFromCenterOfGalaxy = star.distanceFromCenterOfGalaxy;
    planets = star.planets;
    return *this;
}

Star::~Star() {
    std::cout << "Star destructor called" << std::endl;
}

// Constructor
Star::Star(const std::string& n, double m, double r, double o, double d) : CelestialObject(n, 0, 0), mass(m), radius(r),orbitSpeed(o), distanceFromCenterOfGalaxy(d) {
    // Init the variables

}

//// Implement getter for the moons vector
//std::vector<Planet> &Star::getPlanets() {
//    return planets;
//}