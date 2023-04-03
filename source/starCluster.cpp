#include "starCluster.h"

void StarCluster::draw() {
    // Draw the starCluster
}

StarCluster::StarCluster(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double rotationSpeed, double luminosity) : CelestialObject(name, 0, 0){
    this->name = name;
    this->mass = mass;
    this->radius = radius;
    this->distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
    this->rotationSpeed = rotationSpeed;
    this->luminosity = luminosity;
}

StarCluster::~StarCluster() {
    // Delete the stars
}

StarCluster::StarCluster(const StarCluster& starCluster) : CelestialObject(starCluster) {
    this->name = starCluster.name;
    this->mass = starCluster.mass;
    this->radius = starCluster.radius;
    this->distanceFromCenterOfGalaxy = starCluster.distanceFromCenterOfGalaxy;
    this->rotationSpeed = starCluster.rotationSpeed;
    this->luminosity = starCluster.luminosity;
    this->stars = starCluster.stars;
}

StarCluster& StarCluster::operator=(const StarCluster& starCluster) {
    if (this != &starCluster) {
        this->name = starCluster.name;
        this->mass = starCluster.mass;
        this->radius = starCluster.radius;
        this->distanceFromCenterOfGalaxy = starCluster.distanceFromCenterOfGalaxy;
        this->rotationSpeed = starCluster.rotationSpeed;
        this->luminosity = starCluster.luminosity;
        this->stars = starCluster.stars;
    }
    return *this;
}

double StarCluster::getDistanceFromCenterOfGalaxy() const {
    return this->distanceFromCenterOfGalaxy;
}

void StarCluster::setDistanceFromCenterOfGalaxy(double distanceFromCenterOfGalaxy) {
    this->distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
}

double StarCluster::getRotationSpeed() const {
    return this->rotationSpeed;
}

void StarCluster::setRotationSpeed(double rotationSpeed) {
    this->rotationSpeed = rotationSpeed;
}
