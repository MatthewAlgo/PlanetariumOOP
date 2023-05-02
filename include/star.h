#ifndef STAR_H
#define STAR_H

#include "celestialObject.h"
#include "planet.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <string>

#define NOT_PART_OF_A_GALAXY -1
#define PART_OF_A_GALAXY 1

class Star : public CelestialObject
{
protected:
    double mass;
    double radius;
    double orbitSpeed;
    double distanceFromCenterOfGalaxy;

    std::vector<Planet> planets;

    // Image of the star
    std::shared_ptr<sf::CircleShape> starObj;

public:
    // Constructor, destructor, copy constructor, assignment operator, getters and setters
    void draw(std::shared_ptr<sf::RenderWindow> window) override;

    // Constructor
    Star(const std::string& name, double mass, double radius, double orbitSpeed, double distanceFromCenterOfGalaxy, double gal_X, double gal_Y, double gal_R, std::shared_ptr<sf::RenderWindow> window);

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
