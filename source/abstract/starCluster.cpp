#include "abstract/starCluster.h"

// Implement // Constructor, copy constructor and assignment operator
StarCluster::StarCluster(double distanceFromCenterOfGalaxy, double radius) {
    this->distanceFromCenterOfGalaxy = distanceFromCenterOfGalaxy;
    this->rotationSpeed = 0;
    this->mass = 0;
    this->radius = radius;
    this->luminosity = 0;
}

StarCluster::StarCluster(const StarCluster& starCluster) {
    this->distanceFromCenterOfGalaxy = starCluster.distanceFromCenterOfGalaxy;
    this->rotationSpeed = starCluster.rotationSpeed;
    this->mass = starCluster.mass;
    this->radius = starCluster.radius;
    this->luminosity = starCluster.luminosity;
}

StarCluster& StarCluster::operator=(const StarCluster& starCluster) {
    this->distanceFromCenterOfGalaxy = starCluster.distanceFromCenterOfGalaxy;
    this->rotationSpeed = starCluster.rotationSpeed;
    this->mass = starCluster.mass;
    this->radius = starCluster.radius;
    this->luminosity = starCluster.luminosity;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const StarCluster &cluster) {
    os << "distanceFromCenterOfGalaxy: " << cluster.distanceFromCenterOfGalaxy << " rotationSpeed: "
       << cluster.rotationSpeed << " mass: " << cluster.mass << " radius: " << cluster.radius << " luminosity: "
       << cluster.luminosity << " stars: " << cluster.stars;
    return os;
}


