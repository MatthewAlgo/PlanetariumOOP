#include "planet.h"

// Constructor
Planet::Planet(std::string name, double mass, double radius, double distanceFromSun, double orbitSpeed) : CelestialObject(name, 0, 0)
{
    this->mass = mass;
    this->radius = radius;
    this->distanceFromSun = distanceFromSun;
    this->orbitSpeed = orbitSpeed;
}

// Getters and setters for all the private variables
double Planet::getMass() const
{
    return this->mass;
}

void Planet::setMass(double mass)
{
    this->mass = mass;
}

double Planet::getRadius() const
{
    return this->radius;
}

void Planet::setRadius(double radius)
{
    this->radius = radius;
}

double Planet::getDistanceFromSun() const
{
    return this->distanceFromSun;
}

void Planet::setDistanceFromSun(double distanceFromSun)
{
    this->distanceFromSun = distanceFromSun;
}

double Planet::getOrbitSpeed() const
{
    return this->orbitSpeed;
}

void Planet::setOrbitSpeed(double orbitSpeed)
{
    this->orbitSpeed = orbitSpeed;
}

double Planet::getColor() const
{
    return this->color;
}

void Planet::setColor(double color)
{
    this->color = color;
}

double Planet::getTexture() const
{
    return this->texture;
}

void Planet::setTexture(double texture)
{
    this->texture = texture;
}

double Planet::getRotationSpeed() const
{
    return this->rotationSpeed;
}

void Planet::setRotationSpeed(double rotationSpeed)
{
    this->rotationSpeed = rotationSpeed;
}

double Planet::getRotationAngle() const
{
    return this->rotationAngle;
}

void Planet::setRotationAngle(double rotationAngle)
{
    this->rotationAngle = rotationAngle;
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
{}

// Getter for the moons
std::vector<Moon>& Planet::getMoons()
{
    return this->moons;
}
