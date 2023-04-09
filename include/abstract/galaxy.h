#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <iostream>
#include "abstract/starCluster.h"

class Galaxy
{
    private:
    std::string name;
    double distanceFromCenterOfUniverse;
    double rotationSpeed;
    double radius;
    double luminosity;

    std::vector<StarCluster> starClusters;
    std::vector<Star> lonelyStars;
public:
    friend std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy);

    // Constructor, copy constructor and assignment operator
    Galaxy(const std::string& name, double distanceFromCenterOfUniverse, double radius);
    Galaxy(const Galaxy& galaxy);
    ~Galaxy();

    // Getter and setter for the rotation speed and luminosity
    double getRotationSpeed() const;
    void setRotationSpeed(double rotationSpeed);
    double getLuminosity() const;
    void setLuminosity(double luminosity);

    Galaxy& operator=(const Galaxy& galaxy);
    bool operator==(const Galaxy& galaxy);

    void addStar(const Star& star);
};


#endif // !GALAXY_H