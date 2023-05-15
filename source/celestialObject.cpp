#include "celestialObject.h"
#include "structs/mt_randomengine.h"
#include "constants.h"

CelestialObject::CelestialObject(const std::string& n, double c, double t) : name(n), color(c), texture(t) {
    // std::cout<<"Default constructor for CelestialObject\n"<<std::endl;
    position = RandomEngine::randomPositionInRect(0, 0, Constants::WindowWidth, Constants::WindowHeight);
}

CelestialObject::~CelestialObject() {
}

std::pair<double, double> CelestialObject::getPosition() const {
    return position;
}

void CelestialObject::setPosition(const std::pair<double, double>& p) {
    position = p;
}

CelestialObject& CelestialObject::operator=(const CelestialObject& celestialObject) {
    if (this == &celestialObject) {
        return *this;
    }
    name = celestialObject.name;
    color = celestialObject.color;
    texture = celestialObject.texture;
    position = celestialObject.position;
    return *this;
}

CelestialObject::CelestialObject(const CelestialObject& celestialObject) {
    name = celestialObject.name;
    color = celestialObject.color;
    texture = celestialObject.texture;
    position = celestialObject.position;
}