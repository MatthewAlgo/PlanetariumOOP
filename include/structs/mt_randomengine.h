#pragma once
#include <random>
#include <cmath>

#define M_PI 3.14159265358979323846

int Mersenne_Twister_Generator(const int minvalue, const int maxvalue);
std::pair<double, double> randomPositionInCircle(const double Cx, const double Cy, const double R);
std::pair<double, double> randomPositionInRect(const double Px, const double Py, const double Qx, const double Qy);

