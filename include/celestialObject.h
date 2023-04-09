#ifndef CELESTIAL_OBJECT_H
#define CELESTIAL_OBJECT_H

#include <string>
#include <iostream>

// Create a pure virtual class
class CelestialObject
{
protected:
    std::string name;
    double color;
    double texture;

    // Getters and setters for all the private variables
//    std::string getName() const;
//    void setName(std::string name);
//    double getColor() const;
//    void setColor(double color);
//    double getTexture() const;
//    void setTexture(double texture);

    // Pure virtual function
    virtual void draw() = 0;
    // Constructor
    CelestialObject(const std::string& name, double color, double texture);
    virtual ~CelestialObject();

};


#endif