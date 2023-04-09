#include <iostream>
#include "abstract/universe.h"
#include "star.h"
#include "blackHole.h"
#include "abstract/galaxy.h"
#include "constants.h"

void init() {
    // Initialize the universe
    Universe universe(Constants::NUMBER_OF_GALAXIES);
    for(int i = 0; i < Constants::NUMBER_OF_GALAXIES; i++) {
        std::string name = "Galaxy " + std::to_string(i);
        Galaxy galaxy(name, i, i);
        for(int j = 0; j < Constants::NUMBER_OF_STARS_PER_GALAXY; j++) {
            std::string starName = "Star " + std::to_string(j);
            Star star(starName, Constants::STARMASS_MASSIVE, i, j, i);
            galaxy.addStar(star);
        }
        if(galaxy.getRotationSpeed() == 0 && galaxy.getLuminosity() == 0) {
            galaxy.setRotationSpeed(i * Constants::ROTATION_SPEED_CONSTANT);
            galaxy.setLuminosity(i * Constants::LUMINOSITY_CONSTANT);
        }
        universe.addGalaxy(galaxy);
    }
    BlackHole blackHole("Black Hole", Constants::BLACKHOLEMASS_SUPERMASSIVE, Constants::BLACKHOLEMASS_SUPERMASSIVE, Constants::BLACKHOLEMASS_SUPERMASSIVE, Constants::BLACKHOLEMASS_SUPERMASSIVE);
    std::cout<<blackHole<<std::endl;

    std::cout<<universe<<std::endl;
}

int main() {
    init();
    return 0;
}
