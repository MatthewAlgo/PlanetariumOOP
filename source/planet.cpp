#include "planet.h"
#include "structs/mt_randomengine.h"
#include "except/exceptions.h"

// Constructor
Planet::Planet(const std::string& n, double m, double r, double d, double o, double StarX, double StarY, double StarR) : CelestialObject(n, 0, 0), mass(m), radius(r), distanceFromSun(d), orbitSpeed(o) {
    // Init the variables
    if (radius < 0) {
        throw PlanetariumArgumentException("Radius cannot be negative");
    }
    if (mass < 0) {
        throw PlanetariumArgumentException("Mass cannot be negative");
    }
    if (orbitSpeed < 0) {
        throw PlanetariumArgumentException("Orbit speed cannot be negative");
    }
    if (distanceFromSun < 0) {
        throw PlanetariumArgumentException("Distance from sun cannot be negative");
    }

    // The star is not part of a galaxy
    position = RandomEngine::randomPositionInCircle(StarX, StarY, StarR);
}


double Planet::getRadius() const
{
   return radius;
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

[[maybe_unused]]
void Planet::draw(sf::RenderWindow* window)
{

    if (window == nullptr)
    {
        throw WindowNotFoundException("Window not found");
    }


    // Draw the planet
    sf::CircleShape planet(this->radius);
    planet.setFillColor(sf::Color::Red);
    planet.setPosition(position.first, position.second);
    window->draw(planet);

}

void Planet::addMoon(const Moon& moon)
{
    this->moons.push_back(moon);
}

void Planet::drawRings(sf::RenderWindow* window, double rad)
{
    // Draw the rings
    sf::CircleShape rings(rad);
    rings.setFillColor(sf::Color::Transparent);
    rings.setOutlineThickness(1);
    rings.setOutlineColor(sf::Color::White);
    rings.setPosition(position.first - (rad), position.second - (rad));
    window->draw(rings);
}