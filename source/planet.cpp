#include "planet.h"

// Constructor
Planet::Planet(std::string name, double mass, double radius, double distFromSun, double orbitSpeed) : CelestialObject(name, 0, 0)
{
    this->mass = mass;
    this->radius = radius;
    this->distanceFromSun = distFromSun;
    this->orbitSpeed = orbitSpeed;
}

// Getters and setters for all the private variables
[[maybe_unused]]
double Planet::getMass() const
{
    return mass;
}
[[maybe_unused]]
void Planet::setMass(double m)
{
    mass = m;
}
[[maybe_unused]]
double Planet::getRadius() const
{
    return radius;
}
[[maybe_unused]]
void Planet::setRadius(double r)
{
    radius = r;
}
[[maybe_unused]]
double Planet::getDistanceFromSun() const
{
    return distanceFromSun;
}
[[maybe_unused]]
void Planet::setDistanceFromSun(double dist)
{
    this->distanceFromSun = dist;
}
[[maybe_unused]]
double Planet::getOrbitSpeed() const
{
    return this->orbitSpeed;
}
[[maybe_unused]]
void Planet::setOrbitSpeed(double os)
{
    this->orbitSpeed = os;
}
[[maybe_unused]]
double Planet::getColor() const
{
    return this->color;
}
[[maybe_unused]]
void Planet::setColor(double c)
{
    this->color = c;
}
[[maybe_unused]]
double Planet::getTexture() const
{
    return texture;
}
[[maybe_unused]]
void Planet::setTexture(double t)
{
    this->texture = t;
}
[[maybe_unused]]
double Planet::getRotationSpeed() const
{
    return rotationSpeed;
}
[[maybe_unused]]
void Planet::setRotationSpeed(double rs)
{
    rotationSpeed = rs;
}
[[maybe_unused]]
double Planet::getRotationAngle() const
{
    return rotationAngle;
}
[[maybe_unused]]
void Planet::setRotationAngle(double rA)
{
    this->rotationAngle = rA;
}

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
    this->rotationSpeed = planet.rotationSpeed;
    this->color = planet.color;
    this->texture = planet.texture;
    this->rotationSpeed = planet.rotationSpeed;
    this->rotationAngle = planet.rotationAngle;
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
        this->rotationSpeed = planet.rotationSpeed;
        this->color = planet.color;
        this->texture = planet.texture;
        this->rotationSpeed = planet.rotationSpeed;
        this->rotationAngle = planet.rotationAngle;
        this->name = planet.name;
        this->moons = planet.moons;
    }

    return *this;
}

Planet::~Planet()
{
}

void Planet::draw()
{
    std::cout << "Drawing planet: " << this->name << std::endl;
}

// Getter for the moons
std::vector<Moon>& Planet::getMoons()
{
    return this->moons;
}
