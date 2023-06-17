#pragma once

#include "star.h"

class StarFactory {
public:
    static Star createSmallStar(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Star createNormalStar(const std::string& name, const std::pair<double, double>& position, double sRad);
    static Star createLargeStar(const std::string& name, const std::pair<double, double>& position, double sRad);
};