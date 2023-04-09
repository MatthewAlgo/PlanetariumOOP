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