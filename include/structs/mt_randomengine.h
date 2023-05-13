#pragma once
#include <random>
#include <cmath>
#include "constants.h"

class RandomEngine {
    public:
    static std::pair<double, double> randomPositionInCircle(const double Cx, const double Cy, const double R);
    static std::pair<double, double> randomPositionInRect(const double Px, const double Py, const double Qx, const double Qy);
    RandomEngine() = delete;
    ~RandomEngine() = delete;
};
