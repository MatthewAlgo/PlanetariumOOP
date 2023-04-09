#include "abstract/universe.h"

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

void Universe::createBigBang() {
    // Create the big bang - init the stars, galaxies, black holes, etc.
    for (int i = 0; i < numberOfGalaxies; i++) {
        std::string name = "Galaxy " + std::to_string(i);
        Galaxy galaxy(name, i, i);
        for (int j = 0; j < Constants::NUMBER_OF_STARS_PER_GALAXY; j++) {
            std::string starName = "Star " + std::to_string(j);
            Star star(starName, Constants::STARMASS_MASSIVE, i, j, i);
            galaxy.addStar(star);
        }
        if (galaxy.getRotationSpeed() == 0 && galaxy.getLuminosity() == 0) {
            galaxy.setRotationSpeed(i * Constants::ROTATION_SPEED_CONSTANT);
            galaxy.setLuminosity(i * Constants::LUMINOSITY_CONSTANT);
        }
        addGalaxy(galaxy);
    }
    startTime();
}

void Universe::startTime(){
    // Start the time
    begin = std::chrono::high_resolution_clock::now();
}

// Check the time
void Universe::checkTime(){
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time since big bang = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time since big bang = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << "[s]" << std::endl;
}