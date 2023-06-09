#include "star.h"
#include "structs/mt_randomengine.h"
#include "constants.h"
#include "except/exceptions.h"

[[maybe_unused]]
void Star::draw(sf::RenderWindow* window) {
    // Draw a yellow small circle for the star at the position position

    
    if (window == nullptr)
    {
        std::cout<<"Window is null"<<std::endl;
        exit(1);
    }
    

    sf::CircleShape star;
    star.setRadius(radius);
    star.setFillColor(sf::Color::Yellow);
    star.setPosition(position.first, position.second);
    window->draw(star);
}


// friend ostream for <<
std::ostream &operator<<(std::ostream &os, const Star &star) {
    os << "Star name: " << star.name << std::endl;
    os << "Star mass: " << star.mass << std::endl;
    os << "Star radius: " << star.radius << std::endl;
    os << "Star distance from center of galaxy: " << star.distanceFromCenterOfGalaxy << std::endl;
    os << "Star orbit speed: " << star.orbitSpeed << std::endl;
    for (int i = 0; i < (int)star.planets.size(); i++) {
        os << star.planets[i] << std::endl;
    }
    return os;
}

// Constructor
Star::Star(const std::string& n, double m, double r, double o, double d, double gal_X, double gal_Y, double gal_R) : CelestialObject(n, 0, 0), mass(m), radius(r),orbitSpeed(o), distanceFromCenterOfGalaxy(d) {
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
    if (distanceFromCenterOfGalaxy < 0) {
        throw PlanetariumArgumentException("Distance from center of galaxy cannot be negative");
    }

    // The star is not part of a galaxy
    if (distanceFromCenterOfGalaxy == Constants::NOT_PART_OF_A_GALAXY) {
        position = RandomEngine::randomPositionInRect(0, 0, Constants::WindowWidth, Constants::WindowHeight);
    } else if (distanceFromCenterOfGalaxy == Constants::PART_OF_A_GALAXY) {
        // Suppose the center of galaxy is at (Xgal, Ygal) and the radius of the galaxy is Rgal. The star should be in the circle of radius Rgal
        // The star should be at a random distance from the center of the galaxy in the circle
        position = RandomEngine::randomPositionInCircle(gal_X, gal_Y, gal_R);
    }

}

//// Implement getter for the moons vector
std::vector<Planet> &Star::getPlanets() {
   return planets;
}

void Star::addPlanet(const Planet& planet) {
    planets.push_back(planet);
}

void Star::drawHalo(sf::RenderWindow* window, double rad) {
    if (window == nullptr)
    {
        std::cout<<"Window is null"<<std::endl;
        exit(1); // No need to continue
    }
    sf::CircleShape halo;
    halo.setRadius(rad);
    halo.setFillColor(sf::Color::Red);
    halo.setOutlineThickness(1);
    halo.setOutlineColor(sf::Color::White);
    halo.setPosition(position.first - rad, position.second - rad);
    window->draw(halo);
}

double Star::getRadius() const {
    return radius;
}


// Destructor
Star::~Star() {
    delete starObj;
    // No additional cleanup needed for planets vector
}

// Swap function
void Star::swap(Star& first, Star& second) {
    using std::swap;

    // Swap base class member variables
    CelestialObject::swap(static_cast<CelestialObject&>(first), static_cast<CelestialObject&>(second));


    // Swap member variables
    swap(first.mass, second.mass);
    swap(first.radius, second.radius);
    swap(first.orbitSpeed, second.orbitSpeed);
    swap(first.distanceFromCenterOfGalaxy, second.distanceFromCenterOfGalaxy);
    swap(first.planets, second.planets);
    swap(first.starObj, second.starObj);
}

// Copy constructor
Star::Star(const Star& other) : CelestialObject(other), mass(other.mass), radius(other.radius), orbitSpeed(other.orbitSpeed), distanceFromCenterOfGalaxy(other.distanceFromCenterOfGalaxy), starObj(nullptr)
{
    // Deep copy the planets
    for (const auto& planet : other.planets)
    {
        planets.push_back(Planet(planet));
    }

    // Deep copy the star object
    if (other.starObj)
    {
        starObj = new sf::CircleShape(*other.starObj);
    }
}
// Assignment operator
Star& Star::operator=(Star other) {
    swap(*this, other); // Swap the content of 'this' and 'other'
    return *this;
}






