#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include "celestialObject.h"

class BlackHole : public CelestialObject
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
    


    friend std::ostream& operator<<(std::ostream& os, const BlackHole& blackHole);
};

#endif // !BLACK_HOLE_H