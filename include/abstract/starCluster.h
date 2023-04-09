#ifndef STAR_CLUSTER_H
#define STAR_CLUSTER_H

#include "star.h"
#include <vector>

class StarCluster
{
private:
    double distanceFromCenterOfGalaxy;
    double rotationSpeed;
    double mass;
    double radius;
    double luminosity;

    std::vector<Star> stars;

public:
    friend std::ostream& operator<<(std::ostream& os, const StarCluster& starCluster);

//    double getDistanceFromCenterOfGalaxy() const;
//    double getRotationSpeed() const;
//    double getMass() const;
//    double getRadius() const;
//    double getLuminosity() const;

    // Constructor, copy constructor and assignment operator
    StarCluster(double distanceFromCenterOfGalaxy, double radius);
    StarCluster(const StarCluster& starCluster);
    StarCluster& operator=(const StarCluster& starCluster);
};

#endif // !STAR_CLUSTER_H  