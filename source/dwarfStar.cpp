#include "dwarfStar.h"

// Implement all the functions in the header file of dwarfStar
void DwarfStar::draw() {
    // Draw the dwarf star
}

double DwarfStar::getMagnetismLevel() const {
    return this->magnetismLevel;
}

void DwarfStar::setMagnetismLevel(double magnetismLevel) {
    this->magnetismLevel = magnetismLevel;
}

double DwarfStar::getTemperature() const {
    return this->temperature;
}

void DwarfStar::setTemperature(double temperature) {
    this->temperature = temperature;
}

double DwarfStar::getLuminosity() const {
    return this->luminosity;
}

void DwarfStar::setLuminosity(double luminosity) {
    this->luminosity = luminosity;
}

DwarfStar::DwarfStar(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double rotationSpeed, double magnetismLevel, double temperature, double luminosity) : Star(name, mass, radius, distanceFromCenterOfGalaxy, rotationSpeed) {
    this->magnetismLevel = magnetismLevel;
    this->temperature = temperature;
    this->luminosity = luminosity;
}

DwarfStar::~DwarfStar() {
    // Destructor
}

DwarfStar::DwarfStar(const DwarfStar& dwarfStar) : Star(dwarfStar) {
    this->magnetismLevel = dwarfStar.magnetismLevel;
    this->temperature = dwarfStar.temperature;
    this->luminosity = dwarfStar.luminosity;
}

DwarfStar& DwarfStar::operator=(const DwarfStar& dwarfStar) {
    if (this == &dwarfStar) {
        return *this;
    }
    Star::operator=(dwarfStar);
    this->magnetismLevel = dwarfStar.magnetismLevel;
    this->temperature = dwarfStar.temperature;
    this->luminosity = dwarfStar.luminosity;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const DwarfStar &dwarfStar) {
    os << "Dwarf Star name: " << dwarfStar.name << std::endl;
    os << "Dwarf Star mass: " << dwarfStar.mass << std::endl;
    os << "Dwarf Star radius: " << dwarfStar.radius << std::endl;
    os << "Dwarf Star distance from center of galaxy: " << dwarfStar.distanceFromCenterOfGalaxy << std::endl;
    os << "Dwarf Star rotation speed: " << dwarfStar.rotationSpeed << std::endl;
    os << "Dwarf Star rotation angle: " << dwarfStar.rotationAngle << std::endl;
    os << "Dwarf Star magnetism level: " << dwarfStar.magnetismLevel << std::endl;
    os << "Dwarf Star temperature: " << dwarfStar.temperature << std::endl;
    os << "Dwarf Star luminosity: " << dwarfStar.luminosity << std::endl;
    return os;
}