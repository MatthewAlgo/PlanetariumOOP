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
    void draw(std::shared_ptr<sf::RenderWindow> window) override;

    // Constructor
    Planet(const std::string& name, double mass, double radius, double distanceFromSun, double orbitSpeed);

    // Getters and setters for all the private variables
//    double getMass() const;
//    void setMass(double mass);
//    double getRadius() const;
//    void setRadius(double radius);
//    double getDistanceFromSun() const;
//    void setDistanceFromSun(double distanceFromSun);
//    double getOrbitSpeed() const;
//    void setOrbitSpeed(double orbitSpeed);
//    double getColor() const;
//    void setColor(double color);
//    double getTexture() const;
//    void setTexture(double texture);

//    std::vector<Moon>& getMoons();
    void setMoons(const std::vector<Moon>& moons);

    // friend ostream for <<
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);

    // Copy constructor, assignment operator, destructor
    Planet(const Planet& planet);
    Planet& operator=(const Planet& planet);
    ~Planet();

};


#endif