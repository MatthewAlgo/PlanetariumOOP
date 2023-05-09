#pragma once
#include <random>
#include <cmath>

#define P_PI 3.14159265358979323846

std::pair<double, double> randomPositionInCircle(const double Cx, const double Cy, const double R);
std::pair<double, double> randomPositionInRect(const double Px, const double Py, const double Qx, const double Qy);

