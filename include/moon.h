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
    void draw(sf::RenderWindow *window) override;
    void drawOrbit(sf::RenderWindow *window, double radius);
    // Constructor
    // Moon(moonName, Constants::MOONMASS_MASSIVE, 1, 1, 1, planetPosition.first, planetPosition.second, Constants::PLANET_ORBIT_SIZE)
    Moon(const std::string &name, double mass, double radius, double distanceFromPlanet, double orbitSpeed, double planetX, double planetY, double planetOrbitR);

    // friend ostream for <<
    friend std::ostream &operator<<(std::ostream &os, const Moon &moon);

    // Destructor, copy constructor and assignment operator
    double getRadius() const;
    ~Moon();
    Moon(const Moon &moon);
    // Swap function
    void swap(Moon &first, Moon &second);

    // Assignment operator
    Moon &operator=(Moon other);
};

#endif