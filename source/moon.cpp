#include "moon.h"
#include "except/exceptions.h"
#include "structs/mt_randomengine.h"

// Implement all the functions in the header file

[[maybe_unused]] void Moon::draw(sf::RenderWindow *window)
{
    
    if (window == nullptr)
    {
        throw WindowNotFoundException("Window not found");
    }
    

    // Draw the moon
    sf::CircleShape moonDraw(this->radius);
    moonDraw.setFillColor(sf::Color::Blue);
    moonDraw.setPosition(position.first, position.second);
    window->draw(moonDraw);
}

double Moon::getRadius() const {
   return radius;
}

// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const Moon &moon)
{
    os << "Moon: " << moon.name << ", Mass: " << moon.mass << ", Radius: " << moon.radius << ", Distance from planet: " << moon.distanceFromPlanet << ", Orbit speed: " << moon.orbitSpeed << ", Rotation speed: " << moon.rotationSpeed << ", Texture: " << moon.texture << ", Rotation angle: " << moon.rotationAngle;
    return os;
}

// Destructor, copy constructor and assignment operator
Moon::~Moon()
{
    // std::cout << "Moon " << this->name << " destroyed!" << std::endl;
}

Moon::Moon(const std::string &name, double mass, double radius, double distanceFromPlanet, double orbitSpeed, double planetX, double planetY, double planetOrbitR)
    : CelestialObject(name, 0, 0), mass(mass), radius(radius), distanceFromPlanet(distanceFromPlanet), orbitSpeed(orbitSpeed), rotationSpeed(0), rotationAngle(0)
{
    // Init the variables
    if (radius < 0)
    {
        throw PlanetariumArgumentException("Radius cannot be negative");
    }
    if (mass < 0)
    {
        throw PlanetariumArgumentException("Mass cannot be negative");
    }
    if (orbitSpeed < 0)
    {
        throw PlanetariumArgumentException("Orbit speed cannot be negative");
    }
    if (planetOrbitR < 0)
    {
        throw PlanetariumArgumentException("planetOrbitR cannot be negative");
    }

    // The star is not part of a galaxy
    position = RandomEngine::randomPositionInCircle(planetX, planetY, planetOrbitR);
}

Moon::Moon(const Moon &moon) : CelestialObject(moon.name, 0, 0)
{
    // std::cout<<"Moon copy constructor called!"<<std::endl;
    this->mass = moon.mass;
    this->radius = moon.radius;
    this->distanceFromPlanet = moon.distanceFromPlanet;
    this->orbitSpeed = moon.orbitSpeed;
    this->rotationSpeed = moon.rotationSpeed;
    this->color = moon.color;
    this->texture = moon.texture;
    this->rotationAngle = moon.rotationAngle;
}

// Add the equal operator
Moon &Moon::operator=(const Moon &moon)
{
    // std::cout<<"Moon assignment operator called!"<<std::endl;
    this->mass = moon.mass;
    this->radius = moon.radius;
    this->distanceFromPlanet = moon.distanceFromPlanet;
    this->orbitSpeed = moon.orbitSpeed;
    this->rotationSpeed = moon.rotationSpeed;
    this->color = moon.color;
    this->texture = moon.texture;
    this->rotationAngle = moon.rotationAngle;
    return *this;
}

void Moon::drawOrbit(sf::RenderWindow* window, double rad){
    sf::CircleShape orbit(rad);
    orbit.setFillColor(sf::Color::Green);
    orbit.setOutlineThickness(1);
    orbit.setOutlineColor(sf::Color::Green);
    orbit.setPosition(position.first - rad, position.second - rad);
    window->draw(orbit);
}