#ifndef STAR_H
#define STAR_H

#include "celestialObject.h"
#include "planet.h"
#include <SFML/Graphics.hpp>

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

    // Image of the star
    sf::CircleShape* starObj;

public:
    // Constructor, destructor, copy constructor, assignment operator, getters and setters
    void draw(sf::RenderWindow* window) override;
    void drawHalo(sf::RenderWindow* window, double radius);
    
    // Constructor
    Star(const std::string& name, double mass, double radius, double orbitSpeed, double distanceFromCenterOfGalaxy, double gal_X, double gal_Y, double gal_R);
    // Star(name, mass, radius, orbitSpeed, distanceFromCenterOfGalaxy, gal_X, gal_Y, gal_R, window)


    std::vector<Planet> &getPlanets();
    void addPlanet(const Planet& planet);

    // friend ostream for <<
    friend std::ostream &operator<<(std::ostream &os, const Star &star);
    double getRadius() const; 

    // Copy constructor, assignment operator, destructor
    Star(const Star &star);
    Star &operator=(const Star &star);
    ~Star();
};

#endif // STAR_H
