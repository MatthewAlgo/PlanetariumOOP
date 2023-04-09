#include "dwarfStar.h"

// Implement all the functions in the header file of dwarfStar
void DwarfStar::draw() {
    // Draw the dwarf star
}

//[[maybe_unused]]
//double DwarfStar::getMagnetismLevel() const {
//    return magnetismLevel;
//}
//[[maybe_unused]]
//void DwarfStar::setMagnetismLevel(double magLevel) {
//    this->magnetismLevel = magLevel;
//}
//[[maybe_unused]]
//double DwarfStar::getTemperature() const {
//    return this->temperature;
//}
//[[maybe_unused]]
//void DwarfStar::setTemperature(double temp) {
//    this->temperature = temp;
//}
//[[maybe_unused]]
//double DwarfStar::getLuminosity() const {
//    return this->luminosity;
//}
//[[maybe_unused]]
//void DwarfStar::setLuminosity(double lum) {
//    this->luminosity = lum;
//}

DwarfStar::DwarfStar(const std::string& n, double m, double r, double d, double orbSpeed, double magLevel, double temp, double lum) : Star(n, m, r, d, orbSpeed), magnetismLevel(magLevel), temperature(temp), luminosity(lum) {
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
    os << "Dwarf Star magnetism level: " << dwarfStar.magnetismLevel << std::endl;
    os << "Dwarf Star temperature: " << dwarfStar.temperature << std::endl;
    os << "Dwarf Star luminosity: " << dwarfStar.luminosity << std::endl;
    return os;
}