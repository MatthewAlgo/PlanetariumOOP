#include "hyperGiantStar.h"

HyperGiantStar:: HyperGiantStar(std::string name, double mass, double radius, double distanceFromSun, double orbitSpeed, double yearsToLive, double expansionScale, double expansionSpeed) 
        : Star(name, mass, radius, distanceFromSun, orbitSpeed)
{
    this->yearsToLive = 0;
    this->expansionScale = 0;
    this->expansionSpeed = 0;
}

void HyperGiantStar::draw()
{
    std::cout << "Drawing a hyperGiantStar" << std::endl;
}

HyperGiantStar::~HyperGiantStar()
{
}

HyperGiantStar::HyperGiantStar(const HyperGiantStar& hyperGiantStar) : Star(hyperGiantStar)
{
    this->yearsToLive = hyperGiantStar.yearsToLive;
    this->expansionScale = hyperGiantStar.expansionScale;
    this->expansionSpeed = hyperGiantStar.expansionSpeed;
}

HyperGiantStar& HyperGiantStar::operator=(const HyperGiantStar& hyperGiantStar)
{
    if (this != &hyperGiantStar)
    {
        Star::operator=(hyperGiantStar);
        this->yearsToLive = hyperGiantStar.yearsToLive;
        this->expansionScale = hyperGiantStar.expansionScale;
        this->expansionSpeed = hyperGiantStar.expansionSpeed;
    }
    return *this;
}

// Getters and setters
double HyperGiantStar::getYearsToLive() const
{
    return this->yearsToLive;
}

void HyperGiantStar::setYearsToLive(double yearsToLive)
{
    this->yearsToLive = yearsToLive;
}

double HyperGiantStar::getExpansionScale() const
{
    return this->expansionScale;
}

void HyperGiantStar::setExpansionScale(double expansionScale)
{
    this->expansionScale = expansionScale;
}

double HyperGiantStar::getExpansionSpeed() const
{
    return this->expansionSpeed;
}

void HyperGiantStar::setExpansionSpeed(double expansionSpeed)
{
    this->expansionSpeed = expansionSpeed;
}

// Overloaded operators

std::ostream& operator<<(std::ostream& os, const HyperGiantStar& hyperGiantStar)
{
    os << "HyperGiantStar: " << hyperGiantStar.name << std::endl;
    os << "Mass: " << hyperGiantStar.mass << std::endl;
    os << "Radius: " << hyperGiantStar.radius << std::endl;
    os << "Orbit speed: " << hyperGiantStar.orbitSpeed << std::endl;
    os << "Years to live: " << hyperGiantStar.yearsToLive << std::endl;
    os << "Expansion scale: " << hyperGiantStar.expansionScale << std::endl;
    os << "Expansion speed: " << hyperGiantStar.expansionSpeed << std::endl;
    return os;
}