#include "starfactory.h"
#include "star.h"
#include "constants.h"

Star StarFactory::createSmallStar(const std::string& name, const std::pair<double, double>& position, double sRad){
    Star star(name, Constants::STARMASS_MASSIVE, 1, 1, 1, position.first, position.second, sRad);
    return star;
}

Star StarFactory::createNormalStar(const std::string& name, const std::pair<double, double>& position, double sRad){
    Star star(name, Constants::STARMASS_MASSIVE, 1, 1, 1, position.first, position.second, sRad + 10);
    return star;
}


Star StarFactory::createLargeStar(const std::string& name, const std::pair<double, double>& position, double sRad){
    Star star(name, Constants::STARMASS_MASSIVE, 1, 1, 1, position.first, position.second, sRad + 20);
    return star;
}
