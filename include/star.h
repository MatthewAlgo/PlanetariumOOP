#ifndef STAR_H
#define STAR_H

#include "celestialObject.h"
#include "planet.h"
#include <iostream>
#include <vector>
#include <string>

class Star : public CelestialObject
{
protected:
    double mass;
    double radius;
    double orbitSpeed;
    double distanceFromCenterOfGalaxy;

    std::vector<Planet> planets;

public:
    // Constructor, destuctor, copy constructor, assignment operator, getters and setters
    void draw() override;

    // Constructor
    Star(const std::string& name, double mass, double radius, double distanceFromSun, double orbitSpeed);

    // Getters and setters for all the private variables
//    double getMass() const;
//    void setMass(double mass);
//    double getRadius() const;
//    void setRadius(double radius);
//    double getDistanceFromCenterOfGalaxy() const;
//    void setDistanceFromCenterOfGalaxy(double distanceFromSun);
//    // Getter for the planets vector
//    std::vector<Planet> &getPlanets();

    // friend ostream for <<
    friend std::ostream &operator<<(std::ostream &os, const Star &star);

    // Copy constructor, assignment operator, destructor
    Star(const Star &star);
    Star &operator=(const Star &star);
    ~Star();
};

#endif // STAR_H
