#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <iostream>
#include "abstract/starCluster.h"
#include "constants.h"
#include "blackHole.h"

class Galaxy
{
protected:
    std::string name;
    double distanceFromCenterOfUniverse;
    double rotationSpeed;
    double radius;
    double luminosity;

    std::pair<double, double> position;

    std::vector<StarCluster> starClusters;
    std::vector<Star> lonelyStars;
    BlackHole blackHole;
public:
    friend std::ostream& operator<<(std::ostream& os, const Galaxy& galaxy);

    // Constructor, copy constructor and assignment operator
    Galaxy(const std::string& name, double distanceFromCenterOfUniverse, double radius, std::shared_ptr<sf::RenderWindow> window);
    Galaxy(const Galaxy& galaxy);
    ~Galaxy();

    // Getter and setter for the rotation speed and luminosity
    double getRotationSpeed() const;
    void setRotationSpeed(double rotationSpeed);
    double getLuminosity() const;
    void setLuminosity(double luminosity);

    Galaxy& operator=(const Galaxy& galaxy);
    bool operator==(const Galaxy& galaxy);

    void addStar(const Star& star);

    void draw(std::shared_ptr<sf::RenderWindow> window); // Draw the galaxy

    std::pair<double, double> getPosition() const;
    void setPosition(const std::pair<double, double>& position);
    double getRadius() const;
};


#endif // !GALAXY_H