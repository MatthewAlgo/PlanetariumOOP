#include "moonfactory.h"
#include "moon.h"
#include "constants.h"

Moon MoonFactory::createSmallMoon(const std::string& name, const std::pair<double, double>& position, double sRad){
    Moon moon(name, Constants::MOONMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad);
    return moon;
}

Moon MoonFactory::createNormalMoon(const std::string& name, const std::pair<double, double>& position, double sRad){
    Moon moon(name, Constants::MOONMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad + 10);
    return moon;
}


Moon MoonFactory::createLargeMoon(const std::string& name, const std::pair<double, double>& position, double sRad){
    Moon moon(name, Constants::MOONMASS_MASSIVE, 2, 1, 1, position.first, position.second, sRad + 20);
    return moon;
}
