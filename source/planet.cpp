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


Planet::~Planet()
{
}

[[maybe_unused]]
void Planet::draw(sf::RenderWindow* window)
{

    if (window == nullptr)
    {
        std::cout<<"Window is null"<<std::endl;
        exit(1);
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

// Swap function
void Planet::swap(Planet& first, Planet& second) {
    using std::swap;

    CelestialObject::swap(static_cast<CelestialObject&>(first), static_cast<CelestialObject&>(second));


    // Swap member variables
    swap(first.mass, second.mass);
    swap(first.radius, second.radius);
    swap(first.distanceFromSun, second.distanceFromSun);
    swap(first.orbitSpeed, second.orbitSpeed);
    swap(first.moons, second.moons);
}

// Copy constructor
Planet::Planet(const Planet& other) : CelestialObject(other), mass(other.mass), radius(other.radius),
                                      distanceFromSun(other.distanceFromSun), orbitSpeed(other.orbitSpeed),
                                      moons(other.moons) {}

// Assignment operator
Planet& Planet::operator=(Planet other) {
    swap(*this, other); // Swap the content of 'this' and 'other'
    return *this;
}

void Planet::setMoons(const std::vector<Moon> &m) {
    this->moons = m;
}
