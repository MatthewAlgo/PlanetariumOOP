#include "hyperGiantStar.h"

HyperGiantStar::HyperGiantStar(const std::string& name, double mass, double radius, double distanceFromSun, double orbitSpeed)
        : Star(name, mass, radius, distanceFromSun, orbitSpeed), expansionScale(0), expansionSpeed(0){}

void HyperGiantStar::draw()
{
    std::cout << "Drawing a hyperGiantStar" << std::endl;
}

HyperGiantStar::~HyperGiantStar()
{
}

HyperGiantStar::HyperGiantStar(const HyperGiantStar& hyperGiantStar) : Star(hyperGiantStar)
{
    this->expansionScale = hyperGiantStar.expansionScale;
    this->expansionSpeed = hyperGiantStar.expansionSpeed;
}

HyperGiantStar& HyperGiantStar::operator=(const HyperGiantStar& hyperGiantStar)
{
    if (this != &hyperGiantStar)
    {
        Star::operator=(hyperGiantStar);
        this->expansionScale = hyperGiantStar.expansionScale;
        this->expansionSpeed = hyperGiantStar.expansionSpeed;
    }
    return *this;
}

//// Getters and setters
//[[maybe_unused]]
//double HyperGiantStar::getExpansionScale() const
//{
//    return this->expansionScale;
//}
//[[maybe_unused]]
//void HyperGiantStar::setExpansionScale(double expScale)
//{
//    this->expansionScale = expScale;
//}
//[[maybe_unused]]
//double HyperGiantStar::getExpansionSpeed() const
//{
//    return this->expansionSpeed;
//}
//[[maybe_unused]]
//void HyperGiantStar::setExpansionSpeed(double expSpeed)
//{
//    this->expansionSpeed = expSpeed;
//}

// Overloaded operators

std::ostream& operator<<(std::ostream& os, const HyperGiantStar& hyperGiantStar)
{
    os << "HyperGiantStar: " << hyperGiantStar.name << std::endl;
    os << "Mass: " << hyperGiantStar.mass << std::endl;
    os << "Radius: " << hyperGiantStar.radius << std::endl;
    os << "Orbit speed: " << hyperGiantStar.orbitSpeed << std::endl;
    os << "Expansion scale: " << hyperGiantStar.expansionScale << std::endl;
    os << "Expansion speed: " << hyperGiantStar.expansionSpeed << std::endl;
    return os;
}