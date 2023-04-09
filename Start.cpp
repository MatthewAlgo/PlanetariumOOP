#include <iostream>
#include "abstract/universe.h"
#include "star.h"
#include "blackHole.h"
#include "abstract/galaxy.h"
#include "constants.h"

void init() {
    // Initialize the universe
    Universe universe(Constants::MEDIUM_NUMBER_OF_GALAXIES);
    universe.createBigBang();
    std::cout<<universe<<std::endl;
    universe.checkTime();
}

int main() {
    init();
    return 0;
}
