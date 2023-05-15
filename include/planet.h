#ifndef PLANET_H
#define PLANET_H

#include "celestialObject.h"
#include "moon.h"
#include <iostream>
#include <vector>
#include <string>

class Planet : public CelestialObject
{   
private:
    double mass;
    double radius;
    double distanceFromSun;
    double orbitSpeed;

    std::vector<Moon> moons;

public:
    void draw(sf::RenderWindow* window) override;
    void drawRings(sf::RenderWindow* window, double radius);

    // Constructor
    Planet(const std::string& n, double m, double r, double d, double o, double StarX, double StarY, double StarR);

    void setMoons(const std::vector<Moon>& moons);
    void addMoon(const Moon& moon);
    // friend ostream for <<
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    double getRadius() const;

    // Copy constructor, assignment operator, destructor
    Planet(const Planet& planet);
    Planet& operator=(const Planet& planet);
    ~Planet();

};


#endif