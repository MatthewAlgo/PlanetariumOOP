#pragma once

#include "moon.h"

class MoonFactory {
public:
    static Moon createSmallMoon(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Moon createNormalMoon(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Moon createLargeMoon(const std::string& name, const std::pair<double, double>& position, double sRad);
};