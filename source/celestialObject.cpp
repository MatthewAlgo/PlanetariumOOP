#include "celestialObject.h"

// Implement all the functions in the header file of celestialObject
//[[maybe_unused]]
//std::string CelestialObject::getName() const {
//    return name;
//}
//[[maybe_unused]]
//void CelestialObject::setName(const std::string& n) {
//    name = n;
//}
//[[maybe_unused]]
//double CelestialObject::getColor() const{
//    return color;
//}
//[[maybe_unused]]
//void CelestialObject::setColor(double c) {
//    this->color = c;
//}
//
//[[maybe_unused]]
//double CelestialObject::getTexture() const{
//    return texture;
//}
//[[maybe_unused]]
//void CelestialObject::setTexture(double t) {
//    texture = t;
//}

CelestialObject::CelestialObject(const std::string& n, double c, double t) : name(n), color(c), texture(t) {
}