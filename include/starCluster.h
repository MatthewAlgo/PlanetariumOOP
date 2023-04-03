#ifndef STAR_CLUSTER_H
#define STAR_CLUSTER_H

#include "star.h"
#include <vector>

class StarCluster : public CelestialObject
{
private:
    double distanceFromCenterOfGalaxy;
    double rotationSpeed;
    double mass;
    double radius;
    double luminosity;

    std::vector<Star> stars;

public:
    // Constructor, destructor, copy constructor, assignment operator, getters and setters
    StarCluster();
    void draw() override;
    StarCluster(std::string name, double mass, double radius, double distanceFromCenterOfGalaxy, double rotationSpeed, double luminosity);
    ~StarCluster();
    StarCluster(const StarCluster& starCluster);

    StarCluster& operator=(const StarCluster& starCluster);

    double getDistanceFromCenterOfGalaxy() const;
    void setDistanceFromCenterOfGalaxy(double distanceFromCenterOfGalaxy);
    double getRotationSpeed() const;
    void setRotationSpeed(double rotationSpeed);
    double getMass() const;
    void setMass(double mass);
    double getRadius() const;
    void setRadius(double radius);
    double getTemperature() const;
    void setTemperature(double temperature);
    double getLuminosity() const;
    void setLuminosity(double luminosity);

    friend std::ostream& operator<<(std::ostream& os, const StarCluster& starCluster);
};

#endif // !STAR_CLUSTER_H  