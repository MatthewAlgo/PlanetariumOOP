#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <iostream>
#include "abstract/starCluster.h"

class Galaxy
{
    private:
    double distanceFromCenterOfUniverse;
    double rotationSpeed;
    double radius;
    double luminosity;

    std::vector<StarCluster> starClusters;
public:
    friend std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy);

    // Constructor, copy constructor and assignment operator
    Galaxy(double distanceFromCenterOfUniverse, double radius);
    Galaxy(const Galaxy& galaxy);
    ~Galaxy();

    Galaxy& operator=(const Galaxy& galaxy);
    bool operator==(const Galaxy& galaxy);
};


#endif // !GALAXY_H