#include "planetfactory.h"
#include "planet.h"
#include "constants.h"

Planet PlanetFactory::createSmallPlanet(const std::string& name, const std::pair<double, double>& position, double sRad){
    Planet planet(name, Constants::STARMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad);
    return planet;
}

Planet PlanetFactory::createNormalPlanet(const std::string& name, const std::pair<double, double>& position, double sRad){
    Planet planet(name, Constants::STARMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad + 10);
    return planet;
}


Planet PlanetFactory::createLargePlanet(const std::string& name, const std::pair<double, double>& position, double sRad){
    Planet planet(name, Constants::STARMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad + 20);
    return planet;
}
