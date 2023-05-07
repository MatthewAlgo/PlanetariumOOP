#ifndef MOON_H
#define MOON_H
#include "celestialObject.h"
#include <iostream>

class Moon : public CelestialObject
{
private:
    double mass;
    double radius;
    double distanceFromPlanet;
    double orbitSpeed;
    double rotationSpeed;
    double rotationAngle;

public:
    Moon();
    void draw(sf::RenderWindow* window) override;

    // Constructor
    // Moon(moonName, Constants::MOONMASS_MASSIVE, 1, 1, 1, planetPosition.first, planetPosition.second, Constants::PLANET_ORBIT_SIZE)
    Moon(const std::string& name, double mass, double radius, double distanceFromPlanet, double orbitSpeed, double planetX, double planetY, double planetOrbitR);

    // Getters and setters for all the private variables
//    double getMass();
//    void setMass(double mass);
//    double getRadius();
//    void setRadius(double radius);
//    double getDistanceFromPlanet();
//    void setDistanceFromPlanet(double distanceFromPlanet);
//    double getOrbitSpeed();
//    void setOrbitSpeed(double orbitSpeed);
//    double getRotationSpeed();
//    void setRotationSpeed(double rotationSpeed);
//    double getColor();
//    void setColor(double color);
//    double getTexture();
//    void setTexture(double texture);
//    double getRotationAngle();
//    void setRotationAngle(double rotationAngle);

    // friend ostream for <<
    friend std::ostream& operator<<(std::ostream& os, const Moon& moon);

    // Destructor, copy constructor and assignment operator
    ~Moon();
    Moon(const Moon& moon);
    Moon& operator=(const Moon& moon);
};

#endif