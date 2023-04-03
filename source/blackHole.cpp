#include "blackHole.h"

// Implement all the functions in the header file of blackHole
void BlackHole::draw() {
    // Draw the black hole
}

double BlackHole::getMass() const {
    return this->mass;
}

void BlackHole::setMass(double mass) {
    this->mass = mass;
}

double BlackHole::getRadius() const{
    return this->radius;
}

void BlackHole::setRadius(double radius) {
    this->radius = radius;
}


// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const BlackHole &blackHole) {
    os << "Black hole name: " << blackHole.name << std::endl;
    os << "Black hole mass: " << blackHole.mass << std::endl;
    os << "Black hole radius: " << blackHole.radius << std::endl;
    return os;
}

// Constructor, copy constructor, destructor, and assignment operator
BlackHole::BlackHole(std::string name, double activityLevel, double schwarzschildRadius, 
        double radius, double mass) : CelestialObject(name, 0, 0){
    // Init the variables
    this->activityLevel = activityLevel;
    this->schwarzschildRadius = schwarzschildRadius;
    this->radius = radius;
    this->mass = mass;
    
}

BlackHole::~BlackHole() {
    // Destructor
}

BlackHole::BlackHole(const BlackHole& blackHole) : CelestialObject(blackHole) {
    this->activityLevel = blackHole.activityLevel;
    this->schwarzschildRadius = blackHole.schwarzschildRadius;
    this->radius = blackHole.radius;
    this->mass = blackHole.mass;
}

BlackHole& BlackHole::operator=(const BlackHole& blackHole) {
    if (this == &blackHole) {
        return *this;
    }
    CelestialObject::operator=(blackHole);
    this->activityLevel = blackHole.activityLevel;
    this->schwarzschildRadius = blackHole.schwarzschildRadius;
    this->radius = blackHole.radius;
    this->mass = blackHole.mass;
    return *this;
}
