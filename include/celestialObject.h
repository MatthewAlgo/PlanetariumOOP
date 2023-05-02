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

    // Getters and setters for all the private variables
    //    std::string getName() const;
    //    void setName(std::string name);
    //    double getColor() const;
    //    void setColor(double color);
    //    double getTexture() const;
    //    void setTexture(double texture);
    
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) = 0;
    // Constructor
    CelestialObject(const std::string& name, double color, double texture);
    virtual ~CelestialObject();

    std::pair<double, double> getPositon() const;
    void setPositon(const std::pair<double, double>& position);
};


#endif