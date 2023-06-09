#include "structs/mt_randomengine.h"

// Random position delimited by the circle with center Cx Cy and radius R
std::pair<double, double> RandomEngine::randomPositionInCircle(const double Cx, const double Cy, const double R) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double r = R * std::sqrt(dis(gen));
    double theta = 2.0 * Constants::P_PI * dis(gen);

    double x = Cx + r * std::cos(theta);
    double y = Cy + r * std::sin(theta);

    return std::make_pair<>(x, y);
}

// random position delimited by the square with upper left Px Py and lower right Qx Qy
std::pair<double, double> RandomEngine::randomPositionInRect(const double Px, const double Py, const double Qx, const double Qy){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> disX(Px, Qx);
    static std::uniform_real_distribution<> disY(Py, Qy);

    double x = disX(gen);
    double y = disY(gen);

    return std::make_pair<>(x, y);
}