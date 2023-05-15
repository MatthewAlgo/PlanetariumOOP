#ifndef CELESTIAL_OBJECT_H
#define CELESTIAL_OBJECT_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Create a pure virtual class
class CelestialObject
{
protected:
    std::string name;
    sf::Color color;
    double texture;

    std::pair<double, double> position;


    public:
    virtual void draw(sf::RenderWindow* window) = 0;
    CelestialObject(const std::string& name, double color, double texture);
    virtual ~CelestialObject();
    // Operator overloading =
    CelestialObject& operator=(const CelestialObject& celestialObject);
    // Operator overloading copy constructor
    CelestialObject(const CelestialObject& celestialObject);

    std::pair<double, double> getPosition() const;
    void setPosition(const std::pair<double, double>& position);
};


#endif