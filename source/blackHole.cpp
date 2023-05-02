#include "blackHole.h"

// Implement all the functions in the header file of blackHole
void BlackHole::draw(std::shared_ptr<sf::RenderWindow> window) {
    // Draw the black hole
    std::cout << "Drawing a black hole" << std::endl;
}

//[[maybe_unused]]
//double BlackHole::getMass() const {
//    return mass;
//}
//[[maybe_unused]]
//void BlackHole::setMass(double m) {
//    mass = m;
//}
//[[maybe_unused]]
//double BlackHole::getRadius() const{
//    return radius;
//}
//[[maybe_unused]]
//void BlackHole::setRadius(double r) {
//    radius = r;
//}


// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const BlackHole &blackHole) {
    os << "Black hole name: " << blackHole.name << std::endl;
    os << "Black hole mass: " << blackHole.mass << std::endl;
    os << "Black hole radius: " << blackHole.radius << std::endl;
    return os;
}

// Constructor, copy constructor, destructor, and assignment operator
BlackHole::BlackHole(const std::string& name, double a, double s, double r, double m) : CelestialObject(name, 0, 0){
    // Init the variables
    activityLevel = a;
    schwarzschildRadius = s;
    radius = r;
    mass = m;

}

BlackHole::BlackHole(double a, double s, double r, double m) : CelestialObject("Default name", 0, 0) {
    // Init the variables
    activityLevel = a;
    schwarzschildRadius = s;
    radius = r;
    mass = m;
}

BlackHole::~BlackHole() {
    // Destructor
}

BlackHole::BlackHole(const BlackHole& blackHole) : CelestialObject(blackHole) {
    activityLevel = blackHole.activityLevel;
    schwarzschildRadius = blackHole.schwarzschildRadius;
    radius = blackHole.radius;
    mass = blackHole.mass;
}

BlackHole& BlackHole::operator=(const BlackHole& blackHole) {
    if (this == &blackHole) {
        return *this;
    }
    CelestialObject::operator=(blackHole); // Call the base class assignment operator
    activityLevel = blackHole.activityLevel;
    schwarzschildRadius = blackHole.schwarzschildRadius;
    radius = blackHole.radius;
    mass = blackHole.mass;
    return *this;
}

BlackHole::BlackHole() : CelestialObject("Default name", 0, 0) {
    // Init the variables
    activityLevel = 0;
    schwarzschildRadius = 0;
    radius = 0;
    mass = 0;
}
