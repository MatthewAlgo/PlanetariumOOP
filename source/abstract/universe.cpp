#include "abstract/universe.h"
#include "except/exceptions.h"
#include "structs/mt_randomengine.h"
#include "planetfactory.h"
#include "starfactory.h"
#include "moonfactory.h"

int Universe::numberOfUniverseObjects = 0;

Universe::Universe(int nOg) {
    numberOfGalaxies = nOg;
}



Universe::~Universe() {
    // removeAllGalaxies();
}

Universe::Universe(const Universe& universe) : galaxies(universe.galaxies) {
    numberOfGalaxies = universe.numberOfGalaxies;
}

Universe& Universe::operator=(const Universe& universe) {
    if (this != &universe) {
        numberOfGalaxies = universe.numberOfGalaxies;
        galaxies = universe.galaxies;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Universe& universe) {
    os << "Number of galaxies: " << universe.numberOfGalaxies << std::endl;
    os << "Galaxies: " << std::endl;
    for (int i = 0; i < (int)universe.galaxies.size(); i++) {
        os << universe.galaxies[i] << std::endl;
    }
    return os;
}

void Universe::addGalaxy(const Galaxy& galaxy) {
    galaxies.push_back(galaxy);
}


void Universe::createBigBang(MainWindowClass* window) {
    // Create the big bang - init the stars, galaxies, black holes, etc.
    // The problem is not from here
    if (window->getWindow() == nullptr) {
        throw WindowNotFoundException("Window not found");
    }

    for (int i = 0; i < numberOfGalaxies; i++) {
        std::string name = "Galaxy " + std::to_string(i);
        Galaxy galaxy(name, i, 100);

        // Add stars to the galaxy
        for (int j = 0; j < Constants::NUMBER_OF_STARS_PER_GALAXY; j++) {
            std::string starName = "Star " + std::to_string(j);

            // Add the star object to the window and to the galaxy
            window->addObjectToBeDrawn(new Star(StarFactory::createSmallStar(starName, galaxy.getPosition(), galaxy.getRadius())));
            CelestialObject* star = window->getObjectsToBeDrawn().back();

            // Add planets to the star
            for(int k = 0; k < Constants::PLANETS_PER_STAR; ++k){
                std::string planetName = "Planet " + std::to_string(k);

                // Add the planet object to the window and to the star
                window->addObjectToBeDrawn(new Planet(PlanetFactory::createSmallPlanet(starName, star->getPosition(), 1)));
                CelestialObject* planet = window->getObjectsToBeDrawn().back();
                
                // Add moons to the planet
                for (int l = 0; l < Constants::MOONS_PER_PLANET; ++l){
                    std::string moonName = "Moon " + std::to_string(l);

                    // Add the moon object to the window and to the planet
                    window->addObjectToBeDrawn(new Moon(MoonFactory::createSmallMoon(moonName, planet->getPosition(), 1)));
                }
            }
        }

        if (galaxy.getRotationSpeed() == 0 && galaxy.getLuminosity() == 0) {
            galaxy.setRotationSpeed(i * Constants::ROTATION_SPEED_CONSTANT);
            galaxy.setLuminosity(i * Constants::LUMINOSITY_CONSTANT);
        }

        // Add the galaxy object to the universe
        addGalaxy(galaxy);
    }

    startTime();
}

void Universe::startTime(){
    // Start the time
    begin = std::chrono::steady_clock::now();
}

// Check the time
int Universe::checkTime(){
    auto end = std::chrono::steady_clock::now();
    std::cout << "Time since big bang = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time since big bang = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;
    return (int)std::chrono::duration_cast<std::chrono::seconds> (end - begin).count();
}