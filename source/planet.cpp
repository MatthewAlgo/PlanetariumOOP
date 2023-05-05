#include "planet.h"
#include "structs/mt_randomengine.h"

// Constructor
Planet::Planet(const std::string& n, double m, double r, double d, double o, double StarX, double StarY, double StarR) : CelestialObject(n, 0, 0), mass(m), radius(r), distanceFromSun(d), orbitSpeed(o) {
    // Init the variables
    if (radius < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    if (mass < 0) {
        throw std::invalid_argument("Mass cannot be negative");
    }
    if (orbitSpeed < 0) {
        throw std::invalid_argument("Orbit speed cannot be negative");
    }
    if (distanceFromSun < 0) {
        throw std::invalid_argument("Distance from sun cannot be negative");
    }

    // The star is not part of a galaxy
    position = randomPositionInCircle(StarX, StarY, StarR);
}

// Getters and setters for all the private variables
//[[maybe_unused]]
//double Planet::getMass() const
//{
//    return mass;
//}
//[[maybe_unused]]
//void Planet::setMass(double m)
//{
//    mass = m;
//}
//[[maybe_unused]]
//double Planet::getRadius() const
//{
//    return radius;
//}
//[[maybe_unused]]
//void Planet::setRadius(double r)
//{
//    radius = r;
//}
//[[maybe_unused]]
//double Planet::getDistanceFromSun() const
//{
//    return distanceFromSun;
//}
//[[maybe_unused]]
//void Planet::setDistanceFromSun(double dist)
//{
//    this->distanceFromSun = dist;
//}
//[[maybe_unused]]
//double Planet::getOrbitSpeed() const
//{
//    return this->orbitSpeed;
//}
//[[maybe_unused]]
//void Planet::setOrbitSpeed(double os)
//{
//    this->orbitSpeed = os;
//}
//[[maybe_unused]]
//double Planet::getColor() const
//{
//    return this->color;
//}
//[[maybe_unused]]
//void Planet::setColor(double c)
//{
//    this->color = c;
//}
//[[maybe_unused]]
//double Planet::getTexture() const
//{
//    return texture;
//}
//[[maybe_unused]]
//void Planet::setTexture(double t)
//{
//    this->texture = t;
//}
//[[maybe_unused]]
//double Planet::getRotationSpeed() const
//{
//    return rotationSpeed;
//}
//[[maybe_unused]]
//void Planet::setRotationSpeed(double rs)
//{
//    rotationSpeed = rs;
//}
//[[maybe_unused]]
//double Planet::getRotationAngle() const
//{
//    return rotationAngle;
//}
//[[maybe_unused]]
//void Planet::setRotationAngle(double rA)
//{
//    this->rotationAngle = rA;
//}

// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const Planet &planet)
{
    os << "Planet: " << planet.name << std::endl;
    os << "Mass: " << planet.mass << std::endl;
    os << "Radius: " << planet.radius << std::endl;
    os << "Distance from sun: " << planet.distanceFromSun << std::endl;
    os << "Orbit speed: " << planet.orbitSpeed << std::endl;
    return os;
}

// Copy constructor, assignment operator, destructor
Planet::Planet(const Planet &planet) : CelestialObject(planet.name, 0, 0)
{
    this->mass = planet.mass;
    this->radius = planet.radius;
    this->distanceFromSun = planet.distanceFromSun;
    this->orbitSpeed = planet.orbitSpeed;
    this->color = planet.color;
    this->texture = planet.texture;
    this->name = planet.name;
    this->moons = planet.moons;
}

Planet &Planet::operator=(const Planet &planet)
{
    if (this != &planet)
    {
        this->mass = planet.mass;
        this->radius = planet.radius;
        this->distanceFromSun = planet.distanceFromSun;
        this->orbitSpeed = planet.orbitSpeed;
        this->color = planet.color;
        this->texture = planet.texture;
        this->name = planet.name;
        this->moons = planet.moons;
    }

    return *this;
}

Planet::~Planet()
{
}

void Planet::draw(sf::RenderWindow* window)
{
    // Draw the planet
    sf::CircleShape planet(this->radius);
    planet.setFillColor(sf::Color::Red);
    planet.setPosition(position.first, position.second);
    window->draw(planet);

    // Draw the moons
    for (auto& moon : this->moons)
    {
        moon.draw(window);
    }
}

// Getter for the moons
//std::vector<Moon>& Planet::getMoons()
//{
//    return this->moons;
//}
