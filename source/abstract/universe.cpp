#include "abstract/universe.h"

Universe::Universe() {
    numberOfGalaxies = 0;
}

Universe::Universe(int nOg) {
    numberOfGalaxies = nOg;
}

void Universe::draw() {
    // Draw the universe
}

void Universe::addGalaxy(Galaxy galaxy) {
    this->galaxies.push_back(galaxy);
}

void Universe::removeGalaxy(Galaxy galaxy) {
    for (int i = 0; i < galaxies.size(); i++) {
        if (galaxies[i] == galaxy) {
            galaxies.erase(galaxies.begin() + i);
        }
    }
}

void Universe::removeGalaxy(int index) {
    galaxies.erase(galaxies.begin() + index);
}

void Universe::removeAllGalaxies() {
    galaxies.clear();
}

void Universe::setNumberOfGalaxies(int nOg) {
    numberOfGalaxies = nOg;
}

int Universe::getNumberOfGalaxies() {
    return numberOfGalaxies;
}

std::vector<Galaxy> Universe::getGalaxies() {
    return galaxies;
}

Universe::~Universe() {
    removeAllGalaxies();
}

Universe::Universe(const Universe& universe) {
    numberOfGalaxies = universe.numberOfGalaxies;
    galaxies = universe.galaxies;
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
    for (int i = 0; i < universe.galaxies.size(); i++) {
        os << universe.galaxies[i] << std::endl;
    }
    return os;
}