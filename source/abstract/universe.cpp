#include "abstract/universe.h"
#include "except/exceptions.h"
#include "structs/mt_randomengine.h"

int Universe::numberOfUniverseObjects = 0;

Universe::Universe(int nOg) {
    numberOfGalaxies = nOg;
}

//[[maybe_unused]]
//void Universe::draw() {
//    // Draw the universe
//}
//
//[[maybe_unused]]
//void Universe::addGalaxy(Galaxy galaxy) {
//    this->galaxies.push_back(galaxy);
//}
//[[maybe_unused]]
//void Universe::removeGalaxy(const Galaxy& galaxy) {
//    for (int i = 0; i < galaxies.size(); i++) {
//        if (galaxies[i] == galaxy) {
//            galaxies.erase(galaxies.begin() + i);
//        }
//    }
//}
//
//void Universe::removeGalaxy(int index) {
//    galaxies.erase(galaxies.begin() + index);
//}
//
//void Universe::removeAllGalaxies() {
//    galaxies.clear();
//}
//
//void Universe::setNumberOfGalaxies(int nOg) {
//    numberOfGalaxies = nOg;
//}
//
//int Universe::getNumberOfGalaxies() {
//    return numberOfGalaxies;
//}
//
//std::vector<Galaxy> Universe::getGalaxies() {
//    return galaxies;
//}

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

// void Universe::createBigBang(MainWindowClass* window) {
//     // Create the big bang - init the stars, galaxies, black holes, etc.
//     // The problem is not from here
//     if (window->getWindow() == nullptr) {
//         throw WindowNotFoundException("Window not found");
//     }

//     for (int i = 0; i < numberOfGalaxies; i++) {
//         std::string name = "Galaxy " + std::to_string(i);
//         Galaxy galaxy(name, i, 100);
//         // Add stars to the galaxy
//         for (int j = 0; j < Constants::NUMBER_OF_STARS_PER_GALAXY; j++) {
//             std::string starName = "Star " + std::to_string(j);
//             window->getObjectsToBeDrawn().push_back(new Star(starName, Constants::STARMASS_MASSIVE, 2, j, 1, galaxy.getPosition().first, galaxy.getPosition().second, galaxy.getRadius()));
//             galaxy.addStar(dynamic_cast<Star&>(*window->getObjectsToBeDrawn()[window->getObjectsToBeDrawn().size() - 1]));
//             // Get the position of the star
//             std::pair<int, int> starPosition = window->getObjectsToBeDrawn().back()->getPosition();

//             // Add planets to the star
//             for(int k = 0; k < Constants::PLANETS_PER_STAR; ++k){
//                 std::string planetName = "Planet " + std::to_string(k);            
//                 window->getObjectsToBeDrawn().push_back(new Planet(planetName, Constants::PLANETMASS_MASSIVE, 1, 1, 1, starPosition.first, starPosition.second, Constants::STAR_ORBIT_SIZE)); // Draw the planet relative to the star
//                 galaxy.getLonelyStars().back().addPlanet(dynamic_cast<Planet&>(*window->getObjectsToBeDrawn()[window->getObjectsToBeDrawn().size() - 1]));
            
//                 // Get the position of the planet
//                 std::pair<int, int> planetPosition = window->getObjectsToBeDrawn().back()->getPosition();

//                 for (int l = 0; l < Constants::MOONS_PER_PLANET; ++l){
//                     std::string moonName = "Moon " + std::to_string(l);
//                     window->getObjectsToBeDrawn().push_back(new Moon(moonName, Constants::MOONMASS_MASSIVE, 1, 1, 1, planetPosition.first, planetPosition.second, Constants::PLANET_ORBIT_SIZE)); // Draw the moon relative to the planet
//                     galaxy.getLonelyStars().back().getPlanets().back().addMoon(dynamic_cast<Moon&>(*window->getObjectsToBeDrawn()[window->getObjectsToBeDrawn().size() - 1]));
//                 }
//             }
//         }
//         if (galaxy.getRotationSpeed() == 0 && galaxy.getLuminosity() == 0) {
//             galaxy.setRotationSpeed(i * Constants::ROTATION_SPEED_CONSTANT);
//             galaxy.setLuminosity(i * Constants::LUMINOSITY_CONSTANT);
//         }
//         addGalaxy(galaxy);
//     }

//     startTime();
// }


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
            window->addObjectToBeDrawn(new Star(starName, Constants::STARMASS_MASSIVE, 2, j, 1, galaxy.getPosition().first, galaxy.getPosition().second, galaxy.getRadius()));
            CelestialObject* star = window->getObjectsToBeDrawn().back();

            // Add planets to the star
            for(int k = 0; k < Constants::PLANETS_PER_STAR; ++k){
                std::string planetName = "Planet " + std::to_string(k);

                // Add the planet object to the window and to the star
                window->addObjectToBeDrawn(new Planet(planetName, Constants::PLANETMASS_MASSIVE, 1, 1, 1, star->getPosition().first, star->getPosition().second, Constants::STAR_ORBIT_SIZE));
                CelestialObject* planet = window->getObjectsToBeDrawn().back();
                
                // Add moons to the planet
                for (int l = 0; l < Constants::MOONS_PER_PLANET; ++l){
                    std::string moonName = "Moon " + std::to_string(l);

                    // Add the moon object to the window and to the planet
                    window->addObjectToBeDrawn(new Moon(moonName, Constants::MOONMASS_MASSIVE, 1, 1, 1, planet->getPosition().first, planet->getPosition().second, Constants::PLANET_ORBIT_SIZE));
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