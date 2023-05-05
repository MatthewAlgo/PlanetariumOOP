#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include "celestialObject.h"

class BlackHole : protected CelestialObject
{
protected:
    double activityLevel;
    double schwarzschildRadius;
    double radius;
    double mass;
public:
    void draw(sf::RenderWindow* window) override;
    BlackHole();
    BlackHole(const std::string& name, double activityLevel, double schwarzschildRadius, double radius, double mass);
    BlackHole(double activityLevel, double schwarzschildRadius, double radius, double mass);
    ~BlackHole();
    BlackHole(const BlackHole& blackHole);
    BlackHole& operator=(const BlackHole& blackHole);
    

    // Getters and setters for all the private variables
//    double getActivityLevel() const;
//    void setActivityLevel(double activityLevel);
//    double getSchwarzschildRadius() const;
//    void setSchwarzschildRadius(double schwarzschildRadius);
//    double getRadius() const;
//    void setRadius(double radius);
//    double getMass() const;
//    void setMass(double mass);

    friend std::ostream& operator<<(std::ostream& os, const BlackHole& blackHole);
};

#endif // !BLACK_HOLE_H