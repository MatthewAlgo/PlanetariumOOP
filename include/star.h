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
    double rotationSpeed;
    double rotationAngle;
    double distanceFromCenterOfGalaxy;

    std::string name;
    std::vector<Planet> planets;

public:
    // Constructor, destuctor, copy constructor, assignment operator, getters and setters
    void draw() override;

    // Constructor
    Star(std::string name, double mass, double radius, double distanceFromSun, double orbitSpeed);

    // Getters and setters for all the private variables
    double getMass() const;
    void setMass(double mass);
    double getRadius() const;
    void setRadius(double radius);
    double getDistanceFromCenterOfGalaxy() const;
    void setDistanceFromCenterOfGalaxy(double distanceFromSun);
    double getRotationSpeed() const;
    void setRotationSpeed(double rotationSpeed);
    double getRotationAngle() const;
    void setRotationAngle(double rotationAngle);
    // Getter for the planets vector
    std::vector<Planet> &getPlanets();

    // friend ostream for <<
    friend std::ostream &operator<<(std::ostream &os, const Star &star);

    // Copy constructor, assignment operator, destructor
    Star(const Star &star);
    Star &operator=(const Star &star);
    ~Star();
};

#endif // !STAR
