#ifndef OOP_SOLARSYSTEM_H
#define OOP_SOLARSYSTEM_H

#include "planet.h"
#include "star.h"
#include "moon.h"

#include <memory>
#include <ostream>

template <typename T> requires (!std::convertible_to<T, std::string>)
std::ostream& operator<<(std::ostream& os, const T& obj) {
    os << "[";
    for(const auto& elem : obj)
        os << elem << " ";
    os << "]\n";
    return os;
}


class SolarSystem {
public:
    friend std::ostream &operator<<(std::ostream &os, const SolarSystem &solarSystem);

    SolarSystem(const std::vector<Planet> &planets, const std::shared_ptr<Star> &mainStar,
                int asteroidBelts, int ageSinceStarFormation);
    SolarSystem();

public:
    [[nodiscard]] const std::vector<Planet> &getPlanets() const;

    void setPlanets(const std::vector<Planet> &planets);

    [[nodiscard]] const std::shared_ptr<Star> &getMainStar() const;

    void setMainStar(const std::shared_ptr<Star> &mainStar);

    int getAsteroidBelts() const;

    void setAsteroidBelts(int asteroidBelts);

    int getAgeSinceStarFormation() const;

    void setAgeSinceStarFormation(int ageSinceStarFormation);

    bool operator==(const SolarSystem &rhs) const;

    bool operator!=(const SolarSystem &rhs) const;

private:
    std::vector<Planet> planets;
    std::shared_ptr<Star> mainStar;
    int asteroidBelts;
    int ageSinceStarFormation;
    friend class SolarSystemBuilder;
};


class SolarSystemBuilder {
private:
    SolarSystem ssystem;
public:
    SolarSystemBuilder()  = default;
    SolarSystemBuilder& noAsteroidBelts(int nr);
    SolarSystemBuilder& ageOfSSystem(int age);
    SolarSystemBuilder& addPlanet(Planet planet);
    SolarSystemBuilder& setMainStar(Star mStar);
    SolarSystem build();

};

#endif
