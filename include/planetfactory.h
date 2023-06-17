#pragma once

#include "planet.h"

class PlanetFactory {
public:
    static Planet createSmallPlanet(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Planet createNormalPlanet(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Planet createLargePlanet(const std::string& name, const std::pair<double, double>& position, double sRad);
};