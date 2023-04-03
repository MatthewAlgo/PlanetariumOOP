#include "celestialObject.h"

// Implement all the functions in the header file of celestialObject
void CelestialObject::draw() {
    // Draw the celestial object
}

std::string CelestialObject::getName() const {
    return this->name;
}

void CelestialObject::setName(std::string name) {
    this->name = name;
}

double CelestialObject::getColor() const{
    return this->color;
}

void CelestialObject::setColor(double color) {
    this->color = color;
}


double CelestialObject::getTexture() const{
    return this->texture;
}

void CelestialObject::setTexture(double texture) {
    this->texture = texture;
}
